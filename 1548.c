#include <stdio.h>
#include <stdlib.h>

int comp_desc(const void *a, const void *b) {
    // para qsort: ordenação decrescente
    int va = *(int*)a;
    int vb = *(int*)b;
    return vb - va;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);
        int original[1000];
        int ordenado[1000];

        int i;
        for (i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }

        qsort(ordenado, M, sizeof(int), comp_desc);

        int conta = 0;
        for (i = 0; i < M; i++) {
            if (original[i] == ordenado[i]) {
                conta++;
            }
        }

        printf("%d\n", conta);
    }

    return 0;
}