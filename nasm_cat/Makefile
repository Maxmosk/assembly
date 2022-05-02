.PHONY: all clean

# Assembler
ASM=nasm
# Assembly flags
ASMFLAGS=-felf64
# Linker
LD=ld
# Linker flags
LDFLAGS=-m elf_x86_64
all: cat

cat: cat.asm
	$(ASM) $(ASMFLAGS) -o cat.o cat.asm
	$(LD) $(LDFLAGS) -o cat cat.o
	chmod u+x cat

clean:
	rm *.o cat

