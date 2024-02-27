#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    // Define a function pointer to the add function
    // (*fun_ptr)(Para_type) = function_name/&function_name
    int (*addPtr)(int, int) = &add;

    // Call the add function using the function pointer
    int result = (*addPtr)(7, 8);

    printf("The result is: %d\n", result);

    return 0;
}
