#ifndef _AEDHEADER_H
#define _AEDHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int menu();
void limpa();
char* addnome(char *agenda, int *tam, int *i );
char* apaga(char *agenda, int *tam, int *i);
void listar(char *agenda);

#endif

