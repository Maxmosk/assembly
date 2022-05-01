.PHONY: all clean

# C compiler
CC=gcc
# C compiler 64-bit flags
C64FLAGS=-m64 -fno-pie -no-pie -O0 -g -fno-stack-protector
# Assembler
ASM=nasm
# Assembler 64-bit flags
ASMFLAGS64=-felf64 -g


all: fabs


fabs: main.o fabs.o
	$(CC) $(C64FLAGS) -o fabs fabs.o main.o

main.o: main.c
	$(CC) $(C64FLAGS) -c -o main.o main.c

fabs.o: fabs.asm
	$(ASM) $(ASMFLAGS64) -o fabs.o fabs.asm


clean:
	rm -rf *.o fabs


