#include <stdlib.h>
#include <stdio.h>

enum cor {
    PRETO,
    VERMELHO
};

typedef struct No {
    int dado;
    struct No *esq, *dir;
    enum cor cor;
} No;


/* 
Operacao de correcao

    - Rotacao
    - Elevacao de cor

    Problemas encontrados:
        1- Raiz com filho esquerdo preto e direito vermelho
            - Rotacao a esquerda

        2- Raiz com 2 filhos vermelhos
            - Sobe cor.

        3- Raiz preta com filho esquerdo e neto mais a esquerda vermelhos
            - Rotacao a direita
*/      

/* correcoes */
void sobe_cor(No *raiz) {
    /* a raiz fica vermelha */
    raiz->cor = VERMELHO;

    /* os filhos ficam pretos */
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

No *rotacao_esquerda(No *raiz) {
    /* 
        1- guarda o filho direito
        2- troca o filho esq pelo dir do dir
        3- aux recebe a cor da raiz
        4- aux recebe a raiz a esq
        5- raiz fica vermelha
        6- retorna a nova raiz
    */
    No *aux = raiz->dir;
    raiz->esq = aux->dir;
    aux->cor = raiz->cor;
    aux->esq = raiz;
    raiz->cor = VERMELHO;    

    return aux;
}

No *rotacao_direita(No *raiz) {
    /* 
        1- guarda o filho a esq
        2- troca o filho a dir pelo filho a esq do esq
        3- aux recebe a cor da raiz
        4- aux recebe a raiz a dir
        5- raiz fica vermelha
        6- retorna a nova raiz   
    */
    No *aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    aux->cor = raiz->cor;
    raiz->cor = VERMELHO;

    return aux;
}

// funcao para corrigir todos os casos
No *corrige(No *raiz) {
    if(raiz->esq != NULL && raiz->dir != NULL) {
        // raiz direita vermelha
        if(raiz->esq->cor == PRETO && raiz->dir->cor == VERMELHO) {
            return rotacao_esquerda(raiz);
        }

        // dois filhos vermelhos
        if(raiz->esq->cor == VERMELHO && raiz->dir->cor == VERMELHO) {
            sobe_cor(raiz);
            return raiz;
        }
    }

    if(raiz->esq != NULL && raiz->esq->esq != NULL) {
        // dois filhos vermelhos seguidos
        if(raiz->esq->esq->cor == VERMELHO && raiz->esq->cor == VERMELHO) {
            raiz = rotacao_direita(raiz);
            sobe_cor(raiz);
            return raiz;
        }
    }

}



// funcao de inserir
// recebe uma arvore
// recebe uma chave a ser inserida
// retorna uma arvore
No *insere_rec(No *raiz, int ch) {
    // se a raiz for nula, cria um novo elemento
    if(raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->dado = ch;
        novo->cor = VERMELHO;

        return novo;
    }

    // se a chave for menor q a raiz
    // procura uma posicao nula a esquerda
    // insere um novo no
    if(ch < raiz->dado) raiz->esq = insere_rec(raiz->esq, ch);

    // se a chave for maior que a raiz
    // procura uma posicao nula a direita
    // insere um novo no
    else raiz->dir = insere_rec(raiz->dir, ch);

    // corrige os nos da raiz a cada insercao
    return corrige(raiz);
}

No *insere(No *raiz, int ch) {
    // insere com a funcao insere_rec()
    raiz = insere_rec(raiz, ch);
    // garante que a raiz sempre sera preta
    if(raiz) raiz->cor = PRETO;
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
    raiz = insere(raiz, 6);
    insere(raiz, 4);
    insere(raiz, 3);
    insere(raiz, 5);
    insere(raiz, 7);
    insere(raiz, 8);
    insere(raiz, 9);


    // mostra_arvore(raiz, 1);
    printf("raiz: %d\n", raiz->dado);
    printf("esq: %d\n", raiz->esq->dado);
    printf("dir: %d\n", raiz->dir->dado);
    

    return 0;
}