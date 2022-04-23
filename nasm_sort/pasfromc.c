#include <stdio.h>
#include <stdint.h>

extern int SORT_$$_SORT$PQWORD$QWORD$$QWORD (void *array1, void *array2);


int main (void)
{
    uint64_t arr1[] = {1, 1, 1, 1, 1, 1, 1};
    uint64_t arr2[] = {2, 2, 2, 2, 2, 2, 2};
    void *bug = &arr2;
    printf("%ld\n", SORT_$$_SORT$PQWORD$QWORD$$QWORD (&bug, arr1));
    return 0;
}

