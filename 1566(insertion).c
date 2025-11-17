#include <stdio.h>

int main() {
    int NC, N, i, j, h;
    scanf("%d", & NC);

    while (NC--) {
        scanf("%d", &N);
        int v[N];

        for (i = 0; i < N; i++) {
            scanf("%d", &v[i]);
        }

        for (i = 1; i < N; i++) {
            h = v[i];
            j = i -1;

            while (j >= 0 && v[j] > h) {
            v[j + 1] = v[j];
            j--;
            }
        v[j + 1] = h;
        }
        for (i = 0; i < N; i++) {
        if (i > 0)
        printf("");
        printf("%d", v[i]);
        }
    printf("\n");
    }
}