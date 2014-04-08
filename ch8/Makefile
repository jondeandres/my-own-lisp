TARGET=../bin
SHARED=../shared

default:
	mkdir -p ${TARGET}
	gcc error_handling.c ${SHARED}/mpc.c -I ${SHARED}/ -ledit -lm -o ${TARGET}/error_handling

clean:
	rm -rf ${TARGET}/error_handling
