// Exercício 1180 usando vetores
#include <stdio.h>

int main() {
    int N;
    int vet[1000];
    int i;
    int menor, posicao;

    scanf("%d", &N);

// Leitura dos elementos do vetor
    for (i = 0; i < N; i++) {
        scanf("%d", &vet[i]);
    }

    menor = vet[0];
    posicao = 0;

// Percorrer o vetor para achar o menor e sua posição
    for (i = 1; i < N; i++) {
        if (vet[i] < menor) {
            menor = vet[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}