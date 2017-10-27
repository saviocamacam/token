#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenbib.h"
#define T 3

int main(int argc, char *argv[]) {
	int a, op=0;
	char *str;// = "Savio Camacam 21/01/95 * * **&";
	char s[30];
	printf ("INFORME UMA STRING: ");
	scanf ("%[^\n]", s);
	str = s;
	TokenReader *reader = newtoken(str);
	do{
		printf ("(1) ALTERAR STRING\n");
		printf ("(2) EXTRAIR TOKENS\n");
		printf ("(3) LIBERAR TOKEN\n");
		printf ("(4) NOVO TOKEN\n");
		printf ("(5) SAIR\n");
		printf ("opcao: ");
		scanf ("%d", &op);
		if (op == 1) {
			fflush(stdin);
			setbuf(stdin,NULL);
			printf ("\nINFORME UMA STRING: ");
			scanf ("%[^\n]", s);
			str = s;
			settoken(reader, str);
		}
		else if (op == 2) {
	 		printf ("\nTOKENS: ");
			if (hasmoretokens(reader) == 0) {
				printf ("NAO HA TOKENS!\n");
			}
			else {
				do{
					char *token = nextToken(reader);
					printf ("%s ", token);
				}while(hasmoretokens(reader));
				printf ("\n\n");
			}
		}
		else if (op == 3) {
			freetoken(reader);
		}
	} while (op != 5);	
	return 0;
}
