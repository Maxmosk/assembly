.PHONY: all clean


all: hello

hello: hello.o
	ld -o hello hello.o
	chmod u+x hello

hello.o: hello.asm
	nasm -felf64 hello.asm -o hello.o

clean:
	rm -rf *.o hello

