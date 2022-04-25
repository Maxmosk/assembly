#include <stdio.h>


extern double _abs (double num);
extern double _add (double num_1, double num_2);


int main (void)
{
    printf ("%Lf\n", _add (-0.3, 23.0));

    return 0;
}

