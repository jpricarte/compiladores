all:	main parser scanner
	gcc parser.tab.o lex.yy.o extra.o main.o -o etapa2
	make clean

main:	main.c
	gcc main.c -c
	gcc extra.c -c

parser: parser.y
	bison -d parser.y
	gcc parser.tab.c -c

scanner: scanner.l
	 flex scanner.l
	 gcc lex.yy.c -c

clean:
	rm *.o

