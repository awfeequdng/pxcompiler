#include "llvm/Support/Signals.h"
// #include "llvm/Support/inter"
#include <gtest/gtest.h>

TEST(TestSignal, TestInterrupt) {
    // llvm::raw_ostream()
    llvm::sys::RunInterruptHandlers();
}
