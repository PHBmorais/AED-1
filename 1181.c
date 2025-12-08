#include <stdio.h>

int main() {

    int L;
    char T;'
    double matriz[12][12];
    int i, j;
    double soma = 0.0;

    scanf("%d", &L);

    scanf(" %c", &T);

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    for (j = 0; j < 12; j++) {
        soma += matriz[L][j];
    }

    if (T == 'S') {
        printf("%.1lf\n", soma);
    }
    else if (T == 'M') {
        printf("%.1lf\n", soma / 12.0);
    }

    return 0;
}