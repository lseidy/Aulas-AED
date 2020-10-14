#include "bibliotecainfinita.h"

int main(){
    Pessoa *cadastro;
    cadastro = (Pessoa*) malloc(1*sizeof(Pessoa)); 
    int i, tamanho=1;
    
    do{
        limpa();
        printf("---------MENU---------\n");
        printf("1 - Adicionar cadastro\n");
        printf("2 - Listar e Sair     \n");
        scanf("%i", &i);
        switch(i){
            case 1:
                cadastro = novocadastro(cadastro, &tamanho);
            break;
            case 2:
                listar(cadastro, &tamanho);
            return 0;
            break;
        }




    }while(1);

    return 0;
}