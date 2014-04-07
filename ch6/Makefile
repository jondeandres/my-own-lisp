TARGET=../bin
SHARED=../shared

default:
	mkdir -p ${TARGET}
	gcc parsing.c ${SHARED}/mpc.c -I ${SHARED}/ -ledit -lm -o ${TARGET}/parsing

clean:
	rm -rf ${TARGET}/parsing
