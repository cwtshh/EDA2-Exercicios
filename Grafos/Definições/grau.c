#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
    int **adj; // matriz de adjacencia
    int n; // numero de vertices
} grafo;

int grau(grafo *g, int u) {
    int v, grau = 0;
    for(v = 0; v < g->n; v++) { // percorre todos os vertices
        if(g->adj[u][v]) // se existe a aresta (u, v)
            grau++;
    }
    return grau;
}

int mais_popular( grafo *g) {
    int u, max, grau_max, grau_atual;
    max = 0;
    grau_max = grau(g, 0);
    for(u = 1; u < g->n; u++) {
        grau_atual = grau(g, u); // calcula o grau do vertice atual
        if(grau_atual > grau_max) { // se o grau atual for maior que o grau maximo
            max = u; // atualiza o vertice mais popular
            grau_max = grau_atual; // atualiza o grau maximo
        }
    }
    return max;
}