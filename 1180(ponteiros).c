// Exercício 1180 usando ponteiros
// Temos 2 ponteiros uma para percorrer o vetor e outro para apontar para o menor elemento
#include <stdio.h>

int main() {
    int N;
    int vet[1000];
    int *p;
    int *menor;
    int posicao = 0;

    scanf("%d", &N);

// Leitura dos elementos
    for (p = vet; p < vet + N; p++) {
        scanf("%d", p);
    }

// o ponteiro aponta para o primeiro elemento
    menor = vet;

// Percorrer o vetor com ponteiro
    for (p = vet + 1; p < vet + N; p++) {
        if (*p < *menor) {
            menor = p;
            posicao = p - vet;
        }
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
