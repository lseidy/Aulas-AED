#include "biblista.h"

struct vars{
    struct vars *last;
    struct vars *next;
    cad pessoas;
};
typedef struct vars elem;

void limpa(){
    system("cls||clear");
}
int menu(void *pbuffer){
    nbuffer *p;
    p = pbuffer;
    
    do{
    limpa();
    printf("|______[M E N U]_______|\n");
    printf("|1  -  Incluir nome    |\n");
    printf("|2  -  Apagar nome     |\n");
    printf("|3  -  Buscar nome     |\n");
    printf("|4  -  Listar          |\n");
    printf("|5  -  Sair            |\n");
    printf("->Digite: "); scanf("%c", &p->i);
    }while((p->i - '0')>5 ||(p->i - '0')<0);
    getchar();
   
    return p->i - '0'; 
}
void freelist(Lista* list){
    if(list != NULL){
        elem* caixa;
        while((*list) != NULL){ //condicao o conteudo ser igual a NULL
            caixa = *list; 
            *list = (*list)->next; // topo passa a ser o proximo
            free(caixa);
        }
        free(list);
    }
}
bool Push(void* pbuffer,Lista* list){
    nbuffer *novo;
    novo = pbuffer;
    
    do{
        printf("->Digite o novo nome: ");
        fgets((*novo).pessoas.pessoa, 50, stdin);
    }while((*novo).pessoas.pessoa[0] == ' ' || (*novo).pessoas.pessoa[0] == '\n');

    if(list == NULL) return false; //se a lista desalocada
    
    elem* caixa = (elem*) malloc(sizeof(elem)); //declara nova variavel
    
    if(caixa == NULL) return false; //se falhou alocacao

    caixa->pessoas = novo->pessoas; //cadastro recebe o caixavo
    caixa->next = (*list); //caixa aponta para proxima caixa
    caixa->last = NULL; // na fila o anterior se torna o ultmo

    if((*list) != NULL)
        (*list)->last = caixa; // se a lista tiver elementos, a o topo aponta para a nova caixa 
    *list = caixa; // por fim o conteudo da caixa é inserido na lista
    novo->tam++;

    return true;
}
void Print(void *pbuffer, Lista *list){
    nbuffer *p;
    p=pbuffer;

    elem *n;
    n = *list;

    limpa();

    p->cont=0;
    printf("[Digite o criterio para a ordenacao]\n->1 - Alfabetica Crescente\n->2 - Alfabetica Decrescente\n->"); 
    
    do{
        scanf("%d", &p->aux);
    }while(p->aux>2 || p->aux <0);
    getchar();

    Sort(list, pbuffer);
    p->fila = (cad*) malloc(p->tam*sizeof(cad));
    while(n != NULL){
        p->fila[p->cont] = n->pessoas;
        p->cont++;
        n = n->next;
    }

    if(p->aux == 1){
        p->aux = 0;
        while(p->aux < p->tam){
            printf("%d: %s",p->aux, p->fila[p->aux].pessoa);
            p->aux++;
        }
        printf("Pressione qualquer tecla para continuar. . ."); getchar();
    }else{
        p->aux = p->tam - 1;
        while(p->aux >= 0){
            printf("%d: %s",p->aux, p->fila[p->aux].pessoa);
            p->aux--;
        }
        printf("Pressione qualquer tecla para continuar. . ."); getchar();
        
    }
    free(p->fila);

}
void Sort(Lista *list, void* pbuffer){
    nbuffer *p;
    p = pbuffer;
    elem *n, *i;
    n = *list;
    i = *list;

    while(n != NULL) { //passa o a lista
      i = n->next;
      while(i != NULL) { // passa uma outra lista para comparar os nomes
        if(strcmp(n->pessoas.pessoa, i->pessoas.pessoa) > 0) { // compara o nome anterior com o proximo
            strcpy(p->pessoas.pessoa, n->pessoas.pessoa);      // se for maior 
            strcpy(n->pessoas.pessoa, i->pessoas.pessoa);      // passa o nome maior para frente
            strcpy(i->pessoas.pessoa, p->pessoas.pessoa);      // passa o nome menor para tras
        }
        i = i->next;
      }
      n = n->next;
    }
}
bool Pop(void *pbuffer, Lista *list){
    if(list == NULL)
        return false;
    if(*list == NULL)
        return false;
    nbuffer *p;
    p=pbuffer;
    p->cont=0;
    elem *caixa;
    caixa = *list;
    printf("[Digite o numero da pessoa a ser removida]\n-> "); scanf("%d", &p->rem);
    getchar();

    while(caixa != NULL && p->cont != p->rem){ // percore a lista até encontrar aquele a ser removido
        caixa = caixa->next;
        p->cont++; 
    }     
    if(caixa == NULL)
        return false;
    if(caixa->last == NULL)
        *list = caixa->next;
    else
        caixa->last->next = caixa->next;  // a ligacao do ultimo recebe o proximo daquele que vou excluir
    if(caixa->next != NULL)
        caixa->next->last = caixa->last; // o anterior do próximo recebe o o anterior do que vou excluir
    free(caixa);

    p->tam--;
    return true;
    

}
void Search(void* pbuffer, Lista *list){
    nbuffer *p;
    elem *caixa;
    p = pbuffer;
    p->cont=0;
    caixa = *list;
    
    printf("[ Digite o nome para a busca ]\n-> ");
    fgets(p->pessoas.pessoa, 50, stdin);

    while(caixa!=NULL){
        if(strcmp(p->pessoas.pessoa, caixa->pessoas.pessoa) == 0){ // percorre comparando pra ver se acho o nome
            printf("[Nome na lista]\n->Posicao: %d", p->cont);
            printf("\n->Pressione qualquer tecla para continuar. . ."); getchar();
            return;
        }
        caixa = caixa->next;
        p->cont++;
    }
    printf("Nome nao encontrado");
    printf("\n->Pressione qualquer tecla para continuar. . ."); getchar();
}