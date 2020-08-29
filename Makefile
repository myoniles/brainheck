FLEXFILE=src/parser.l
BISONFILE=src/parser.y
all: clean flex bison brainheck
brainheck: clean flex bison comp

comp:
	g++ -g lib/scanner.cpp lib/parser.cpp -o bin/interpreter src/AST.cpp
flex:
	flex -o lib/scanner.cpp ${FLEXFILE}
bison:
	bison -v -Wconflicts-sr -Wconflicts-rr -o lib/parser.cpp --defines=lib/parser.h ${BISONFILE}
clean:
	rm -f lib/parser.h lib/parser.cpp scanner.cpp interpreter
