#include <stdio.h>
int main(void) {
	char *ciudades[] = {"Quito", "Cuenca", "Loja"};
	int **i = &ciudades[0];
	printf("%c\n", **i);
	return 0;
	
}