// By Rafael Baculima (sigladon)
#include <stdio.h>

int main(void) {
	
	int a;
	double b;
	char c;
	
	printf("The size of a is %d bytes and its memory address is %u\n", sizeof(a), &a);
	printf("The size of b is %d bytes and its memory address is %u\n", sizeof(b), &b);
	printf("The size of c is %d bytes and its memory address is %u\n", sizeof(c), &c);

	return 0;
}
