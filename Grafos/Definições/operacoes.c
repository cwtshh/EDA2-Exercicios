#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
    int **adj; // matriz de adjacencia
    int n; // numero de vertices
} grafo;


grafo *cria_grafo(int n) {
    int i, j;
    grafo *g = (grafo *) malloc(sizeof(grafo)); // aloca memoria para o grafo
    g->n = n; // atribui o numero de vertices
    g->adj = (int **) malloc(n * sizeof(int *)); // aloca memoria para as linhas da matriz
    for(i = 0; i < n; i++) {
        g->adj[i] = malloc(n * sizeof(int)); // aloca memoria para as colunas da matriz
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            g->adj[i][j] = 0; // inicializa a matriz com 0
        }
    }

    return g;
}

void destroi_grafo(grafo *g) {
    int i;
    for(i = 0; i < g->n; i++) {
        free(g->adj[i]); // libera as colunas da matriz
    }
    free(g->adj); // libera as linhas da matriz
    free(g); // libera a memoria do grafo
}

