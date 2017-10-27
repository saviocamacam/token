#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int b, i;
	char *str = "Savio Camacam";
	printf ("%s", str);
	i=0;
	while (hasmoretokens(*(str+i)) == 1) {
		i++;
	}
	
	return 0;
}
