#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "AEDHeader.h"

void menu(int *op){
    int aux;
    
    printf("_____________MENU_____________\n");
    printf("|1- Adicionar nome            |\n");
    printf("|2- Remover nome              |\n");
    printf("|3 - Listar agenda            |\n");
    printf("\n Digite Enter para sair . . .");
    aux = getch();
    *op = aux - '0';
}