#include <stdio.h>
#include <stdlib.h>

/* 
Uma fila de prioridade e uma estrutura de dados que possui duas operacoes

-> insercao
-> remocao do elemento de maior prioridade

Ex:
    filas
    pilhas


considere que desejamos remover o maior elemento do conjunto. para isso usamos
uma arvore hierarquica ou max heap.

max-heap e uma arvore binaria quase completa na qual a raiz de qualquer subarvore
possui chave maior que seus filhos.

uma arvore binaria e dita quase completa se todos os nos estao cheio com excessao
do ultimo, e os nos do ultimo nivel estao mais a esquerda

Ex:

                        10
                9               4
        7           8        3      2
    6     4       5   1
*/

// implementacao


// Pai de v[i] => v[(1 - 1)/2]

// filho esq de v[i] => v[i * 2 + 1]

// filho direito de v[i] => v[i * 2 + 2]

typedef struct {
    int *v;
    int n, tam;
} FP;

FP *cria_heap(int tam) {
    FP *fp = malloc(sizeof(FP));
    fp->v = malloc(tam * sizeof(int));
    fp->tam = tam;
    fp->n = 0;

    return fp;
}
