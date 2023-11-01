#include <stdio.h>
int main(void) {
	int r = 20;
	int *p = &r;
	unaFuncion(&p);
	printf("%d\n", *p);
	return 0;
	
}

void unaFuncion(int *p) {
	int q = 10;
	p = &q;
}