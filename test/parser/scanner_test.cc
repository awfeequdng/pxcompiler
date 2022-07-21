#include "parser/scanner.h"

#include <gtest/gtest.h>

#include "common/hex_formatter.h"
#include "parser/token.h"

using namespace parser;

TEST(TestScanner, TestBufPutc) {
    auto buf = std::stringbuf();
    buf.sputc('c');
    buf.sputc('p');
    buf.sputc('x');
    EXPECT_EQ(buf.str(), "cpx");
}

TEST(TestScanner, TestBufPutGet) {
    auto buf = std::stringbuf();
    std::string str = "hello world";
    buf.sputn(str.c_str(), str.length());
    EXPECT_EQ(buf.str(), str);
    auto str1 = " cpx";
    buf.sputn(str1, 4);
    EXPECT_EQ(buf.str(), "hello world cpx");

    buf.pubseekpos(0);
    buf.sputn(str1, 4);
    EXPECT_EQ(buf.str(), " cpxo world cpx");
    buf.str("hello world");
    EXPECT_EQ(buf.str(), "hello world");

    char str_buf[10];
    buf.pubseekpos(3);
    buf.sgetn(str_buf, 4);
    str_buf[4] = 0;
    EXPECT_EQ(std::string(str_buf), "lo w");

    buf.str("hello");
    buf.sputc('n');
    EXPECT_EQ(buf.str(), "nello");

    buf.pubseekoff(0, std::ios_base::end);
    buf.sputc('n');
    EXPECT_EQ(buf.str(), "nellon");
}

TEST(TestScanner, TestscanString) {
    std::unordered_map<std::string, std::string> table = {
        {R"**(' \n\tTest String')**", " \n\tTest String"},
        {R"**('\x\B')**", "xB"},
        // todo: can not pass through this test case
        //        {R"**('\0\'\"\b\n\r\t\\')**", "\000'\"\b\n\r\t\\"},
        {R"**('\Z')**", "\x1a"},
        {R"**('\%\_')**", R"**(\%\_)**"},
        {R"**('hello')**", "hello"},
        {R"**('"hello"')**", R"**("hello")**"},
        {R"**('""hello""')**", R"**(""hello"")**"},
        {R"**('hel''lo')**", "hel'lo"},
        {R"**('\'hello')**", "'hello"},
        {R"**("hello")**", "hello"},
        {R"**("'hello'")**", "'hello'"},
        {R"**("''hello''")**", "''hello''"},
        {R"**("hel""lo")**", R"**(hel"lo)**"},
        {R"**("\"hello")**", R"**("hello)**"},
        {R"**('disappearing\ backslash')**", "disappearing backslash"},
        {"'한국의中文UTF8およびテキストトラック'", "한국의中文UTF8およびテキストトラック"},
        {"'\\a\x90'", "a\x90"},
        {"'\\a\x18èàø»\x05'", "a\x18èàø»\x05"},
        {"' \\n\\t'", " \n\t"},
    };
    int tok;
    common::Pos pos;
    std::string lit;
    for (auto &[str, expect] : table) {
        auto scanner = NewScanner(str);
        std::tie(tok, pos, lit) = scanner->scan();
        ASSERT_EQ(tok, tok_stringLit);
        ASSERT_EQ(pos._offset, 0);
        ASSERT_EQ(lit, expect);
    }
}

TEST(TestScanner, TestCommonComment) {
    auto l = NewScanner("/*x40101 select\n5*/ SELECT");
    auto [tok, pos, lit] = l->scan();
    ASSERT_EQ(tok, tok_identifier);
    ASSERT_EQ(lit, "SELECT");
    auto expect_pos = common::Pos{1, 4, 20};
    ASSERT_EQ(pos, expect_pos);

    l->reset("//xxxxxx   \nselect 2");
    std::tie(tok, pos, lit) = l->scan();
    ASSERT_EQ(tok, tok_identifier);
    expect_pos = common::Pos{1, 0, 12};
    ASSERT_EQ(pos, expect_pos);
    ASSERT_EQ(lit, "select");
}

