#include <stdio.h>


void swap(int a, int b){
	
	printf("Before the swap:\n");
	printf("%d, %d\n", a, b);

	int temp = a;
	a = b;
	b = temp;
	printf("After the swap:\n");
	printf("%d, %d", a, b);
	
}

int main(){
	
	int a, b;
	a = 10;
	b = 15;
	printf("%d\n", a*b);
	swap(a, b);
	return 0;
}


