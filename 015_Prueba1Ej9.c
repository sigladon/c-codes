#include <stdio.h>
int main(void) {
	int i = 100, *p = &i;
	function(&p);
	printf("%d", *p);
	printf("%d", i);
	return 0;
}

void function(int **p) {
	int j = 2;
	*p = &j;
	printf("%d", **p);
}