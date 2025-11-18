#include <stdio.h>

int main(void) {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int fila[100];
        int frente = 0, tras = 0;

// Enfileira as cartas de 1 até n
        for (int i = 1; i <= n; i++)
            fila[tras++] = i;

        printf("Discarded cards:");
        int primeira = 1;

// Enquanto tiver mais de uma carta
        while (tras - frente > 1) {
// Descarta a carta do topo
            if (primeira) {
                printf(" %d", fila[frente++]);
                primeira = 0;
            } else {
                printf(", %d", fila[frente++]);
            }

// Move a próxima carta para o fim
            fila[tras++] = fila[frente++];
        }

        printf("\nRemaining card: %d\n", fila[frente]);
    }

    return 0;
}
