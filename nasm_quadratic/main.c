#include <stdio.h>


extern long double _abs (long double number);


int main (void)
{
    printf ("%Lf\n", _abs (-0.3));

    return 0;
}

