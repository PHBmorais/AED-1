#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char dado;
    struct Node *prox;
};

void push(struct Node **topo, char valor) {
    struct Node *novo = (struct Node*) malloc(sizeof(struct Node));
    novo->dado = valor;
    novo->prox = *topo;
    *topo = novo;
}

void pop(struct Node **topo) {
    if (*topo != NULL) {
        struct Node *temp = *topo;
        *topo = (*topo)->prox;
        free(temp);
    }
}

int isEmpty(struct Node *topo) {
    return topo == NULL;
}

int main() {

    int N;
    char linha[1000];

    // Lê o número de casos
    scanf("%d", &N);

    // Consumir a quebra de linha após o número
    getchar();

    while (N--) {

        struct Node *pilha = NULL;
        int diamantes = 0;

        // Lê linha completa
        fgets(linha, sizeof(linha), stdin);

        for (int i = 0; linha[i] != '\0'; i++) {

            if (linha[i] == '<') {
                push(&pilha, '<');
            } 
            else if (linha[i] == '>') {
                if (!isEmpty(pilha)) {
                    pop(&pilha);
                    diamantes++;
                }
            }
        }

        // Limpar pilha
        while (!isEmpty(pilha)) {
            pop(&pilha);
        }

        printf("%d\n", diamantes);
    }

    return 0;
}