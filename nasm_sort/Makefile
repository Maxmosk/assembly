.PHONY: all clean asmplot pasplot

# C compiler
CC=gcc
# C compiler 64-bit flags
C64FLAGS=-m64 -fno-pie -no-pie -O0 -g -fno-stack-protector
# Assembler
ASM=nasm
# Assembler 64-bit flags
ASMFLAGS64=-felf64 -g

# Pascal compiler
PC=fpc
# Pascal compiler flags
PFLAGS=


all: sort_asm sort_pas


sort_asm: main.o sort_asm.o
	$(CC) $(C64FLAGS) -o sort_asm sort_asm.o main.o

main.o: main.c
	$(CC) $(C64FLAGS) -c -o main.o main.c

sort_asm.o: sort_asm.asm
	$(ASM) $(ASMFLAGS64) -o sort_asm.o sort_asm.asm

sort_pas: pascal_prof.o sort_pas.o
	$(CC) $(C64FLAGS) -o sort_pas sort_pas.o pascal_prof.o

pascal_prof.o: pascal_prof.c
	$(CC) $(C64FLAGS) -c -o pascal_prof.o pascal_prof.c

sort_pas.o: sort_pas.pp
	$(PC) $(PFLAGS) sort_pas.pp &>/dev/null


asmplot: sort_asm
	./sort_asm &> data.txt
	./prof_plot.py
	rm data.txt

pasplot: sort_pas
	./sort_pas &> data.txt
	./prof_plot.py
	rm data.txt

clean:
	rm -rf *.o sort_asm sort_pas *.ppu


