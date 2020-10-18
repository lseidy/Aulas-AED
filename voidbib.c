#include "voidbib.h"

void limpa(){
    system("cls||clear");
}
int menu(void *pbuffer){
    varvoid *n;
    n = pbuffer;

    do{
        limpa();
        printf("-----[ Menu ]-----\n");
        printf("1 - Incluir nome\n");
        printf("2 - Apagar nome \n");
        printf("3 - Buscar nome \n");
        printf("4 - Listar      \n");
        printf("5 - Sair        \n");
        printf("Digite: ");
        fflush(stdin); scanf("%c", &n->i);
        if((n->i - '0') == 5){
            break;
        }
        if((n->i - '0') > 5 || (n->i - '0') < 1){
            printf("Digite um valor valido\n");
            system("pause");
        }
        else{
            break;
        }
    }while(1);
    
    return (n->i - '0');
}
varvoid* incluir(void *pbuffer){
    cad *n;
    varvoid *i;
    i = pbuffer;
    pbuffer = realloc(pbuffer, sizeof(varvoid) + sizeof(cad) + (i->words * sizeof(cad)));

    i = pbuffer;
    n = pbuffer + sizeof(varvoid) + (i->words * sizeof(cad)); 

    fflush(stdin);
    printf("Digite um nome: ");
    fgets(n->pessoa, 50, stdin);

    i->words++;
    return pbuffer;
}
varvoid* iniciar(void* pbuffer){
    varvoid *n;
    n=pbuffer;
    n->words=0;
    n->aux=0;

    return pbuffer;
}
void listar(void *pbuffer){
    cad *p;
    varvoid *aux;
    p = pbuffer + sizeof(varvoid) + (0 * sizeof(cad)); 
    aux = pbuffer;
    
    aux->aux = 0;
    while(aux->aux < aux->words){
        printf("%d - ", aux->aux);
        printf("%s", p->pessoa);
        aux->aux++;
        p++;
    }
    system("pause");
}
void buscar(void *pbuffer){
    cad *p;
    varvoid *i;
    i= pbuffer;

    p = pbuffer + sizeof(varvoid);
    printf("digite o nome para busca: ");
    fflush(stdin);

    fgets(i->pessoa,50, stdin);

    i->aux = 0;
    while(i->aux < i->words){
        if(strcmp(i->pessoa, p->pessoa) == 0){
            printf("Nome na lista posicao: %d\n", i->aux);
            break;
        }else{
            i->aux++;
            p++;
        }
    }
    system("pause");


}
varvoid* apagar(void *pbuffer){
    varvoid *i;
    cad *p, *n;
    i=pbuffer;
    printf("Digite o numero do nome a ser removido: "); scanf("%d", &i->n);
    p = pbuffer + sizeof(varvoid) +(i->n *sizeof(cad));

    printf("%d\n", sizeof(pbuffer));
    while(i->n < i->words){
        n = pbuffer + sizeof(varvoid) + ((i->n+1) *sizeof(cad));
        strcpy(p->pessoa, n->pessoa); 
        i->n++;
        p++;
    }
    
    i->words--;
    pbuffer = realloc(pbuffer, sizeof(varvoid) + sizeof(cad) + (i->words *sizeof(cad)));
    printf("%d\n", sizeof(pbuffer));
    system("pause");

    return pbuffer;
}
/*void liberar(void *pbuffer){
    cad *p, *m, *n, *o;
    varvoid *k, *l;
    p=pbuffer;
    m= pbuffer;
    n = pbuffer;
    o = pbuffer;
    k = pbuffer;
    l=pbuffer;

    free(p);
    free(m);
    free(n);
    free(o);
    free(k);
    free(l);

    free(pbuffer);
}*/