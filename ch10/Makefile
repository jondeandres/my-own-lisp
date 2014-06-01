TARGET=../bin
SHARED=../shared
# FLAGS=-w -std=c99 -g
FLAGS= -std=c99 -g

default:
	mkdir -p ${TARGET}
	gcc *.c ${FLAGS}  ${SHARED}/mpc.c -I ${SHARED}/ -ledit -lm -o ${TARGET}/q_expressions

clean:
	rm -rf ${TARGET}/q_expressions
