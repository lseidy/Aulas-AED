#ifndef _BIB_LISTA_H
#define _BIB_LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char pessoa[50];
}cad;
typedef struct{
    char i;
    int cont, rem, tam, aux;
    cad pessoas;
    cad *fila;
}nbuffer;
typedef struct vars* Lista; // declaracao de ponteiro
int menu(void *pbuffer);
void freelist(Lista *list);
void limpa();
bool Push(void* pbuffer,Lista* list);
void Print(void *pbuffer, Lista *list);
bool Pop(void *pbuffer, Lista *list);
void Search(void* pbuffer, Lista *list);
void Sort(Lista *list, void* pbuffer);
#endif