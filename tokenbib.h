#ifndef TOKENBIB_H_INCLUDED
#define TOKENBIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *string;
	int tam;
	int cursor;
}TokenReader;

TokenReader* newtoken(char *str);
//Libera Token
void freetoken (TokenReader *reader);
//Substring
char *stringretorno (char *str, int in, int f);
//Fun��o letra
void fletra (char *str, int a, int *b);
//Fun��o numeros
void fnum (char *str, int a, int *b);
//Descarta espa�os
void fspace(char *str, int a, int *b);
//Pr�ximo Token
char *nextToken (TokenReader *reader);
//Altera Token de leitura
void settoken (TokenReader *reader, char *str);
//Indica que ainda h� tokens
int hasmoretokens (TokenReader *reader);

#endif
