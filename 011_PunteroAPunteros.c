// By Rafael Baculima (Sigladon)
// Puntero a Punteros

#include <stdio.h>

int main (void) {
	
	int var;
	int *ptr;
	int **pptr;
	
	var = 3000;
	
	// Toma la dirección de var
	ptr = &var;
	
	// Toma la dirección de ptr usando & 
	pptr = &ptr;
	
	// Toma el valor usando pptr
	printf("Valor de var = %d\n", var);
	*ptr = 5000;
	printf("Valor disponible en *ptr = %d\n", *ptr);
	**pptr = 7000;
	printf("valor disponible en **pptr = %d\n", **pptr);
	
	printf("Prueba %u\n", **&pptr);
	printf("Direccion var: %u. Direccion *ptr: %u. Direccion **pptr: %u", &var, &ptr, &pptr);
	
	return 0;
}