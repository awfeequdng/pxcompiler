
#include "common/check.h"

#include <gtest/gtest.h>

namespace pxc::Testing {
namespace {

TEST(CheckTest, CheckTrue) { PXC_CHECK(true); }

TEST(CheckTest, CheckFalse) {
  // TODO: figure out why we can't use \\d+ instead of .+ in these patterns.
  ASSERT_DEATH({ PXC_CHECK(false); },
               "Stack trace:\n"
               ".+\n"
               "CHECK failure at common/check_test.cpp:.+: false\n");
}

TEST(CheckTest, CheckTrueCallbackNotUsed) {
  bool called = false;
  auto callback = [&]() {
    called = true;
    return "called";
  };
  PXC_CHECK(true) << callback();
  EXPECT_FALSE(called);
}

TEST(CheckTest, CheckFalseMessage) {
  ASSERT_DEATH({ PXC_CHECK(false) << "msg"; },
               "CHECK failure at common/check_test.cpp:.+: false: msg\n");
}

TEST(CheckTest, CheckOutputForms) {
  const char msg[] = "msg";
  std::string str = "str";
  int i = 1;
  PXC_CHECK(true) << msg << str << i << 0;
}

TEST(CheckTest, Fatal) {
  ASSERT_DEATH({ PXC_FATAL() << "msg"; },
               "FATAL failure at common/check_test.cpp:.+: msg\n");
}

auto FatalNoReturnRequired() -> int { PXC_FATAL() << "msg"; }

TEST(ErrorTest, FatalNoReturnRequired) {
  ASSERT_DEATH({ FatalNoReturnRequired(); },
               "FATAL failure at common/check_test.cpp:.+: msg\n");
}

}  // namespace
}  // namespace pxc::Testing
