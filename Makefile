.PHONY: all clean interro1 tree

all:
	mkdir -p build; cd build; cmake -DCMAKE_BUILD_TYPE=Release ../; make

debug:
	mkdir -p build; cd build; cmake -DCMAKE_BUILD_TYPE=Debug ../; make

clean:
	rm -rf ./build ./*/build ./docs/ ./*/docs

interro1:
	mkdir -p ./i1/build; cd ./i1/build; gcc -o interro1 -std=c11 -Wall -pedantic -lm ../src/main.c ../src/primestat.c ../src/statsample.c ../../td04/src/td04.c ../../td04/src/PrimeFactor.c ../../td04/src/PrimeFactorization.c ../../td01/src/mathesi.c

tree:
	tree --dirsfirst -I 'build' .
