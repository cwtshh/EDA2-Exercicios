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

void pos_ordem(no *raiz) {
    if(raiz == NULL) return;

    pilha *p1, *p2;
    p1 = cria_pilha();
    p2 = cria_pilha();
    empilhar(p1, raiz);
    no *node;

    while(!vazia(p1)) {
        node = desempilha(p1);
        empilhar(p2, node);

        if(node->esq != NULL) {
            empilhar(p1, node->esq);
        }

        if(node->dir != NULL) {
            empilhar(p1, node->dir);
        }
    }

    while(!vazia(p2)) {
        node = desempilha(p2);
        printf("%d ", node->dado);
    }

    free(p1);
    free(p2);
}