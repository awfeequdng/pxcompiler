#include "common/utf8/reader.h"

#include <gtest/gtest.h>

using namespace common::utf8;

TEST(Utf8ReaderTest, test_read) {
    std::string str = "中国x";
    reader_t reader(str);

    auto rune = reader.next();
    EXPECT_FALSE(reader.eof());

    EXPECT_EQ((std::string)rune, "中");
    rune = reader.next();

    EXPECT_FALSE(reader.eof());
    EXPECT_EQ((std::string)rune, "国");

    EXPECT_FALSE(reader.eof());
    rune = reader.next();

    EXPECT_EQ((std::string)rune, "x");
    EXPECT_TRUE(reader.eof());
}

TEST(Utf8ReaderTest, test_whitespace) {
    std::string str = "  \t中国x";
    reader_t reader(str);
    // get first whitespace
    auto rune = reader.next();
    EXPECT_EQ(rune, ' ');

    // get second whitespace
    rune = reader.next();
    EXPECT_EQ(rune, ' ');

    // get third \t
    rune = reader.next();
    EXPECT_EQ(rune, '\t');

    rune = reader.next();
    EXPECT_FALSE(reader.eof());

    EXPECT_EQ((std::string)rune, "中");
    rune = reader.next();

    EXPECT_FALSE(reader.eof());
    EXPECT_EQ((std::string)rune, "国");

    EXPECT_FALSE(reader.eof());
    rune = reader.next();

    EXPECT_EQ((std::string)rune, "x");
    EXPECT_TRUE(reader.eof());
}

TEST(Utf8ReaderTest, test_pos) {
    std::string str = "中国人";
    reader_t reader(str);

    EXPECT_EQ(reader.length(), 9);

    auto rune = reader.next();
    EXPECT_EQ((std::string)rune, "中");

    auto pos = reader.pos();
    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 3);
    EXPECT_EQ(pos._offset, 3);

    rune = reader.next();
    EXPECT_EQ((std::string)rune, "国");
    pos = reader.pos();

    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 6);
    EXPECT_EQ(pos._offset, 6);

    rune = reader.next();
    EXPECT_EQ((std::string)rune, "人");
    EXPECT_TRUE(reader.eof());
    pos = reader.pos();

    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 9);
    EXPECT_EQ(pos._offset, 9);
}

TEST(Utf8ReaderTest, test_prev) {
    std::string str = "中国人";
    reader_t reader(str);

    EXPECT_EQ(reader.length(), 9);

    auto rune = reader.next();
    EXPECT_EQ((std::string)rune, "中");

    auto pos = reader.pos();
    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 3);
    EXPECT_EQ(pos._offset, 3);

    rune = reader.next();
    EXPECT_EQ((std::string)rune, "国");
    pos = reader.pos();

    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 6);
    EXPECT_EQ(pos._offset, 6);

    rune = reader.next();
    EXPECT_EQ((std::string)rune, "人");
    EXPECT_TRUE(reader.eof());
    pos = reader.pos();

    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 9);
    EXPECT_EQ(pos._offset, 9);

    // get previous rune and set pos to previous position
    rune = reader.prev();
    pos = reader.pos();
    EXPECT_EQ((std::string)rune, "人");
    EXPECT_FALSE(reader.eof());
    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 6);
    EXPECT_EQ(pos._offset, 6);
}

TEST(Utf8ReaderTest, test_set_index) {
    std::string str = "中国x";
    reader_t reader(str);

    auto rune = reader.next();
    EXPECT_FALSE(reader.eof());

    EXPECT_EQ((std::string)rune, "中");
    rune = reader.next();

    EXPECT_FALSE(reader.eof());
    EXPECT_EQ((std::string)rune, "国");

    EXPECT_FALSE(reader.eof());
    rune = reader.next();

    EXPECT_EQ((std::string)rune, "x");
    EXPECT_TRUE(reader.eof());

    EXPECT_FALSE(reader.seek(2));
    EXPECT_TRUE(reader.eof());

    auto pos = reader.pos();

    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 7);
    EXPECT_EQ(pos._offset, 7);

    // it will seek failed
    EXPECT_FALSE(reader.seek(10));
    EXPECT_TRUE(reader.seek(3));
    pos = reader.pos();
    rune = reader.curr();

    EXPECT_EQ(pos._line, 0);
    EXPECT_EQ(pos._col, 3);
    EXPECT_EQ(pos._offset, 3);
    EXPECT_EQ((std::string)rune, "国");
}

TEST(Utf8ReaderTest, test_make_slice) {
    std::string str = "中国人";
    reader_t reader(str);

    EXPECT_EQ(reader.make_slice(0, 9), "中国人");
    EXPECT_EQ(reader.make_slice(3, 6), "国人");
    EXPECT_EQ(reader.make_slice(3, 3), "国");
    EXPECT_EQ(reader.make_slice(6, 3), "人");
}
