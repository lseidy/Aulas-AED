#include "biblista.h"

int main(){
    void *pbuffer = (nbuffer*) malloc(sizeof(nbuffer));
    nbuffer *p;
    p = pbuffer;
    p->cont =0;
    p->tam=0;
    
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if(list != NULL){
        *list = NULL;
    }
    
    do{
        limpa();
        switch(menu(pbuffer)){ //chama menu
            case 1:
                if(Push(pbuffer, list) == true){ // chama funcao pra incluir no pbuffer
                    printf("->Cadastro bem sucedido\nPressione qualquer tecla para continuar. . ."); getchar();
                }else{
                    printf("->Cadastro nao realizado\nPressione qualquer tecla para continuar. . ."); getchar();
                }
            break;
            case 2:
                if(Pop(pbuffer, list) == true){ // func para pagar
                    printf("->Nome removido\n");
                    printf("->Pressione qualquer tecla para continuar. . ."); getchar();
                }else{
                    printf("->Nome nao encontrado\n");
                    printf("->Pressione qualquer tecla para continuar. . ."); getchar();
                }
            break;
            case 3:
                Search(pbuffer, list); // busca nome
            break;
            case 4:
               Print(pbuffer, list); //lista nomes
            break;
            case 5:
                freelist(list);
                free(pbuffer);
                printf("[Programa Finalizado]");
                return 0;
            break;
        }
    }while(1);

    return 0;
}