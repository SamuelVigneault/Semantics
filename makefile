CFLAGS=-std=c++11
decafs: lex.yy.o y.tab.o decafs.o parsetree.o parse.o semantics.o 
	g++ -o decafs lex.yy.o y.tab.o decafs.o parsetree.o parse.o semantics.o

semantics.o: semantics.cc semantics.h
	g++ $(CFLAGS) -c semantics.cc

decafs.o: decafs.cc
	g++ $(CFLAGS) -c decafs.cc

parse.o: parse.cc
	g++ $(CFLAGS) -c parse.cc

parsetree.o: parsetree.cc semantics.h
	g++ $(CFLAGS) -c parsetree.cc

y.tab.o: y.tab.c
	g++ $(CFLAGS) -c y.tab.c

lex.yy.o: lex.yy.c tokentype.h y.tab.h
	g++ $(CFLAGS) -c lex.yy.c

y.tab.h: decaf.y parsetree.h
	bison -y -d -t decaf.y # -t supports runtime debug info
#	bison -y -d decaf.y
#OLD:
#	yacc -t -d -v decaf.y # -t supports runtime debug info
#	yacc -d -v decaf.y

y.tab.c: decaf.y parsetree.h
	bison -y -d -t decaf.y # -t supports runtime debug info
#	bison -y -d decaf.y
#OLD:
#	yacc -t -d -v decaf.y # -t supports runtime debug info
#	yacc -d -v decaf.y

lex.yy.c: decaf.lex y.tab.h   # token types will be defined in y.tab.h now.
	flex decaf.lex

clean:
	rm -rf *~ lex.yy.* *.o y.tab.* decaf{p,l,s} a.out y.output
