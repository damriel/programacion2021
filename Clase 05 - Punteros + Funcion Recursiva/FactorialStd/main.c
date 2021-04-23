#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int factorialRec(int n);

int main()
{
    int num = factorialRec(5);
    printf("%d",num);
    return 0;
}

int factorial(int n)
{
    int fact=1;

    for(int i=1; i<=n; i++)
    {
        fact*=i;
    }

    return fact;
}

/** FUNCION RECURSIVA **/
int factorialRec(int n)
{
    int fact;
    if(n==1 || n==0)
    {
        fact=1;
    }
    else
    {
        fact = n*factorialRec(n-1);
    }
    return fact;
}
