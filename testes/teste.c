#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
	char *a = "       &Savio Camacam";
	char b, d;
//	printf ("%c\n", b);
	d = 'a';
	int c;
	c = isalnum(d);
//	printf ("%d\n", c);
	int i=0;
	b = *(a+i);
	while (isspace(b) == 8) {
		i++;
		printf ("%c", b);
		b = *(a+i);
	}
	printf ("%d", i);
	b = *(a+i);
	while (isalnum(b) == 0) {
		i++;
		printf ("%c", b);
		b = *(a+i);
	}
	printf ("%d", i);
/*	while(isalnum(b)) {
		b = *(a+i);
		printf ("%c", b);
		i++;
	}
//	printf ("%d", i-1);
	b = *(a+i);
	while(isalnum(b)) {
		b = *(a+i);
		printf ("%c", b);
		i++;
	}*/
	return 0;
}
