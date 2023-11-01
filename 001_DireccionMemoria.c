// By Rafael Baculima (sigladon)
#include <stdio.h>

int main(void) {
	
	int myInt = 100;
	
	printf("The value of \"myInt\" is %d, the memory address is %u and has a size of %d bytes\n", myInt, &myInt, sizeof(myInt));
	
	int *ptrInt;
	
	printf("The memory address of \"ptrInt\" is %d and has a size of %u bytes", &ptrInt, sizeof(ptrInt));
	
	return 0;
}
