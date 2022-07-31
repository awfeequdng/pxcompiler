
#include "common/error_builders.h"

#include <gtest/gtest.h>

#include "common/source_location.h"

namespace pxcompiler::Testing {
namespace {

TEST(ErrorBuildersTest, CompilationError) {
  Error err = CompilationError(SourceLocation("x", 1)) << "test";
  EXPECT_EQ(err.message(), "COMPILATION ERROR: x:1: test");
}

TEST(ErrorBuildersTest, ProgramError) {
  Error err = ProgramError(SourceLocation("x", 1)) << "test";
  EXPECT_EQ(err.message(), "PROGRAM ERROR: x:1: test");
}

TEST(ErrorBuildersTest, RuntimeError) {
  Error err = RuntimeError(SourceLocation("x", 1)) << "test";
  EXPECT_EQ(err.message(), "RUNTIME ERROR: x:1: test");
}

}  // namespace
}  // namespace Carbon::Testing
