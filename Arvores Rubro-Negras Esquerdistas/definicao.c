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
REGRAS PARA ARORES RUBRO NEGRAS

Sao arvores binarias rubro-negras se:
    1- Todo no da arvore e preto ou vernmelho
    2- A raiz e preta
    3 - Se um no e vermelho seus filhos sao pretos
    4 - Em cada no, o caminho para qualquer um de seus
    filhos tem a mesma quantidade de nos pretos.
        a. O proprio filho nao conta.
        b. O filhos vermelho é sempre esquerdo.
    5- As folhas sao NULL e tem cor preta.
 */