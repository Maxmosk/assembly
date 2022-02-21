.PHONY: all clean call32bit call64bit

# C compiler
CC=gcc
# C compiler 32-bit flags
C32FLAGS=-m32
# C compiler 64-bit flags
C64FLAGS=-fno-pie -m64 -no-pie
# C compiler common flags
CCOMFLAGS=-nostartfiles -O0
# Assembler
ASM=nasm
# Assembler 32-bit flags
ASMFLAGS32=-felf
# Assembler 64-bit flags
ASMFLAGS64=-felf64


all: call32bit call64bit


call32bit: call32bit.o
	$(CC) $(C32FLAGS) $(CCOMFLAGS) -o call32bit call32bit.o

call32bit.o: call32bit.asm
	$(ASM) $(ASMFLAGS32) -o call32bit.o call32bit.asm


call64bit: call64bit.o
	$(CC) $(C64FLAGS) $(CCOMFLAGS) -o call64bit call64bit.o

call64bit.o: call64bit.asm
	$(ASM) $(ASMFLAGS64) -o call64bit.o call64bit.asm


clean:
	rm -rf *.o call??bit

