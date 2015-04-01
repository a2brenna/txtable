INCLUDE_DIR=$(shell echo ~)/local/include
LIBRARY_DIR=$(shell echo ~)/local/lib
DESDTIR=/
PREFIX=/usr

CXX=clang++
CXXFLAGS=-L${LIBRARY_DIR} -I${INCLUDE_DIR} -march=native -O2 -g -std=c++11 -fPIC -Wall -Wextra

all: libtxtable.so libtxtable.a test

install: libtxtable.so libtxtable.a txtable.h

test: src/test.cc src/txtable.h txtable.o
	${CXX} ${CXXFLAGS} -o test src/test.cc txtable.o

libtxtable.so: txtable.o
	${CXX} ${CXXFLAGS} -shared -Wl,-soname,libtxtable.so -o libtxtable.so txtable.o

libtxtable.a: txtable.o
	ar rcs libtxtable.a txtable.o

txtable.o: src/txtable.h src/txtable.cc
	${CXX} ${CXXFLAGS} -c src/txtable.cc -o txtable.o

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.so
	rm -f test