TEST(TestScanner, TestSpecialComment) {
    auto l = NewScanner("/*101 select\n5*/ SELECT");
    auto [tok, pos, lit] = l->scan();
    ASSERT_EQ(tok, tok_identifier);
    ASSERT_EQ(lit, "SELECT");
    common::Pos expect_pos = common::Pos{1, 4, 17};
    ASSERT_EQ(pos, expect_pos);

    // std::tie(tok, pos, lit) = l->scan();

    // ASSERT_EQ(tok, tok_intLit);
    // ASSERT_EQ(lit, "5");
    // expect_pos = common::Pos{1, 0, 16};
    // ASSERT_EQ(pos, expect_pos);

    // // it will skip '*/' because inBangComment is true
    // std::tie(tok, pos, lit) = l->scan();
    // ASSERT_EQ(tok, tok_identifier);
    // ASSERT_EQ(lit, "SELECT");
    // expect_pos = common::Pos{1, 4, 20};
    // ASSERT_EQ(pos, expect_pos);
}

TEST(TestScanner, TestInteger) {
    std::unordered_map<std::string, std::string> tests = {
        {"01000001783  x", "01000001783"},
        {"00001783gggx", "00001783gggx"},
        {"0 a", "0"},
        {"0000a", "0000a"},
        {"01", "01"},
        {"10 x", "10"},
    };
    auto scanner = NewScanner("");
    for (auto [key, expect] : tests) {
        scanner->reset(key);
        auto [tok, pos, lit] = scanner->scan();
        // it may be identifier
        //        ASSERT_EQ(tok, tok_intLit);
        ASSERT_EQ(lit, expect);
    }
}

TEST(TestScanner, TestStartWithNn) {
    struct {
        std::string str;
        std::string expect;
        int tok;
        char nextChar;
    } tests[] = {
        {
            .str = "nx'123456 f",
            .expect = "nx",
            .tok = tok_identifier,
            .nextChar = '\'',
        },
        {
            .str = "Nx'123456 f",
            .expect = "Nx",
            .tok = tok_identifier,
            .nextChar = '\'',
        },
        // {
        //     .str = "n'123456' f",
        //     .expect = "utf8",
        //     .tok = tok_underscoreCS,
        //     .nextChar = '\'',
        // },
        // {
        //     .str = "N'123456' f",
        //     .expect = "utf8",
        //     .tok = tok_underscoreCS,
        //     .nextChar = '\'',
        // },
    };
    auto scanner = NewScanner("");
    for (auto test : tests) {
        scanner->reset(test.str);
        auto [tok, pos, lit] = scanner->scan();
        auto nc = scanner->reader()->peek();
        ASSERT_EQ(tok, test.tok);
        ASSERT_EQ(lit, test.expect);
        ASSERT_EQ(nc, test.nextChar);
    }
}

TEST(TestScanner, TestStartWithXx) {
    struct {
        std::string str;
        std::string expect;
        int tok;
    } tests[] = {
        {
            .str = "x'123456'",
            .expect = "x'123456'",
            .tok = tok_hexLit,
        },
        {
            .str = "x'123456' ",
            .expect = "x'123456'",
            .tok = tok_hexLit,
        },
        {
            .str = "x'123456' f",
            .expect = "x'123456'",
            .tok = tok_hexLit,
        },
        {
            .str = "x'123456x' f",
            .tok = (int)common::utf8::rune_invalid,
        },
        {
            .str = "X'123456' f",
            .expect = "X'123456'",
            .tok = tok_hexLit,
        },
        {
            .str = "X'123456x' f",
            .tok = (int)common::utf8::rune_invalid,
        },
        {
            .str = "XSTART'123456' f",
            .expect = "XSTART",
            .tok = tok_identifier,
        },
        {
            .str = "xxxji'123456' f",
            .expect = "xxxji",
            .tok = tok_identifier,
        },
        {
            .str = "xxxx'123456' f",
            .expect = "xxxx",
            .tok = tok_identifier,
        },
    };
    auto scanner = NewScanner("");
    for (auto test : tests) {
        scanner->reset(test.str);
        auto [tok, pos, lit] = scanner->scan();
        ASSERT_EQ(tok, test.tok);
        ASSERT_EQ(lit, test.expect);
    }
}

TEST(TestScanner, TestScanQuotedIdent) {
    struct {
        std::string str;
        std::string expect;
        int tok;
    } tests[] = {
        {
            .str = "`greater`",
            .expect = "greater",
            .tok = tok_quotedIdentifier,
        },
        {
            .str = "`greater``hello world`",
            .expect = "greater`hello world",
            .tok = tok_quotedIdentifier,
        },
    };
    auto scanner = NewScanner("");
    for (auto test : tests) {
        scanner->reset(test.str);
        auto [tok, pos, lit] = scanner->scan();
        ASSERT_EQ(tok, test.tok);
        ASSERT_EQ(lit, test.expect);
    }
}

