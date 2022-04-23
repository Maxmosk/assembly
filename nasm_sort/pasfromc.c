#include <stdio.h>
#include <stdint.h>

extern int SORT_$$_SORT$PQWORD$QWORD$$QWORD (uint64_t, uint64_t *array, uint64_t n);


int main (void)
{
    uint64_t arr[] = {123, 234, 345, 456, 567};
    printf("%ld\n", SORT_$$_SORT$PQWORD$QWORD$$QWORD (1, arr, 5));
    return 0;
}

