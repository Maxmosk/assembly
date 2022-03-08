#include <stdint.h>
#include "syscall.h"


int main (void)
{
	char msg[] = "Masha is a cute fox!\n";
	uint64_t a = __syscall__ (1, 1, (long) msg, 21, 0, 0, 0); // write (msg, 21)
	
	__syscall__ (0x3c, 0); // exit (0)
}

