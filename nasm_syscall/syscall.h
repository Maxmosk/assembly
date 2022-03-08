#ifndef SYSCALL_H_INCLUDED
#define SYSCALL_H_INCLUDED

#include <stdint.h>

uint64_t __syscall__ (uint64_t sys_code, ...);

#endif

