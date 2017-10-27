#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	char *str = " &Savio Camacam";
	int i=0, b;
	char c = *(str+i);
	b = isalnum(c);
	if (isspace(b) == 8) {
		printf ("savio");
	}
	printf ("%d\n", b);
	
	
	return 0;
}
