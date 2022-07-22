

gen:
	~/opt/bison/bin/bison --output=./test/parser.cpp --report=state --defines=./test/parser.h parser.ypp
	flex --outfile=./test/lexer.cpp --header-file=./test/lexer.h lexer.lpp