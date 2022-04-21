#include <stdio.h>
#include <stdint.h>


extern void _sort (uint64_t *array, uint64_t size);


int main (void)
{
    uint64_t arr[] = {10, 1, 2, 3, 4, 5, 6};
    _sort (arr, sizeof (arr) / sizeof (uint64_t));
    
    for (int i = 0; i < sizeof (arr) / sizeof (uint64_t); i++)
        printf ("%d\n", arr[i]);


    return 0;
}

