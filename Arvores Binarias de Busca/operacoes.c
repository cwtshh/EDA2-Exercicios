#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;


// recebe uma arvore
// um numero (ch)
// retorna um ponteiro para o no que contem o numero (ch)
// ou NULL caso nao exista
No *busca(No *raiz, int ch) {
    if(raiz == NULL || raiz->dado == ch) {
        return raiz;
    }

    // se o dado for maior que o dado da raiz
    if(raiz->dado < ch) {
        // busca na subarvore direita
        return busca(raiz->dir, ch);
    } else {
        // caso contrario
        // busca na subarvore esquerda
        return busca(raiz->esq, ch);
    }
}

// recebe uma arvore
// recebe uma chave
No *insere(No *raiz, int ch) {
    // se a arvore estiver vazia
    // procura a posicao NULL da arvore
    if(raiz == NULL) {
        // cria um novo no
        No *novo = malloc(sizeof(No));
        novo->dado = ch;
        novo->esq = novo->dir = NULL;

        return novo;
    }

    // se o dado for maior que o dado da raiz
    if(raiz->dado < ch) {
        // insere na subarvore direita
        raiz->dir = insere(raiz->dir, ch);
    } else {
        // caso contrario
        raiz->esq = insere(raiz->esq, ch);
    }

    return raiz;
}

void em_ordem(No *raiz) {
    if(raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d ,", raiz->dado);
        em_ordem(raiz->dir);
    }
}

int main() {
    No *raiz = NULL;

    raiz = insere(raiz, 10);

    insere(raiz, 5);
    insere(raiz, 15);
    insere(raiz, 3);
    insere(raiz, 7);
    insere(raiz, 12);
    insere(raiz, 20);

    em_ordem(raiz);

    return 0;
}