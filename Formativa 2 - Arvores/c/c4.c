#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;


void pos_ordem(no *raiz) {
    if(raiz == NULL) return;

    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->dado);
}