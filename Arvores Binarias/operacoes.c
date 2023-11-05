#include <stdlib.h>
#include <stdio.h>

/* sao definidas por nos */
typedef struct No {
    int dado;
    /* ponteiros para os elementos esq e dir */
    struct No *esq, *dir;
} No;

/* Percursos */

/* raiz -> esq -> dir */
void pre_ordem(No *raiz) {
    if(raiz != NULL) {
        printf("%d", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

/* esq -> raiz -> dir */
void em_ordem(No *raiz) {
    if(raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d", raiz->dado);
        em_ordem(raiz->dir);
    }
}

/* esq -> dir -> raiz */
void pos_ordem(No *raiz) {
    if(raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d", raiz->dado);
    }
}

/* altura */

int altura(No *raiz) {
    if(raiz == NULL) return -1;

    int alt_esq = altura(raiz->esq);
    int alt_dir = altura(raiz->dir);

    if(alt_esq < alt_dir) return alt_dir + 1;
    else return alt_esq + 1;
}

No *insere(No *raiz, No *esq, No *dir) {
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}

int main() {

    No *raiz = malloc(sizeof(No));
    raiz->dado = 1;

    No *esq = malloc(sizeof(No));
    esq->dado = 2;
    esq->dir = NULL;
    esq->esq = NULL;

    No *dir = malloc(sizeof(No));
    dir->dado = 3;
    dir->dir = NULL;
    dir->esq = NULL;

    raiz = insere(raiz, esq, dir);

    pre_ordem(raiz);
    printf("\n");
    em_ordem(raiz);
    printf("\n");
    pos_ordem(raiz);
    printf("\n");

    return 0;
}