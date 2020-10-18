#ifndef _VOIDBIB_H
#define _VOIDBIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char pessoa[50];
}cad;
typedef struct{
    char i;
    int words, aux, n;
    char pessoa[50];
}varvoid;

varvoid* apagar(void *pbuffer);
int menu(void *pbuffer);
void limpa();
void listar(void* pbuffer);
varvoid* incluir(void *pbuffer);
varvoid* iniciar(void* pbuffer);
void buscar(void *pbuffer);
void liberar(void *pbuffer);

#endif