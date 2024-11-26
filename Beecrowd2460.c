// N é a quantidade de pessoas inicial da fila //
// M é a quantidade de pessoas que sairam da fila //

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int maxID = 100000;

    int N, M;

    scanf("%d", &N);

    int fila[N];

    // Laço para ler os identificadores das pessoas que estavam na fila inicial //
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);

    int sairam[M];

    // Laço para ler os identificadores das pessoas que saíram da fila //
    for (int i = 0; i < M; i++) {
        scanf("%d", &sairam[i]);
    }

    int saiu[maxID + 1]; // O índice do vetor será o identificador, e o valor 1 indica que a pessoa saiu //
    for (int i = 0; i <= maxID; i++) {
        saiu[i] = 0;
    }

    // Marca as pessoas que sairam da fila //
    for (int i = 0; i < M; i++) {
        saiu[sairam[i]] = 1; // Marca como 1 as pessoas que saíram //
    }

    // Agora vamos imprimir os identificadores das pessoas que ficaram na fila
    for (int i = 0; i < N; i++) {
        if (saiu[fila[i]] == 0) { // Se a pessoa não saiu da fila imprime o identificador da pessoa //
            printf("%d ", fila[i]);
        }
    }

    printf("\n"); // Nova linha após imprimir os identificadores restantes
    
    return 0;
}