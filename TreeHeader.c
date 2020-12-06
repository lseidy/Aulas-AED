#include "TreeHeader.h"

struct NO{
    int data;
    int height; //necessario para o AVL
    struct NO *left;
    struct NO *right;
};
struct NO* searchlowest(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->left;
     
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->left;
    }
    return no1;

}
bintree* planttree(){
    bintree* raiz = (bintree*) malloc(sizeof(bintree)); //aloca a raiza da arvore
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

//Arvore Binaria
void burnseeds(struct NO* no){
    if(no == NULL)
        return;
    burnseeds(no->left); //vai percorrendo a esquerda
    burnseeds(no->right); // vai percorrendo a direta
    free(no); //quando encontra o ultimo volta liberando 
    no=NULL;
}
void cuttree(bintree *raiz){ 
    if(raiz == NULL)
        return;
    burnseeds(*raiz); //apaga no por no
    free(raiz); // apaga raiz
}
int notplanted(bintree *raiz){ // retorna 0 se nao tiver sido alocado previamente e o elemento inicial for lixo
    if(raiz==NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}
int treeheight(bintree *raiz){
    if(raiz==NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_left = treeheight(&((*raiz)->left));
    int alt_right = treeheight(&((*raiz)->right));

    if( alt_left > alt_right)
        return(alt_left+1);
    else
        return(alt_right+1);
}
int totalnots(bintree *raiz){
    int alt_left = treeheight(&((*raiz)->left));
    int alt_right = treeheight(&((*raiz)->right));
    return(alt_left + alt_right +1);
}
void preorder(bintree *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->data);
        preorder(&((*raiz)->left));
        preorder(&((*raiz)->right));
    }
}
void inorder(bintree *raiz){

    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        inorder(&((*raiz)->left));
        printf("%d\n", (*raiz)->data);
        inorder(&((*raiz)->right));
    }
}
void posorder(bintree *raiz){
    if(raiz == NULL)
            return;
    if(*raiz != NULL){
        posorder(&((*raiz)->left));
        posorder(&((*raiz)->right));
        printf("%d",(*raiz)->data );
    }
}
int insertleaf(bintree *raiz, int info){
    if(raiz == NULL)
        return 0;
    struct NO* leaf;
    leaf = (struct NO*) malloc(sizeof(struct NO));
    if(leaf == NULL)
        return 0;
    leaf->data = info;
    leaf->right = NULL;
    leaf->left = NULL;

    //procurar onde vai
    if(*raiz == NULL)
        *raiz = leaf;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(info == atual->data){
                free(leaf);
                return 0;
            }
            if(info > atual->data)
                atual = atual->right;
            else
                atual = atual->left;
        }
        if(info > ant->data)
            ant->right = leaf;
        else
            ant->left = leaf;
        
    }
    return 1;
}   
int removeleaf(bintree *raiz, int info){
    if(raiz == NULL) return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(info == atual->data){
            if(atual == *raiz)
                 *raiz = removeno(atual);
            else{
                if(ant->right == atual)
                    ant->right = removeno(atual);
                else
                    ant->left = removeno(atual);
            }
            return 1;
        }
        ant = atual;
        if(info > atual->data)
            atual = atual->right;
        else
            atual = atual->left;
    }
    return 1;  
}
struct NO* removeno(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->left == NULL){
        no2 = atual->right;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->left;

    while(no2->right != NULL){
        no1 = no2;
        no2 = no2->right;
    }

    if(no1 != atual){
        no1->right = no2->left;
        no2->left = atual->left;
    }
    no2->right = atual->right;
    free(atual);
    return no2;

}
int searchseed(bintree *raiz, int info){
    if(raiz==NULL)
        return 0;
    struct NO* atual = *raiz;
    
    while(atual != NULL){
        if(info == atual->data);
            return 1;
        if(info > atual->data)
            atual = atual->right;
        else
            atual = atual->left;
    }
    return 0;
}

//Arvore AVL

int AVLheight(struct NO* no){
     if(no == NULL)
        return -1;
    else
        return no->height; //ret2orna a altura
}

int balance(struct NO* no){
   return labs(AVLheight(no->left) - AVLheight(no->right)); //faz a conta do balanceamento e retorna mdoulo
}

