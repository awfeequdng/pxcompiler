#include "common/utf8/rune.h"

#include <gtest/gtest.h>

TEST(RuneTest, utf8) {
    pxcompiler::utf8::rune_t rune{0x4e2d};
    //    EXPECT_EQ(encode(rune).width, 3);
    //    std::cout << encode(rune).data[0] << std::endl;
    std::string str = (std::string)rune;
    EXPECT_EQ(str, "中");
}

// in the Latin-1 space this is
//	'\t', '\n', '\v', '\f', '\r', ' ', U+0085 (NEL), U+00A0 (NBSP).
// Other definitions of spacing characters are set by category
// Z and property Pattern_White_Space.
TEST(RuneTest, whitespace) {
    pxcompiler::utf8::rune_t rune;
    rune = 0xA0;
    EXPECT_TRUE(rune.is_space());
    rune = 0x85;
    EXPECT_TRUE(rune.is_space());
    rune = '\t';
    EXPECT_TRUE(rune.is_space());
    rune = '\n';
    EXPECT_TRUE(rune.is_space());
    rune = '\v';
    EXPECT_TRUE(rune.is_space());
    rune = '\f';
    EXPECT_TRUE(rune.is_space());
    rune = '\r';
    EXPECT_TRUE(rune.is_space());
    rune = ' ';
    EXPECT_TRUE(rune.is_space());
}