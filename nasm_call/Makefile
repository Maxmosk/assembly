.PHONY: all clean call32bit # call64bit

# C compiler
CC=gcc
# C compiler 32-bit flags
C32FLAGS=-m32
# C compiler 64-bit flags
C64FLAGS=-m64
# C compiler common flags
CCOMFLAGS=-nostartfiles -O0
# Assembler
ASM=nasm
# Assembler flags
ASMFLAGS=-felf


all: call32bit # call64bit


call32bit: call32bit.o
	$(CC) $(C32FLAGS) $(CCOMFLAGS) -o call32bit call32bit.o

call32bit.o: call32bit.asm
	$(ASM) $(ASMFLAGS) -o call32bit.o call32bit.asm


clean:
	rm -rf *.o call??bit

