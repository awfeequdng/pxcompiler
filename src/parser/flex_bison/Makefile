

all: lexer parser

lexer:
	~/opt/flex/bin/flex --outfile=./lexer.cc  --header-file=../../include/parser/flex_bison/lexer.h lexer.lpp

parser:
	~/opt/bison/bin/bison --output=./parser.cc --report=state --defines=../../include/parser/flex_bison/parser.h parser.ypp
	# ~/opt/bison/bin/bison --output=./parser.cc --report=state --defines=../../include/parser/flex_bison/parser.h parser.ypp

test: lexer
	g++ lexer.cc -o lexer

clean:
	rm lexer lexer.cc
