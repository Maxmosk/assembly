#include <stdio.h>


extern long double _solver (long double a, long double b);


int main (void)
{
    printf ("%Lf\n", _solver (0.1, 0.3));

    return 0;
}

