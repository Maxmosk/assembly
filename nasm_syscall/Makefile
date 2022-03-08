.PHONY: all claen

all: main

main: main.o syscall.o
	ld -e main -o main main.o syscall.o

main.o: main.c syscall.h
	gcc -c -nostdlib -fno-stack-protector main.c

syscall.o: syscall.asm
	nasm -f elf64 syscall.asm


clean:
	rm *.o main

