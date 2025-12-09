#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int familiar[200000];

int encontrar(int x) {
    if (familiar[x] == x) {
        return x;
    }
    return familiar[x] = encontrar(familiar[x]);
}

void juntar(int a, int b) {
    a = encontrar(a);
    b = encontrar(b);
    if (a != b) familiar[b] = a;
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int m,n;
    int i;

    while (scanf("%d %d", &m, &n) == 2 && (m || n)) {
        Edge edges[n];
        long long total = 0;

        for (i = 0; i < m; i++) {
            familiar[i] = i;
        }
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total += edges[i].w;
        }

        qsort(edges, n, sizeof(Edge), cmp);

        long long mst = 0;

        for (int i = 0; i < n; i++) {
            if (encontrar(edges[i].u) != encontrar(edges[i].v)) {
                juntar(edges[i].u, edges[i].v);
                mst += edges[i].w;
            }
        }
        printf("%lld\n", total - mst);
    }
    return 0;
}