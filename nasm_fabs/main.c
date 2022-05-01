#include <stdio.h>
#include <math.h>


double _fabs (double num);

int main (void)
{
    double num = 0.0;
    scanf ("%lf", &num);
    printf ("%lf\n", _fabs(num));

    return 0;
}

