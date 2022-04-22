.PHONY: all clean plot

# C compiler
CC=gcc
# C compiler 64-bit flags
C64FLAGS=-m64 -fno-pie -no-pie -O0 -g -fno-stack-protector
# Assembler
ASM=nasm
# Assembler 64-bit flags
ASMFLAGS64=-felf64 -g


all: sort


sort: main.o sort.o
	$(CC) $(C64FLAGS) -o sort sort.o main.o

main.o: main.c
	$(CC) $(C64FLAGS) -c -o main.o main.c

sort.o: sort.asm
	$(ASM) $(ASMFLAGS64) -o sort.o sort.asm


plot: sort
	./sort &> data.txt
	./prof_plot.py
	rm data.txt

clean:
	rm -rf *.o sort


