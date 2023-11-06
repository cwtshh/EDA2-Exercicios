#include <stdio.h>
#include <stdlib.h>

#define pai(i) (i - 1)/2


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

// troca i com j
void troca(int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

// se o filho for maior que o pai ele sobe no heap
void sobe_no_heap(FP *fp, int i) {
    if(i < 0 && fp->v[pai(i)] < fp->v[i]) {
        troca(fp->v, pai(i), i);
        sobe_no_heap(fp, pai(i));
    }
}

// insere no final e sobe no heap
void insere(FP *fp, int x) {
    fp->v[fp->n] = x;
    fp->n++;

    sobe_no_heap(fp, fp->n - 1);
}

// remove o ultimo elemento da lista
void remove(FP *fp) {
    troca(fp->v, 0, fp->n - 1);
    fp->n--;
    desce_no_heap(fp, 0);

    return fp->v[fp->n];
}

// desce ate a ultima posicao e troca com o maior filho
void desce_no_heap(FP *fp, int i) {
    int menor_filho, maior_filho, esq = i * 2 + 1, dir = i * 2 + 2;

    // se o esq esta dentro de n
    if(esq < fp->n) {
        menor_filho = esq;

        // se o dir esta dentro de n e dir for maior que esq
        if(dir < fp->n && fp->v[dir] > fp->v[esq]) {
            maior_filho = dir;
        }

        if(fp->v[i] < fp->v[maior_filho]) {
            troca(fp->v, i, maior_filho);
            desce_no_heap(fp, maior_filho);
        }
    }
}



// HEAP SORT

