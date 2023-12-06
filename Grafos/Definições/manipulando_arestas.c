#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
    int **adj; // matriz de adjacencia
    int n; // numero de vertices
} grafo;

void insere_aresta(grafo *g, int u, int v) {
    g->adj[u][v] = 1; // insere a aresta (u, v)
    g->adj[v][u] = 1; // insere a aresta (v, u)
}

void remove_aresta(grafo *g, int u, int v) {
    g->adj[u][v] = 0; // remove a aresta (u, v)
    g->adj[v][u] = 0; // remove a aresta (v, u)
}

int tem_aresta(grafo *g, int u, int v) {
    return g->adj[u][v]; // retorna 1 se existe a aresta (u, v) e 0 caso contrario
}