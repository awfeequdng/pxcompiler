#include "llvm/Support/raw_ostream.h"

void genir();
int lexer_main();
auto pxc_main(int argc, char **argv) -> int;

int main(int argc, char **argv) {
    llvm::errs() << "hello llvm!";

    genir();

    // lexer_main();

    return pxc_main(argc, argv);
}