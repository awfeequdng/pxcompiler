#include "llvm/ADT/SmallString.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"

#include "common/error.h"
#include "common/nonnull.h"
#include "common/arena.h"
#include "parser/flex_bison/parse.h"
#include "ast/ast.h"

#include "vm/run_ast.h"

#include <cstdlib>

static auto Main(llvm::StringRef default_prelude_file, int argc, char **argv)
    -> common::ErrorOr<common::Success> {
    llvm::setBugReportMsg(
        "Please report issues to "
        "https://github.com/awfeequdng/pxcompiler/issues and include the "
        "crash backtrace.\n"
    );
    llvm::InitLLVM init_llvm(argc, argv);
    llvm::errs().tie(&llvm::outs());
    llvm::cl::opt<std::string> input_file_name(llvm::cl::Positional, llvm::cl::desc("<input file>"), llvm::cl::Required);
    llvm::cl::opt<bool> parser_debug("parser_debug", llvm::cl::desc("Enable debug output from the parser"));
    llvm::cl::opt<std::string> trace_file_name(
        "trace_file",
        llvm::cl::desc("Output file for tracing; set to `-` to output to stdout.")
    );
    // Find the path of the executable if possible and use that as a relative root
    llvm::cl::opt<std::string> prelude_file_name("prelude", llvm::cl::desc("<prelude file>"),
                                            llvm::cl::init(default_prelude_file.str()));
    llvm::cl::ParseCommandLineOptions(argc, argv);

    // Set up a stream for trace output.
    std::unique_ptr<llvm::raw_ostream> scoped_trace_stream;
    std::optional<common::Nonnull<llvm::raw_ostream*>> trace_stream;
    if (!trace_file_name.empty()) {
        if (trace_file_name == "-") {
            trace_stream = &llvm::outs();
        } else {
            std::error_code err;
            scoped_trace_stream = std::make_unique<llvm::raw_fd_ostream>(trace_file_name, err);
            if (err) {
                return common::Error(err.message());
            }
            trace_stream = scoped_trace_stream.get();
        }
    }

    common::Arena arena;
    PXC_ASSIGN_OR_RETURN(ast::AST ast,
                         parser::flex_bison::Parse(&arena,
                                                   input_file_name,
                                                   parser_debug));
    PXC_ASSIGN_OR_RETURN(int return_code,
                         vm::RunAst(&arena, ast, trace_stream));
    llvm::outs() << "build ast return code: " << return_code << "\n";

    // When there's dedicated trace file, print the return code to it too.
    if (scoped_trace_stream) {
        **trace_stream << "build ast return code: " << return_code << "\n";
    }

    return common::Success();
}

auto pxc_main(int argc, char **argv) -> int {
    llvm::SmallString<256> path;
    if (std::error_code err = llvm::sys::fs::current_path(path)) {
        llvm::errs() << "Failed to get working directory: " << err.message();
        return 1;
    }
    llvm::sys::path::append(path, "pxc/data");

    char *build_working_dir = getenv("BUILD_WORKING_DIRECTORY");
    if (build_working_dir != nullptr) {
        if (std::error_code err =
            llvm::sys::fs::set_current_path(build_working_dir)) {
            llvm::errs() << "Failed to set working directory: " << err.message();
            return 1;
        }
    }

    if (auto result = Main(path, argc, argv); !result.ok()) {
        llvm::errs() << result.error().message() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}