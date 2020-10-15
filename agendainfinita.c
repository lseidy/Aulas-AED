#include "bibliotecainfinita.h"
/*
    ********************ATENDCAO**************
    *PARA COMPILAR NO VS CODE, COLOQUE OS ARQUIVOS NA MESMA PASTA E DIGITE NO TERMINAL
    gcc agendainfinita.c bibliotecainfinita.c -o agenda    (ou nome que vc quiser)
    
    *DEPOIS ABRA O EXECUTAVEL COM
    cmd /c .\"agenda.exe"    (ou nome que vc digitou)

*/

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