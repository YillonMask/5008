#include <stdio.h>

int main(){
	char d[9] = "Xinrui Yi";
	//int i;

	printf("My name is: %s\n", d);

	for (int i=0; i < 9; i++){
		printf("The address of %dth character is: %p\n"
				,i, (char*)&d[i]);
	}
	return 0;
}
