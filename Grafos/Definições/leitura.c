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

grafo *le_grafo() {
    int n, m, i, u, v;
    grafo *g; // grafo de retorno
    scanf("%d %d", &n, &m); // le o numero de vertices e arestas
    g = cria_grafo(n); // cria o grafo com n vertices
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v); // le cada aresta
        insere_aresta(g, u, v); // insere a aresta no grafo
    }

    return g;
}

void imprime_arestas(grafo *g) {
    int u, v;
    for(u = 0; u < g->n; u++) {
        for(v = u + 1; v <g->n; v++) {
            if(g->adj[u][v])
                printf("(%d, %d)\n", u, v); // imprime a aresta (u, v)
        }
    }
}