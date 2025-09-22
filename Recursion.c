/*Recursion -> It is a type of function which is called by itself.
1. Direct recursion
2. Indirect recursion
How function call

Base condition is a condition

*/
#include <stdio.h>
/*
int Factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    return num * Factorial(num - 1);
}
*/

int fibonacci(int num)
{
    if (num <= 1)
    {
        return num;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    int n = 11;
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
    // printf("%d",Factorial(a));
}
