#include <stdio.h>
#include <stdlib.h>
#include "Lopez.h"

int maximum(int a, int b, int c)
{
    int max;
    if(a>b && a>c)
    {
        max = a;
    }
    else if(b>=a && b>c)
    {
        max = b;
    }
    else
    {
        max = c;
    }
    return max;
}
