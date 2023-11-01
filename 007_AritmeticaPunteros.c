// By Rafael Baculima
// Aritmética de Punteros

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
	
	int vectorLength = 20;
	int vector[vectorLength];

	int *a = &vector[0]; // Se guarda la posición en memoria del  primer elemento del vector
	
	srand(time(NULL));
    for (int i = 0; i < vectorLength; i++) {
        *(a+i) = rand() % 100; // Importante usar entre parentesis al dirección al arreglo
        printf("%d\n", *(a+i));
    }
	
	return 0;
}