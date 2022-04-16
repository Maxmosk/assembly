.PHONY: all clean

# C compiler
CC=gcc
# C compiler 64-bit flags
C64FLAGS=-m64 -fno-pie -no-pie -O0 -g -fno-stack-protector
# Assembler
ASM=nasm
# Assembler 64-bit flags
ASMFLAGS64=-felf64 -g


all: factorial


factorial: main.o factorial.o
	$(CC) $(C64FLAGS) -o factorial factorial.o main.o

main.o: main.c
	$(CC) $(C64FLAGS) -c -o main.o main.c

factorial.o: factorial.asm
	$(ASM) $(ASMFLAGS64) -o factorial.o factorial.asm


clean:
	rm -rf *.o factorial


