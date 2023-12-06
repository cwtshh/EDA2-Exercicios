#include <stdio.h>
#include <stdlib.h>
#include "grafos_lista.h"

int main() {
    Grafo *g = cria_grafo(10);


    insere_aresta(g, 0, 1);
    insere_aresta(g, 0, 2);
    insere_aresta(g, 2, 3);
    insere_aresta(g, 2, 4);
    insere_aresta(g, 3, 4);
    insere_aresta(g, 3, 5);
    insere_aresta(g, 4, 5);

    desenha_lista(g);

    destroi_grafo(g);

    return 0;
}