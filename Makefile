FLEXFILE=parser.l
BISONFILE=parser.y
all: clean flex bison brainheck
brainheck: clean flex bison comp

comp:
	g++ -g scanner.cpp parser.cpp -o interpreter AST.cpp
flex:
	flex -o scanner.cpp ${FLEXFILE}
bison:
	bison -v -Wconflicts-sr -Wconflicts-rr -o parser.cpp --defines=parser.h ${BISONFILE}
clean:
	rm -f parser.h parser.cpp scanner.cpp parser
