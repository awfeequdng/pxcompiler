#include "llvm/Support/raw_ostream.h"

void genir();
int lexer_main();

int main() {
    llvm::errs() << "hello llvm!";

    genir();

    lexer_main();

    return 0;
}