int higher(int x, int y){ //compara nos
    if(x>y)
        return x;
    else
        return y;
}
void LLrotation(bintree *raiz){
    struct NO *no;
    
    no = (*raiz)->left; //no pega o da esquerda pra fazer a rotacao
    (*raiz)->left = no->right; // substitui pra onde o no apontava para raiz apontar
    no->right = (*raiz); // faz a rotacao

    //altura vira a maior altura entre 
    (*raiz)->height = higher(AVLheight((*raiz)->left), AVLheight((*raiz)->right))+1;
    
    no->height = higher(AVLheight(no->left), (*raiz)->height)+1;
    (*raiz) = no;
}
void RRrotation(bintree *raiz){
    struct NO *no;
    no = (*raiz)->right;
    (*raiz)->right = no->left;
    no->left = (*raiz);

    (*raiz)->height = higher(AVLheight((*raiz)->left), AVLheight((*raiz)->right))+1;
    no->height = higher(AVLheight(no->right), (*raiz)->height) + 1;
    (*raiz) = no;

}
void LRrotation(bintree *raiz){
    RRrotation(&(*raiz)->left);
    LLrotation(raiz);   
}
void RLrotation(bintree *raiz){
    LLrotation(&(*raiz)->right);
    RRrotation(raiz);   
}
int AVLinsert(bintree *raiz, int info){
    int res;
    if(*raiz == NULL){
        struct NO *leaf; 
        leaf = (struct NO*) malloc(sizeof(struct NO)); // cria a folha e atribui os dados
        
        if(leaf == NULL) //verifica aloc
            return 0;
        leaf->data = info;
        leaf->height = 0;
        leaf->left = NULL; // null pois sempre que coloca uma folha ela é a ultima
        leaf->right = NULL;
        *raiz = leaf;
        //printf("->valor inserido");
        return 1; // se chegar no ultimo elemento da arvore retorna 1 para dar inicio
    }
    struct NO *atual = *raiz;
    if(info < atual->data){ //pergunta se a info é esta a esquerda da raiz
        if((res = AVLinsert(&(atual->left), info)) == 1){ //chama recursividade para achar o ultimo no
            if(balance(atual) >= 2){ //calc fb
                if(info < (*raiz)->left->data){ // faz a rotacao a esquerda se tiver desbalanceado a esquerda 
                    LLrotation(raiz);
                }else{
                    LRrotation(raiz); // faz a rotacao a esquerda se tiver desbalanceado a direita
                }
            }
        }
    }else{ // se nao estava deslanceado a esquerda testamos a direita
        if(info > atual->data){
            if((res = AVLinsert(&(atual->right), info)) == 1){ // chama recursivdade para achar ultimo no
                if(balance(atual) >= 2){
                    if(info > (*raiz)->right->data){ //rotacao a direita se a arvores estiver debalanceada a direita
                        RRrotation(raiz);
                    }else{
                        RLrotation(raiz); // do contrario faz uma dupla
                    }
                }
            }   
        }else{
            printf("->Valor duplicado\n");
            return -1;
        }
    } 
    atual->height = higher(AVLheight(atual->left), AVLheight(atual->right))+1;
    return res;
 
}
int AVLremove(bintree *raiz, int info){
    if(*raiz == NULL){
        printf("->nao tem\n");
        printf("\n[Digite qualquer coisa para sair . . .]"); getchar();
        return 0;
    }
    int res;
    if(info< (*raiz)->data){ // se a info for menor ele vai pra esquerda ate achar e tirar o no
        if((res = AVLremove(&(*raiz)->left, info)) ==1){
            if(balance(*raiz)>=2){ // testa pra ver se ficou desbalanceada
                if(AVLheight((*raiz)->right->left)<=AVLheight((*raiz)->right->right))
                    RRrotation(raiz);
                else
                    RLrotation(raiz);
            }
        }

    }
    if(info > (*raiz)->data){ // testa se a info esta a direita
        if(balance(*raiz)>=2){ //testa desbalanceamento
            if(AVLheight((*raiz)->left->right) <= AVLheight((*raiz)->left->left))
                LLrotation(raiz);
            else
                LRrotation(raiz);    
        }
    }
    if((*raiz)->data == info){ // acha o valor e retira ele dando um free
        if((*raiz)->left == NULL || (*raiz)->right == NULL){
            struct NO *oldno = (*raiz);
            if((*raiz)->left != NULL)
                *raiz = (*raiz)->left;
            else
                *raiz = (*raiz)->right;
            free(oldno);
        }else{
            struct NO* temp = searchlowest((*raiz)->right);
            (*raiz)->data = temp->data;
            AVLremove(&(*raiz)->right, (*raiz)->data);
            if(balance(*raiz)>= 2){
                if(AVLheight((*raiz)->left->right)<=AVLheight((*raiz)->left->left))
                    LLrotation(raiz);
                else
                    RRrotation(raiz);
                
            }
        }
        return 1;
    }
    return res;
}
void TreePrint(bintree *raiz, int level, int height){
    if(raiz == NULL)
        return;
    if(level == 0){
        if(*raiz != NULL){
            while(level<height){ // print pra separaros niveis
                printf("->");
                level++;
            }
            printf("%d\n", (*raiz)->data);
        }
    }else if(level > 0){
        if((*raiz)->left != NULL){ // chama recursivamente ate encontrsr o nivel pedido
            TreePrint(&(*raiz)->left, level - 1, height); 
        }
        if((*raiz)->right != NULL){
            TreePrint(&(*raiz)->right, level - 1, height);
        }
    }


}
int AVLcheck(struct NO* raiz)
{
  int fb;

  if (raiz == NULL)
    return 1;

  if (!AVLcheck(raiz->left))
    return 0;
  if (!AVLcheck(raiz->right))
    return 0;

  fb = balance(raiz);
  if (fb > 1)
    return 0;
  else
    return 1;
}

