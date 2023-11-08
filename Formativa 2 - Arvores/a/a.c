#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilhaNo {
    no *node;
    struct fila *prox;
} pilhaNo;

typedef struct pilha {
    no *dado[100];
    int topo;
} pilha;

pilha *cria_pilha() {
    pilha *p = malloc(sizeof(pilha));
    p->topo = -1;

    return p;
}

bool vazia(pilha *p) {
    return p->topo == -1;
}

void empilhar(pilha *p, no *dado) {
    if(p->topo == 99) {
        return;
    }

    p->topo++;
    p->dado[p->topo] = dado;
}

no *desempilha(pilha *p) {
    if(vazia(p)) return NULL;

    return p->dado[p->topo--];
}

void pre_ordem(no *raiz) {
    if(raiz == NULL) return;

    pilha *p = cria_pilha();
    empilhar(p, raiz);

    while(!vazia(p) && p != NULL) {
        no *atual = desempilha(p);
        if(atual == NULL) return;

        printf("%d ", atual->dado);

        if(atual->dir != NULL) {
            empilhar(p, atual->dir);
        }

        if(atual->esq != NULL) {
            empilhar(p, atual->esq);
        }
    }

    free(p);
}

int main() {
    no *raiz = malloc(sizeof(no));
    raiz->dado = 2;
    
    raiz->esq = malloc(sizeof(no));
    raiz->esq->dado = 5;

    raiz->esq->esq = malloc(sizeof(no));
    raiz->esq->esq->dado = 3;

    raiz->esq->dir = malloc(sizeof(no));
    raiz->esq->dir->dado = 8;

    raiz->esq->dir->esq = malloc(sizeof(no));
    raiz->esq->dir->esq->dado = 4;

    raiz->dir = malloc(sizeof(no));
    raiz->dir->dado = 7;

    raiz->dir->esq = malloc(sizeof(no));
    raiz->dir->esq->dado = 1;

    raiz->dir->esq->dir = malloc(sizeof(no));
    raiz->dir->esq->dir->dado = 9;

    raiz->dir->dir = malloc(sizeof(no));
    raiz->dir->dir->dado = 6;

    pre_ordem(raiz);

    return 0;
}
