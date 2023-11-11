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

    pilha *p = cria_pilha();
    pilha *p1 = cria_pilha();

    no *aux = raiz;
    no *last = NULL;

    while(!vazia(p)) {
        if(aux != NULL) {
            empilhar(p, aux);
            empilhar(p1, aux);
        } else {
            no *topo = p->dados[p->topo];

            if(topo->dir != NULL && topo->dir != last->dir) {
                aux = topo->dir;
            } else {
                printf("%d ", topo->dado);
                last = topo;
                desempilha(p);
            }
        }
    }
}