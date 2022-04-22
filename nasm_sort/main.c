#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>


extern void sort (uint64_t *array, uint64_t size);
void rand_list (uint64_t *arr, uint64_t size);
uint64_t rdtsc ()
{
    uint32_t lo = 0;
    uint32_t hi = 0;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t) hi << 32) | lo;
}

int main (void)
{
    uint64_t *arr = calloc (10000, 8);
    for (int i = 1; i <= 10000; i += 100)
    {
        printf ("%d ", i);
        
        uint64_t mid = 0;
        for (int j = 0; j < 10; j++)
        {
            rand_list (arr, i);
            uint64_t time_val = rdtsc ();
            sort (arr, i);
            time_val = rdtsc () - time_val;
            mid += time_val;
        }
        printf ("%f \n", ((double) mid) / 10);
    }

    return 0;
}


void rand_list (uint64_t *arr, uint64_t size)
{
    srand (time (NULL));
    for (uint64_t i = 0; i < size; i++)
    {
        arr[i] = rand ();
    }
}

