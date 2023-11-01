// By Rafael Baculima
// Aritmética de Punteros
// Arreglo en memoria Heap

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_LENGTH 10000000

int main (void) {
	
	int *vectorPtr = malloc(sizeof(int[VECTOR_LENGTH]));
	
	srand(time(NULL));
    for (int i = 0; i < VECTOR_LENGTH; i++) {
        *(vectorPtr+i) = rand() % 100;
        printf("%d\n", *(vectorPtr+i));
    }
    
	free(vectorPtr);
	
	return 0;
}