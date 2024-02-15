#include <stdio.h>

long long fibonacci(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 12;
    for (int i = 0; i <= n; i++)
    {
        printf("%dth Fibonacci Number: %lld\n", i, fibonacci(i));
    }
    return 0;
}
