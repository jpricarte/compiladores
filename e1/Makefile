all:	main scanner
	gcc lex.yy.o extra.o main.o -o etapa1
	make clean

main:	main.c
	gcc main.c -c
	gcc extra.c -c

scanner: scanner.l
	 flex scanner.l
	 gcc lex.yy.c -c

clean:
	rm *.o

