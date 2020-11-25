.PHONY: all clean interro1 tree

all:
	mkdir -p build; cd build; cmake ../; make

clean:
	rm -rf ./build ./*/build ./docs/ ./*/docs

interro1:
	mkdir -p ./i1/build; cd ./i1/build; gcc -o interro1 ../src/main.c

tree:
	tree --dirsfirst -I 'build' .