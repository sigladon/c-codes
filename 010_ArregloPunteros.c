// By Rafael Baculima (sigladon)
// Arreglo de Punteros

#include <stdio.h>

int main(void) {
	
	int miArreglo[8] = {1,2,3,4,5,6,7,8};
	int *ptr2[8];
	
	for (int i = 0; i < 8; i++) {
		
		ptr2[i] = &miArreglo[i];
		printf("La direccion de miArreglo[%d] es %u\n", i, &miArreglo[i]);
	}
	
	puts("");
	
	for (int i = 0; i < 8; i++) {
		printf("ptr2[%d] guarda %d en la direccion %u\n", i, *ptr2+i, &ptr2+i);
	}
	
	return 0;
	
}

