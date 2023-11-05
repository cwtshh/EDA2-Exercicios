#include <stdio.h>
#include <stdlib.h>

enum cor {
    PRETO,
    VERMELHO
};

typedef struct No {
    int dado;
    struct No *esq, *dir;
    enum cor cor;
} No;

int e_vermelho(No *raiz) {
    if(!raiz) return -1;

    return raiz->cor == VERMELHO;
}

int e_preto(No *raiz) {
    if(!raiz) return -1;

    return raiz->cor == PRETO;
}

No *rota_esquerda(No *raiz) {
    No *aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    aux->cor = raiz->cor;
    raiz->cor = VERMELHO;

    return aux;
}


No *rota_direita(No *raiz) {
    No *aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    aux->cor = raiz->cor;
    raiz->cor = VERMELHO;

    return aux;
}

void sobe_cor(No *raiz) {
    /* a raiz fica vermelha */
    raiz->cor = VERMELHO;

    /* os filhos ficam pretos */
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

No *insere_rubro(No *raiz, int ch) {
    if(raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->dado = ch;
        novo->cor = VERMELHO;
        novo->esq = novo->dir = NULL;

        return novo;
    }

    // procura posicao correta e disponivel

    // para a esquerda
    if(raiz->dado > ch) {
        raiz->esq = insere_rubro(raiz->esq, ch);
    } else {
        // para direita
        raiz->dir = insere_rubro(raiz->dir, ch);
    }

    // se a direita for vermelha e a esquerda for preta
    if(e_vermelho(raiz->dir) && e_preto(raiz->esq)) {
        raiz = rota_esquerda(raiz);
        return raiz;
    }

    if(e_vermelho(raiz->esq) && e_vermelho(raiz->esq->esq)) {
        raiz = rota_direita(raiz);
        return raiz;
    }

    if(e_vermelho(raiz->esq) && e_vermelho(raiz->dir)) {
        sobe_cor(raiz);
    }

    return raiz;
}

No *busca(No *raiz, int ch) {
    if(raiz == NULL || raiz->dado == ch) {
        return raiz;
    }

    if(raiz->dado < ch) {
        return busca(raiz->dir, ch);
    } else {
        return busca(raiz->esq, ch);
    }
}

void em_ordem(No *raiz) {
    if(raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        em_ordem(raiz->dir);
    }
}


int main() {
    No *raiz = NULL;

    raiz = insere_rubro(raiz, 10);
    raiz = insere_rubro(raiz, 5);
    raiz = insere_rubro(raiz, 12);

    em_ordem(raiz);

    printf("\n");
    printf("%d", busca(raiz, 12)->dado);

    return 0;
}