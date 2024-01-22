#include <stdio.h>
#include <stdlib.h>

int main(){
	int* arr_p = (int*)malloc(4*sizeof(int));

	arr_p[0] = 8;
	arr_p[1] = 9;
	arr_p[2] = 6;
	arr_p[3] = 4;

	for (int i=0; i<4; i++){
		printf("arr[%d] has value of %d\n",i,arr_p[i]);
	}
	free(arr_p);
	return 0;
}
