#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int vertice;
    struct No *prox;
}No;

typedef struct Grafo {
    int n;
    No *adj;
} Grafo;

Grafo *cria_grafo(int n) {
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    g->n = n;
    g->adj = (No *) malloc(n * sizeof(No));
    for(int i = 0; i < g->n; i++) {
        g->adj[i].vertice = i;
        g->adj[i].prox = NULL;
    }
    return g;
}

void destroi_lista(No *lista) {
    if(lista == NULL) return;
    destroi_lista(lista->prox);
    free(lista);
}

void destroi_grafo(Grafo *g) {
    for(int i = 0; i < g->n; i++) {
        destroi_lista(g->adj[i].prox);
    }
    free(g->adj);
    free(g);
}

void insere_aresta(Grafo *g, int u, int v) {
    No *novo = (No *) malloc(sizeof(No));
    novo->vertice = v;
    novo->prox = g->adj[u].prox;
    g->adj[u].prox = novo;

    novo = (No *) malloc(sizeof(No));
    novo->vertice = u;
    novo->prox = g->adj[v].prox;
    g->adj[v].prox = novo;
}

void remove_aresta(Grafo *g, int v) {
    if(g == NULL) return;

    No *aux = g->adj[v].prox;
    while(aux != NULL) {
        if(aux->vertice == v) {
            g->adj[v].prox = aux->prox;
            free(aux);
            break;
        }
    }
}

int tem_aresta(Grafo *g, int u, int v) {
    No *aux = g->adj[u].prox;
    while(aux != NULL) {
        if(aux->vertice == v) return 1;
    }
    return 0;
}

void imprime_arestas(Grafo *g) {
    for(int i = 0; i < g->n; i++) {
        No *aux = g->adj[i].prox;
        while(aux != NULL) {
            if(aux->vertice > i) printf("%d %d\n", i, aux->vertice);
            aux = aux->prox;
        }
    }
}

void desenha_lista(Grafo *g) {
    for(int i = 0; i < g->n; i++) {
        printf("%d: ", g->adj[i].vertice);
        No *aux = g->adj[i].prox;
        while(aux != NULL) {
            printf("%d ", aux->vertice);
            aux = aux->prox;
        }
        printf("\n");
    }
}



