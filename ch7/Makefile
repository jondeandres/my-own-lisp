TARGET=../bin
SHARED=../shared

default:
	mkdir -p ${TARGET}
	gcc evaluation.c ${SHARED}/mpc.c -I ${SHARED}/ -ledit -lm -o ${TARGET}/evaluation

clean:
	rm -rf ${TARGET}/evaluation
