#ifndef _TREEHEADER_H
#define _TREEHEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NO* bintree;
bintree* planttree();

//ArvoreBinaria
void cuttree(bintree *raiz);
void burnseeds(struct NO* no);
int notplanted(bintree *raiz);
int treeheight(bintree *raiz);
int totalnots(bintree *raiz);
void preorder(bintree *raiz);
void inorder(bintree *raiz);
void posorder(bintree *raiz);
int insertleaf(bintree *raiz, int info);
int removeleaf(bintree *raiz, int info);
struct NO* removeno(struct NO* atual);
int searchseed(bintree *raiz, int info);

//AVL
struct NO* searchlowest(struct NO* atual);
int AVLheight(struct NO* no);
int balance(struct NO* no);
int higher(int x, int y);
void LLrotation(bintree *raiz);
void RRrotation(bintree *raiz);
void LRrotation(bintree *raiz); 
void RLrotation(bintree *raiz); 
int AVLinsert(bintree *raiz, int info);
int AVLremove(bintree *raiz, int info);
void TreePrint(bintree *raiz, int level, int height);
int AVLcheck(struct NO* raiz);


#endif