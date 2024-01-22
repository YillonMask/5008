#include <stdio.h>

int main(){
	int x = 500;
	int *y = &x;
	printf("Value of x is :%d\n", x);
	printf("The address of value x  is: %p\n", y);
	printf("The size of value x is: %zu bytes\n", sizeof(x));
	printf("Value of pointer y is :%p\n", y);
	printf("The size of pointer y is:%zu bytes\n",sizeof(y));
	printf("The address of pointer y is: %p\n", (void *)&y);
	return 0;
}

