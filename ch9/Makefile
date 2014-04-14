TARGET=../bin
SHARED=../shared
FLAGS=-w -std=c99 -g

default:
	mkdir -p ${TARGET}
	gcc *.c ${FLAGS}  ${SHARED}/mpc.c -I ${SHARED}/ -ledit -lm -o ${TARGET}/s_expressions

clean:
	rm -rf ${TARGET}/s_expressions
