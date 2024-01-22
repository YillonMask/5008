#include <stdio.h>
#include <stdlib.h>

void updateArray1(int array[]){
	array[0] = 8;
	*(array+0) = 8;
}

void updateArray2(int *array){
	array[1] =24;// array in c is treated as pointer
}

int main(){
	int nums[3] = {1,2,3};
	// string is treated as array in c
	char d[10] = {'s','i','l','i','c','o','n'};

	
	updateArray1(nums);
	updateArray2(nums);

	printf("sizeof(int): %d\n", sizeof(int));
	
	printf("Our string is: %s\n", d);

	printf("%p\n", &nums[0]);
	printf("%p\n", &nums[1]);
	printf("%p\n", &nums[2]);

	printf("%p\n", nums);//array in c is treated as pointer
	printf("%p\n", nums+1);
	printf("%p\n", nums+2);

	printf("%d\n", *(nums));
	printf("%d\n", *(nums+1));
	printf("%d\n", *(nums+2));// * to derefernce the pointer to value

	printf("%d\n", nums[0]);
	printf("%d\n", nums[1]);
	printf("%d\n", nums[2]);
	return 0;
}
