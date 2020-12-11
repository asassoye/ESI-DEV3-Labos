.PHONY: all clean interro1 tree docs

all:
	mkdir -p build/Release; cd build/Release; cmake -DCMAKE_BUILD_TYPE=Release ../../; make

debug:
	mkdir -p build/Debug; cd build/Debug; cmake -DCMAKE_BUILD_TYPE=Debug ../../; make

clean:
	rm -rf ./build ./*/build ./docs/ ./*/docs

interro1: clean
	mkdir -p ./i1/build; cd ./i1/build; gcc -o interro1 -std=c11 -Wall -pedantic -O3 -lm ../src/main.c ../src/primestat.c ../src/statsample.c ../resources/td04.c ../resources/PrimeFactor.c ../resources/PrimeFactorization.c ../resources/mathesi.c

tree:
	tree --dirsfirst -I 'build|resources' .

docs:
	doxygen ./doxygen