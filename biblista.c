#include "biblista.h"

struct vars{
    struct vars *last;
    struct vars *next;
    char i;
    cad pessoas;
};
typedef struct vars elem;
void limpa(){
    system("cls||clear");
}
int menu(Lista *pbuffer){
    Lista *p;
    p = pbuffer;

    limpa();
    printf("|______[M E N U]_______|\n");
    printf("|1  -  Incluir nome    |\n");
    printf("|2  -  Apagar nome     |\n");
    printf("|3  -  Buscar nome     |\n");
    printf("|4  -  Listar          |\n");
    printf("|5  -  Sair            |\n");
    printf("->Digite: "); scanf("%c", &(*p)->i);
    getchar();
   
    return (*p)->i - '0'; 
}
void freelist(Lista* list){
    if(list != NULL){
        elem* caixa;
        while((*list) != NULL){
            caixa = *list;
            *list = (*list)->next;
            free(caixa);
        }
        free(list);
    }
}
bool Push(void* pbuffer,Lista* list){
    cad novo;
    //novo=pbuffer;
    printf("Digite o novo nome: "); 
    fgets(novo.pessoa, 50, stdin); 

    if(list == NULL) return false; //se a lista desalocada
    
    elem* caixa = (elem*) malloc(sizeof(elem)); //declara nova variavel
    
    if(caixa == NULL) return false; //se falhou alocacao
    
    printf("%s", novo.pessoa);
    caixa->pessoas = novo; //cadastro recebe o novo
    printf("%s", caixa->pessoas.pessoa);
    caixa->next = (*list);
    caixa->last = NULL;

    if((*list) != NULL)
        (*list)->last = caixa;
    *list = caixa;
    return true;
}