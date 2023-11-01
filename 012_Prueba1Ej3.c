#include <stdio.h>
int main(void) {
	char *ptr;
	char string[] = "Juventud divino tesoro";
	ptr = string;
	ptr += 7;
	printf("%c\n", *ptr);
	printf("%c\n", *string);
	return 0;
	
	
}