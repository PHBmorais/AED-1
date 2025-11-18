#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        int ordemF[1000];

        while (1) {
            scanf("%d", &ordemF[0]);
            if (ordemF[0] == 0) {
                break;
            }

            for (int i = 1; i < N; i++) {
                scanf("%d", &ordemF[i]);
            }

            int pilha[1000], topo = -1;
            int atual = 1;
            int possivel = 1;

            for (int i = 0; i < N; i++) {
                int objetivo = ordemF[i];

                while (atual <= objetivo) {
                    pilha[++topo] = atual++;
                }

                if (pilha[topo] != objetivo) {
                    possivel = 0;
                    break;
                }

                topo--;
            }

            if (possivel)
                printf("Yes\n");
            else
                printf("No\n");
        }

        printf("\n");
    }

return 0;
}