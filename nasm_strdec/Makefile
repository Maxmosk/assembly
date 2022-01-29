.PHONY: all clean


all: strdec

strdec: strdec.o
	ld -o strdec strdec.o
	chmod u+x strdec

strdec.o: strdec.asm
	nasm -felf64 strdec.asm -o strdec.o

clean:
	rm -rf *.o strdec

