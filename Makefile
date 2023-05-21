CC=gcc
OUT=arena_allocator
SRCS=src/main.c \
	src/arena_alloc.c
default:
	${CC} -o ${OUT} ${SRCS}

clean:
	rm -rf *.o *.d ${OUT} *.out