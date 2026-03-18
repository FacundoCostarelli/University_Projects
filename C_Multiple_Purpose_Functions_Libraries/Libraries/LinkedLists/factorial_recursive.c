#include<stdio.h>

int funcion(int n);


int main()
{
    printf("%d\n",funcion(4));

    return 0;
}

int funcion(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return(n * funcion(n-1));
    }
}
