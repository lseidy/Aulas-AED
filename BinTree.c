#include "TreeHeader.h"

int main(){
    bintree* raiz = planttree();
    int info, sel=1, h;
    char op;

    do{
        system("clear||cls");
        printf("|(1) - Inserir numero|\n");
        printf("|(2) - Retirar numero|\n");
        printf("|(3) - Listar Arvore |\n");
        printf("|(4) - Sair          |\n");
        printf("->Digite a opcao: "); scanf("%c", &op);
        getchar();
        if(op - '0' == 1){
            printf("Digite o numero para inserir: "); scanf("%d", &info);
            getchar();
            sel = AVLinsert(raiz, info);

            printf("\n[Digite qualquer coisa para sair . . .]"); getchar();
            sel = 1;
        }
        if(op - '0' == 2){
            printf("Digite o numero para remover: "); scanf("%d", &info);
            getchar();
            sel = AVLremove(raiz, info);
        }
        if(op - '0' == 3){
            info = 0;
            h = AVLheight(*raiz);
            while(info<=h){
                TreePrint(raiz, info, info);
                info++;
            }
            printf("\nDigite qualquer coisa para sair . . ."); getchar();
        }
        if(op - '0' == 4){
            if(AVLcheck((*raiz)) == 1)
                printf("->Arvore AVL");
            else
                printf("->Deu errado parceiro"); 
            printf("\nDigite qualquer coisa para sair . . ."); getchar();
            cuttree(raiz);
            sel = 0;
        }

    }while(sel != 0);
    return 0;
}