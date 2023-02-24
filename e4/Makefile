ETAPA=etapa4
FLAGS=-Wall -g
COMP=g++ --std=c++20 ${FLAGS}

all: reset parser scanner make_obj
	${COMP} *.o -o ${ETAPA}
	make clean

make_obj: *.c *.cc
	${COMP} *.c *.cc -c

parser: parser.y
	bison -d parser.y

scanner: scanner.l
	 flex scanner.l

reset: clean
	rm -f lex.yy.* parser.tab.* ${ETAPA}

clean:
	rm -f *.o

