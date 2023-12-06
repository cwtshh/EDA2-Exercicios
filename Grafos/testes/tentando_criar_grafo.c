#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
    grafo *g = cria_grafo(10);

    imprime_matriz_completa(g);

    destroi_grafo(g);

    return 0;
}
