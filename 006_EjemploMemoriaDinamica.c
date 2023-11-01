// By Rafael Baculima (sigladon)
// Ejemplo de Memoria Dinámica

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	// Declaración y asignación de memoria para los punteros
	int *ptr1 = malloc(sizeof(int));
	int *ptr2 = malloc(sizeof(int));
	
	// Asignar valores a ptr1 y ptr2
	*ptr1 = 23;
	*ptr2 = 16;
	
	printf("Value of num1 is %d. Value of num2 is %d\n", *ptr1, *ptr2);

	// Se libera la memoria
	free(ptr1);
	free(ptr2);
	
	return 0;
}