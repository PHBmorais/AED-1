#include <stdio.h>
#include <stdlib.h>

#define MAXV 26

int parent[MAXV];
int visited[MAXV];
int V, E;

int find_set(int x) {
    if (parent[x] != x) parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);
    if (pa != pb) {
        if (pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
    }
}

int cmp_char(const void *a, const void *b) {
    char ca = *(char*)a;
    char cb = *(char*)b;
    return (ca - cb);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &V, &E);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < E; i++) {
            char ca, cb;
            scanf(" %c %c", &ca, &cb);
            int a = ca - 'a';
            int b = cb - 'a';
            union_set(a, b);
        }

        // Para garantir pais atualizados
        for (int i = 0; i < V; i++) {
            parent[i] = find_set(i);
        }

        // Agrupar vértices por componente
        char comp[MAXV][MAXV + 1];
        int comp_sz[MAXV];
        for (int i = 0; i < V; i++) comp_sz[i] = 0;

        for (int i = 0; i < V; i++) {
            int p = parent[i];
            comp[p][comp_sz[p]++] = 'a' + i;
        }

        printf("Case #%d:\n", t);
        int comps = 0;
        for (int i = 0; i < V; i++) {
            if (comp_sz[i] > 0) {
                // ordenar as letras da componente
                qsort(comp[i], comp_sz[i], sizeof(char), cmp_char);
                for (int j = 0; j < comp_sz[i]; j++) {
                    printf("%c,", comp[i][j]);
                }
                printf("\n");
                comps++;
            }
        }
        printf("%d connected components\n\n", comps);
    }
    return 0;
}