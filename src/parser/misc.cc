#include "parser/misc.h"
#include "parser/lexer.h"
#include "parser/scanner.h"
#include "parser/token.h"

namespace parser {
std::shared_ptr<trieNode> ruleTable;

std::shared_ptr<trieNode> getRuleTable() { return ruleTable; }

void initTokenByte(uint8_t c, int tok) {
    if (ruleTable->childs[c] == nullptr) {
        ruleTable->childs[c] = std::make_shared<trieNode>();
    }
    ruleTable->childs[c]->token = tok;
}

void initTokenString(std::string str, int tok) {
    auto node = ruleTable;
    for (unsigned char ch : str) {
        auto id = static_cast<size_t>(ch);
        if (node->childs[id] == nullptr) {
            node->childs[id] = std::make_shared<trieNode>();
        }
        node = node->childs[id];
    }
    node->token = tok;
}

void initTokenFunc(std::string str, trieFunc fn) {
    for (unsigned char ch : str) {
        if (ruleTable->childs[ch] == nullptr) {
            ruleTable->childs[ch] = std::make_shared<trieNode>();
        }
        ruleTable->childs[ch]->fn = fn;
    }
}

__attribute__((constructor)) void init() {
    ruleTable = std::make_shared<trieNode>();
    ruleTable->token = tok_invalid;
    initTokenByte('/', int('/'));
    initTokenByte('+', int('+'));
    initTokenByte('>', int('>'));
    initTokenByte('<', int('<'));
    initTokenByte('(', int('('));
    initTokenByte(')', int(')'));
    initTokenByte('[', int('['));
    initTokenByte(']', int(']'));
    initTokenByte(';', int(';'));
    initTokenByte(',', int(','));
    initTokenByte('&', int('&'));
    initTokenByte('%', int('%'));
    initTokenByte(':', int(':'));
    initTokenByte('|', int('|'));
    initTokenByte('!', int('!'));
    initTokenByte('^', int('^'));
    initTokenByte('~', int('~'));
    initTokenByte('\\', int('\\'));
    initTokenByte('?', tok_paramMarker);
    initTokenByte('=', tok_eq);
    initTokenByte('{', int('{'));
    initTokenByte('}', int('}'));

    initTokenString("||", tok_pipes);
    initTokenString("&&", tok_andand);
    initTokenString("&^", tok_andnot);
    initTokenString(":=", tok_assignmentEq);
    initTokenString("<=>", tok_nulleq);
    initTokenString(">=", tok_ge);
    initTokenString("<=", tok_le);
    initTokenString("!=", tok_neq);
    initTokenString("<>", tok_neqSynonym);
    initTokenString("<<", tok_lsh);
    initTokenString(">>", tok_rsh);
    initTokenString("\\N", tok_null);

    initTokenFunc("@", startWithAt);
    initTokenFunc("/", startWithSlash);
    initTokenFunc("*", startWithStar);
    initTokenFunc("-", startWithDash);
    initTokenFunc("#", startWithSharp);
    initTokenFunc("Xx", startWithXx);
    initTokenFunc("Nn", startWithNn);
    initTokenFunc("Bb", startWithBb);
    initTokenFunc(".", startWithDot);
    initTokenFunc("_$ACDEFGHIJKLMOPQRSTUVWYZacdefghijklmopqrstuvwyz", scanIdentifier);
    initTokenFunc("`", scanQuotedIdent);
    initTokenFunc("0123456789", startWithNumber);
    initTokenFunc("'\"", startString);
}

}  // namespace parser