CC=gcc
OUT=build/libarena_allocator.so
LIBSRCS=\
	src/arena_alloc.c
TESTOUT=example/example
TESTSRC=example/example.c
default:
	${CC} -o ${OUT} ${LIBSRCS} -fpic --shared
test: default
	${CC} -o ${TESTOUT} ${TESTSRC} -I src -larena_allocator -L build 
	./example/test
clean:
	rm -rf *.o *.d ${OUT} *.out *.so ${TESTOUT}