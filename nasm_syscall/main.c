#include <stdint.h>
#include "syscall.h"


int main (void)
{
	char hw[] = "Masha is a cute fox!\n";
	uint64_t a = __syscall__ (1, 1, (long) hw, 21, 0, 0, 0);
	
	__syscall__ (0x3c, 0);
}

