#include <stdio.h>
#include <string.h>

#define MAX 1000

int grafo[MAX][MAX];
int grau[MAX];
int visitado[MAX];
int total;

// dfs = depth first search
void dfs(int v) {
    visitado[v] = 1;

    for (int i = 0; i < grau[v]; i++) {
        int u = grafo[v][i];

        if (!visitado[u]) {
            total+= 2;
            dfs(u);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int inicio, N, M;
        scanf("%d %d %d", &inicio, &N, &M);

        for (int i = 0; i < N; i++) {
            grau[i] = 0;
            visitado[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            grafo[A][grau[A]++] = B;
            grafo[B][grau[B]++] = A;
        }

        total = 0;
        dfs(inicio);

        printf("%d\n", total);
    }

return 0;
}