#include "TreeHeader.h"

int main(){
    bintree* raiz = planttree();
    int i=0, info , qtd, n;
    time_t t;

    srand((unsigned) time(&t));

    printf("Quantos folhas tu queres botar?: "); scanf("%d", &qtd);

    while(i<qtd){
        info = rand()%100;
        AVLinsert(raiz, info);
        i++;
    }
    i=0;
    info = AVLheight(*raiz);
    while(i<=info){
        TreePrint(raiz,i, i);
        i++;
    }

    if((n=AVLcheck(*raiz))==1)
        printf("AVL OK\n");
    else
        printf("Desbalanceada\n");
    cuttree(raiz);
    return 0;
}