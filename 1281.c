#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        char product[60];
        double price;
        char products[60][60];
        double prices[60];

        // Lê os produtos e seus preços
        for (int i = 0; i < N; i++) {
            scanf("%s %lf", products[i], &prices[i]);
        }

        int M;
        scanf("%d", &M);

        double total = 0.0;

        // Lê os produtos comprados
        for (int i = 0; i < M; i++) {
            int qty;
            scanf("%s %d", product, &qty);

            // Procura o produto e soma o valor
            for (int j = 0; j < N; j++) {
                if (strcmp(product, products[j]) == 0) {
                    total += prices[j] * qty;
                    break;
                }
            }
        }

        printf("R$ %.2f\n", total);
    }

    return 0;
}