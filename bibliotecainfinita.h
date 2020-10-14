#ifndef _BIBLIOTECAINFINITA_H
#define _BIBLIOTECAINFINITA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
    char nome[30];
    int altura;
    int idade;
}Pessoa;

void limpa();

Pessoa* novocadastro(Pessoa *cadastro, int *tamanho);
void listar(Pessoa *cadastro, int *tamanho);

#endif