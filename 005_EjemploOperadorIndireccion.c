// By Rafael Baculima (sigladon)
// Ejemplo de operador de Indirección

#include <stdio.h>

int main(void) {
	
	// Declaración y asignación de variables
	int num1 = 10;
	int num2 = 20;
	int *ptr1;
	int *ptr2;
	
	// Asignación de la dirección de memoria
	ptr1 = &num1;
	ptr2 = &num2;
	
	// Cambiar valor de num1 y num2 por medio de punteros
	*ptr1 = 30;
	*ptr2 = 40;
	
	*ptr2 = *ptr1;
	
	printf("Value of num1 is %d. Value of num2 is %d", *ptr1, *ptr2);

	
	return 0;
}

