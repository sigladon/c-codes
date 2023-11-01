// By Rafael Baculima (sigladon)
#include <stdio.h>

int main(void) {
	
	int d = 10;
	double e = 10.1;
	char f = 'a';
	
	int *ptrd = &d;
	double *ptre = &e;
	char *ptrf = &f;
	
	printf("%10s %10s %10s\n","directo","indirecto","direccion");
	printf("%10d %10d %10u\n",d,*ptrd,&d);
	printf("%10.1f %10.1f %10u\n",e,*ptre,&e);
	printf("%10c %10c %10u",f,*ptrf,&f);

	return 0;
}
