#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, n[1], *j;
	n[0] = 9;
	j = &n;
	j = malloc(sizeof(int)*2);
	
	printf("\n[%d] = %d", 0, n[0]);
	return 0;
	
}