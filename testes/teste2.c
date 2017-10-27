#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
	char *a = "&%$";
	char c;
	int b, i=0, j=0;
	c = *(a+i);
	b = isalnum(c);
	if (b == 0) {
		while (isalnum(c) == 0) {
			i++;
			printf ("%c", c);
			c = *(a+i);
		}
		printf ("\n%c", c);
		b = isalnum(c);
		printf ("\n%d", b);
	}
//	printf ("%d", i);
	
	
	return 0;}
