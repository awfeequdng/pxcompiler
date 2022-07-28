%{
   #include <iostream>

%}

/* 在flex文件中添加%option noyywrap，加入该语句之后，g++指令就不需要添加-lfl参数 */
%option noyywrap reentrant

DIGIT   [0-9]
ID      [a-z][a-z0-9]*

%%

{DIGIT}+ {
    int i = atoi(yytext);
    std::cout << "An interger: " << i << std::endl;
    printf("interger: %d\n", i);
}

{DIGIT}+"."{DIGIT}* {
    float f = atof(yytext);
    //std::cout << "An float: " << f << std::endl;
    printf("float: %f\n", f);
}

if|then|begin|end {
    //std::cout << "A keyword: " << yytext << std::endl;
    printf("keyword: %s\n", yytext);
}

{ID} {
    //std::cout << "identifier: " << yytext << std::endl;
    printf("identifier: %s\n", yytext);
}

"+"|"-"|"*"|"/" {
    //std::cout << "An operator: " << yytext << std::endl;
    printf("operator: %s\n", yytext);
}

"{"[\^{}\n]*"}" /*eat up one-line comments */

[ \t\n]+ /* eat up whitespace */

. {
    //std::cout << "unrecognized character: " << yytext << std::endl;
    printf("unrecognized character: %s\n", yytext);
}

%%

int main(int argc, char** argv) {
    yyscant_t scanner;
    yylex_init(&scanner);
    ++argv, --argc;

    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }

    yylex();
    yylex_destory(scanner);
    return 0;
}