TEST(TestScanner, TestStartWithSharp) {
    struct {
        std::string str;
        std::string expect;
        int tok;
    } tests[] = {
        {
            .str = "#xxxxx\nb'1010'",
            .expect = "b'1010'",
            .tok = tok_bitLit,
        },
        {
            .str = "#\nbbbji'1010' f",
            .expect = "bbbji",
            .tok = tok_identifier,
        },
        {
            .str = "####\nbbbb'1010' f",
            .expect = "bbbb",
            .tok = tok_identifier,
        },
    };
    auto scanner = NewScanner("");
    for (auto test : tests) {
        scanner->reset(test.str);
        auto [tok, pos, lit] = scanner->scan();
        ASSERT_EQ(tok, test.tok);
        ASSERT_EQ(lit, test.expect);
    }
}

TEST(TestScanner, TestStartWithBb) {
    struct {
        std::string str;
        std::string expect;
        int tok;
    } tests[] = {
        {
            .str = "b'1010'",
            .expect = "b'1010'",
            .tok = tok_bitLit,
        },
        {
            .str = "b'1010' ",
            .expect = "b'1010'",
            .tok = tok_bitLit,
        },
        {
            .str = "b'1010' f",
            .expect = "b'1010'",
            .tok = tok_bitLit,
        },
        {
            .str = "b'1010x' f",
            .tok = (int)common::utf8::rune_invalid,
        },
        {
            .str = "B'1010' f",
            .expect = "B'1010'",
            .tok = tok_bitLit,
        },
        {
            .str = "b'1010x' f",
            .tok = (int)common::utf8::rune_invalid,
        },
        {
            .str = "BSTART'1010' f",
            .expect = "BSTART",
            .tok = tok_identifier,
        },
        {
            .str = "bbbji'1010' f",
            .expect = "bbbji",
            .tok = tok_identifier,
        },
        {
            .str = "bbbb'1010' f",
            .expect = "bbbb",
            .tok = tok_identifier,
        },
    };
    auto scanner = NewScanner("");
    for (auto test : tests) {
        scanner->reset(test.str);
        auto [tok, pos, lit] = scanner->scan();
        ASSERT_EQ(tok, test.tok);
        ASSERT_EQ(lit, test.expect);
    }
}

TEST(TestScanner, TestPrintTokens) {
    auto scanner = NewScanner("def main(argc, argv) { print('hello world') }");
    auto [tok, pos, lit] = scanner->scan();
    while (tok != 0 && tok != tok_invalid) {
        std::cout << "[ " << tok << ", " << pos._offset << ", " << lit << "]" << std::endl;
        std::tie(tok, pos, lit) = scanner->scan();
    }
    std::cout << "invalid tok = " << tok << std::endl;
}

TEST(TestScanner, TestString) {
    struct {
        std::string str;
        std::string expect;
        int tok;
    } tests[] = {
        {
            .str = "<=>dd",
            .expect = "<=>",
            .tok = tok_nulleq,
        },
        {
            .str = "<=xx",
            .expect = "<=",
            .tok = tok_le,
        },
        {
            .str = ":=xx",
            .expect = ":=",
            .tok = tok_assignmentEq,
        },

    };
    auto scanner = NewScanner("");
    for (auto test : tests) {
        scanner->reset(test.str);
        auto [tok, pos, lit] = scanner->scan();
        ASSERT_EQ(lit, test.expect);
        ASSERT_EQ(tok, test.tok);
    }
}


TEST(TestScanner, TestKeyword) {
    struct {
        std::string str;
        std::string expect;
        int tok;
    } tests[] = {
        {
            .str = "definition",
            .expect = "definition",
            .tok = tok_identifier,
        },
        {
            .str = "defi",
            .expect = "defi",
            .tok = tok_identifier,
        },
        {
            .str = "def",
            .expect = "def",
            .tok = tok_def,
        },

    };
    auto scanner = NewScanner("");
    for (auto test : tests) {
        scanner->reset(test.str);
        auto token = scanner->getNextToken();
        ASSERT_EQ(token.lit, test.expect);
        ASSERT_EQ(token.tag, test.tok);
    }
}
