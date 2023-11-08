#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha {
    no *dados[50];
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
    if(p->topo == 49) {
        return;
    }

    p->topo++;
    p->dados[p->topo] = dado;
}

no *desempilha(pilha *p) {
    if(vazia(p)) return NULL;

    return p->dados[p->topo--];
}

void pre_ordem(no *raiz) {
    if(raiz == NULL) return;

    pilha *p = cria_pilha();
    empilhar(p, raiz);

    while(!vazia(p)) {
        no *aux = desempilha(p);
        printf("%d ", aux->dado);

        if(aux->dir != NULL) {
            empilhar(p, aux->dir);
        }

        if(aux->esq != NULL) {
            empilhar(p, aux->esq);
        }
    }
}

