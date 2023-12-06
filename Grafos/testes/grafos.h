#ifndef grafos_h
#define grafos_h
#include <stdio.h>
#include <stdlib.h>


typedef struct grafo {
    int **adj;
    int n;
} grafo;

grafo *cria_grafo(int n) {
    grafo *g = (grafo *) malloc(sizeof(grafo));
    g->n = n;
    g->adj = (int **) malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++) {
        g->adj[i] = (int *) malloc(sizeof(int) * n);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void destroi_grafo(grafo *g) {
    for(int i = 0; i < g->n; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

void insere_aresta(grafo *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void imprime_arestas(grafo *g) {
    for(int u = 0; u < g->n; u++) {
        for(int v = u + 1; v < g->n; v++) {
            if(g->adj[u][v]) {
                printf("%d-%d\n", u, v);
            }
        }
    }
}

void imprime_matriz_completa(grafo *g) {
    printf("  ");
    for(int k = 0; k < g->n; k++) {
        printf("| %d |", k);  
    }
    printf("\n");
    for(int i = 0; i < g->n; i++) {
        printf("%d ", i);
        for(int j = 0; j < g->n; j++) {
            //printf("  %d  ", j);
            printf("| %d |", g->adj[i][j]);
        }
        printf("\n");
    }
}

int tem_aresta(grafo *g, int u, int v) {
    return g->adj[u][v];
}



#endif