#include <stdlib.h>
#include <stdio.h>

/* sao definidas por nos */
typedef struct No {
    int dado;
    /* ponteiros para os elementos esq e dir */
    struct No *esq, *dir;
} No;