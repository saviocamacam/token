#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3

typedef struct {
	char *string;
	int tam;
	int cursor;
}TokenReader;

TokenReader* newtoken(char *str) {
	TokenReader *rP = (TokenReader*) calloc (1,sizeof(TokenReader));
	rP->tam = strlen(str);
	rP->string = (char*) calloc (rP->tam+1, sizeof(char));
	strcpy(rP->string, str);
	rP->cursor = 0;
	return rP;
}
//Libera Token
void freetoken (TokenReader *reader) {
	free(reader->string);
}
//Substring
char *stringretorno (char *str, int in, int f) {
	int n = f - in;
	int i;
	char *rS = (char*) calloc (n+1,sizeof(char));
	/*for (i=0 ; i<n ; i++) {
		rS[i] = str[in];
		in++;
	}*/
	memcpy (rS,str+in,n);
	return rS;
}
//Função letra
void fletra (char *str, int a, int *b) {
	int i=a;
	char c = *(str + i);
	while (isalnum(c)) {
		c = *(str+i);
		i++;
	}
	*b = i-1;
}
//Função numeros
void fnum (char *str, int a, int *b) {
	int i=a;
	char c = *(str + i);
	while (isdigit(c) > 0 || c == ',') {
		i++;
		c = *(str+i);
	} *b = i;
}
//Descarta espaços
void fspace(char *str, int a, int *b) {
	int i=a;
	char c = *(str+i);
	while (isspace(c) == 8) {
		i++;
		c = *(str+i);
	} *b = i;
}
//Próximo Token
char *nextToken (TokenReader *reader) {
	int b, fim, i, inicio, d;
	i = reader->cursor;
	//coleta o primeiro elemento da string
	char c = *(reader->string + i);
	//verifica se é espaço
	if (isspace(c)==8) {
		//elimina os espaços
		fspace(reader->string, i, &reader->cursor);
		i=reader->cursor;
	}
	//coleta o elemento posterior os espaços
	c = *(reader->string + i);
	//b identifica qual o tipo de caractere
	b = isalnum(c);
	//se b é 0 = caractere epecial
	if (b == 0) {
		inicio = reader->cursor;
		fim = inicio+1;
		char *rS = (char*) calloc ((fim-inicio)+1,sizeof(char));
		rS = (char*)stringretorno(reader->string, inicio, fim);
		reader->cursor = fim;
		return rS;
	}
	else if (b == 2 || b == 1) {
		inicio = reader->cursor;
		fletra(reader->string, inicio, &fim);
		char *rS = (char*) calloc ((fim-inicio)+1,sizeof(char));
		rS = (char*)stringretorno(reader->string, inicio, fim);
		reader->cursor = fim;
		return rS;
	}
	else if (b == 4) {
		inicio=reader->cursor;
		fnum(reader->string, inicio, &fim);
		
		char *rS = (char*) calloc ((fim-inicio)+1,sizeof(char));
		rS = (char*)stringretorno(reader->string, inicio, fim);
		
		reader->cursor = fim;
		return rS;
	}
}
//Altera Token de leitura
void settoken (TokenReader *reader, char *str) {
	reader->tam = strlen(str);
	reader->string = (char*) calloc (reader->tam+1, sizeof(char));
	strcpy(reader->string, str);
	reader->cursor = 0;
}
//Indica que ainda há tokens
int hasmoretokens (TokenReader *reader) {
	if (reader->cursor < reader->tam) {
		return 1;
	} return 0;
}
//Programa principal
int main () {
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
