#include "bibliotecainfinita.h"

void limpa(){
    system("cls");
};
Pessoa* novocadastro(Pessoa *cadastro, int *tamanho){
    limpa();
    if(*tamanho > 1){
        cadastro = (Pessoa*) realloc(cadastro, *tamanho*sizeof(Pessoa));
    }

    printf("Digite o novo nome: ");
    fflush(stdin);
    gets(cadastro[*tamanho-1].nome);

    printf("Digite a idade: ");
    scanf("%i", &(cadastro[*tamanho-1].idade));

    printf("Digite a altura: ");
    scanf("%i", &(cadastro[*tamanho-1].altura));
    
    *tamanho = *tamanho + 1;
    return cadastro;
};
void listar(Pessoa *cadastro, int *tamanho){
    int i=0;
    limpa();

    printf("----------[LISTA DE NOMES]---------\n");
    for(i=0;i<(*tamanho-1); i++){
        printf("Dados \n");
        printf("Nome %d: %s\n", i, cadastro[i].nome);
        printf("Idade %d: %d\n", i, cadastro[i].idade);
        printf("Altura %d: %d\n\n", i, cadastro[i].altura);
        printf("-----------------------------------\n");        
    }
}


