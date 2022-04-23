#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>


extern void SORT_PAS_$$_SORT$PQWORD$QWORD (uint64_t *array, uint64_t size);

void rand_list (uint64_t *arr, uint64_t size);

uint64_t rdtsc (void);


const uint16_t N_CYCLES = 50;
const uint64_t MAX_ELEM = 10000;
const uint16_t STEP = 100;


int main (void)
{
    uint64_t *arr = calloc (MAX_ELEM, sizeof (uint64_t));
    for (int i = 100; i <= MAX_ELEM; i += STEP)
    {
        printf ("%d ", i);
        
        uint64_t mid = 0;
        for (int j = 0; j < N_CYCLES; j++)
        {
            rand_list (arr, i);
            void *bug = &arr;
            uint64_t time_val = rdtsc ();
            SORT_PAS_$$_SORT$PQWORD$QWORD (bug, i);
            time_val = rdtsc () - time_val;
            mid += time_val;
        }
        printf ("%f \n", ((double) mid) / 10);
    }

    
    free (arr);

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

uint64_t rdtsc (void)
{
    uint32_t lo = 0;
    uint32_t hi = 0;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t) hi << 32) | lo;
}
