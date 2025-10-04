// Exercício 1180 usando alocação dinâmica
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *vet;
    int *p;
    int *menor;
    int posicao = 0;

    scanf("%d", &N);

    vet = (int *) malloc(N * sizeof(int));
    if (vet == NULL) {
        return 1;
    }

    for (p = vet; p < vet+ N; p++) {
        scanf("%d", p);
    }

    menor = vet;

    for (p = vet + 1; p < vet + N; p++) {
        if (*p < *menor) {
            menor = p;
            posicao = p - vet;
        }
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", posicao);

    free(vet);

    return 0;
}