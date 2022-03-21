#include <stdio.h>
#include <stdint.h>


extern uint64_t factorial (uint64_t n);


int main (void)
{
    uint64_t n = 12;
    //scanf ("%ld", &n);

    //n = factorial (n);
    printf ("%ld\n", n);


    return 0;
}
