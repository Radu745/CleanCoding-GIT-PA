#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} NODE;

typedef struct Graph {
    int v;
    int *vis;
    NODE **alst;
} GPH;

NODE *create_node(int v) {
    NODE *nn = malloc(sizeof(NODE));
    nn->data = v;
    nn->next = NULL;
    return nn;
}

GPH *create_g(int v) {
    GPH *g = malloc(sizeof(GPH));
    g->v = v;
    g->alst = malloc(v * sizeof(NODE *));
    g->vis = malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        g->alst[i] = NULL;
        g->vis[i] = 0;
    }
    return g;
}

void add_edge(GPH *g, int src, int dest) {
    NODE *nn = create_node(dest);
    nn->next = g->alst[src];
    g->alst[src] = nn;

    nn = create_node(src);
    nn->next = g->alst[dest];
    g->alst[dest] = nn;
}

void insert_edges(GPH *g, int edg_nr) {
    int src, dest;
    printf("Adauga %d muchii (de la 0 la %d):\n", edg_nr, g->v - 1);
    for (int i = 0; i < edg_nr; i++) {
        scanf("%d%d", &src, &dest);
        add_edge(g, src, dest);
    }
}

int drum_direct(GPH *g, int src, int dest) {
    NODE *cur = g->alst[src];
    while (cur != NULL) {
        if (cur->data == dest) return 1;
        cur = cur->next;
    }
    return 0;
}

int main() {
    int nrv, edg_nr;
    int src, dest;

    printf("Cate noduri are graful? ");
    scanf("%d", &nrv);

    printf("Cate muchii are graful? ");
    scanf("%d", &edg_nr);

    GPH *g = create_g(nrv);
    insert_edges(g, edg_nr);

    printf("Introdu doua noduri pentru a verifica daca exista drum direct intre ele:\n");
    scanf("%d%d", &src, &dest);

    if (drum_direct(g, src, dest))
        printf("Exista drum direct intre %d si %d.\n", src, dest);
    else
        printf("NU exista drum direct intre %d si %d.\n", src, dest);

    return 0;
}
