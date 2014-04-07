TARGET=../bin

default:
	mkdir -p $TARGET
	gcc prompt.c -o ${TARGET}/prompt
	gcc prompt_editline.c -ledit -o ${TARGET}/prompt_editline

clean:
	rm -rf ${TARGET}/prompt ${TARGET}/prompt_editline

