.PHONY: all clean interro1 tree docs examen


CPUCOUNT=$(shell grep -c "^processor" /proc/cpuinfo)

all:
	mkdir -p build/Release; cd build/Release; cmake -DCMAKE_BUILD_TYPE=Release -j${CPUCOUNT} ../../; make -j${CPUCOUNT}

test: debug
	cd build/Debug; ctest ../..

debug:
	mkdir -p build/Debug; cd build/Debug; cmake -DCMAKE_BUILD_TYPE=Debug -j${CPUCOUNT} ../../; make -j${CPUCOUNT}

clean:
	rm -rf ./build ./*/build ./docs/ ./*/docs

interro1: clean
	mkdir -p ./i1/build/Release; cd ./i1/build/Release; gcc -o interro1 -std=c11 -Wall -pedantic -O3 -lm ../src/main.c ../src/primestat.c ../src/statsample.c ../resources/td04.c ../resources/PrimeFactor.c ../resources/PrimeFactorization.c ../resources/mathesi.c

examen: clean
	mkdir -p ./i2/build/Release; cd ./i2/build/Release; g++ -o examen -std=c++17 -Wall -pedantic -O3 -lm ../../src/main.cpp ../../resources/data.cpp

tree:
	tree --dirsfirst -I 'build|resources|docs' .

docs:
	doxygen ./doxygen

