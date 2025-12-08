#include <stdio.h>
#include <stdlib.h>

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
    return (topo == NULL);
}

int main() {
    char expressao[1000];

    while (scanf("%s", expressao) != EOF) {

        struct Node *pilha = NULL;
        int i = 0;
        int correto = 1;

        while (expressao[i] != '\0') {

            if (expressao[i] == '(') {
                push(&pilha, '(');
            }
            else if (expressao[i] == ')') {
                if (isEmpty(pilha)) {
                    correto = 0; // tem ')' sem '('
                    break;
                } else {
                    pop(&pilha);
                }
            }

            i++;
        }

        if (!isEmpty(pilha))
            correto = 0;

        while (!isEmpty(pilha))
            pop(&pilha);

        if (correto)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}