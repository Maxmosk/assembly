.PHONY: all clean call32bit call64bit

# C compiler
CC=gcc
# C compiler 64-bit flags
C64FLAGS=-fno-pie -O1 -m64 -no-pie -fno-stack-protector -g
# Assembler
ASM=nasm
# Assembler 64-bit flags
ASMFLAGS64=-felf64 -g


all: quad


quad: solver.o main.o
	$(CC) $(C64FLAGS) -o quad solver.o main.o

solver.o: solver.asm
	$(ASM) $(ASMFLAGS64) -o solver.o solver.asm

main.o: main.c
	$(CC) $(C64FLAGS) -c -o main.o main.c


clean:
	rm -rf *.o quad

