#include <stdio.h>
#include <stdint.h>

extern int SORT_$$_SORT$PQWORD$QWORD (void *array1, uint64_t size);


int main (void)
{
    uint64_t arr[] = {1, 5, 3, 1, 2, 1, 1};
    void *bug = &arr;
    SORT_$$_SORT$PQWORD$QWORD (&bug, sizeof (arr) / sizeof (uint64_t));

    
    for (uint64_t i = 0; i < sizeof (arr) / sizeof (uint64_t); i++)
        printf ("%ld ", arr[i]);

    return 0;
}

