#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
    int **adj; // matriz de adjacencia
    int n; // numero de vertices
} grafo;

void imprime_recomendacoes(grafo *g, int u) {
    int v; // vertice atual 
    int w; // vertice adjacente a v

    for(v = 0; v < g->n; v++) { // percorre todos os vertices
        if(g->adj[u][v]) { // se existe a aresta (u, v)
            for(w = 0; w < g->n; w++) { // percorre todos os vertices
                if(g->adj[v][w] && !g->adj[u][w]) { // se existe a aresta (v, w) e nao existe a aresta (u, w)
                    printf("%d ", w); // imprime o vertice w
                }
            }
        }
    }
}