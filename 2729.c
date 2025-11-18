#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vamos chamar o nó de bloco //
typedef struct bloco {
    char produto[21]; // Nome do produto (máximo de 20 caracteres + '\0') //
    struct bloco *proximo;     // Ponteiro para o próximo bloco //
} bloco;

// Função para adicionar um produto em ordem na lista, sem duplicatas
void adc_produto(bloco **cabeca, const char *novo_produto) {
    // Criar um novo bloco //
    bloco *novo = malloc(sizeof(bloco));
    strcpy(novo->produto, novo_produto);
    novo->proximo = NULL;

    bloco *atual = *cabeca;
    bloco *anterior = NULL;

    // Encontrar a posição correta para inserir o produto //
    while (atual != NULL && strcmp(atual->produto, novo_produto) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Verificar se o produto já existe na lista //
    if (atual != NULL && strcmp(atual->produto, novo_produto) == 0) {
        free(novo); // Liberar a memória do produto duplicado //
        return;
    }

    // Inserir o produto na posição correta //
    if (anterior == NULL) {
        // Inserir no início da lista //
        novo->proximo = *cabeca;
        *cabeca = novo;
    } else {
        // Inserir entre 'anterior' e 'atual' //
        anterior->proximo = novo;
        novo->proximo = atual;
    }
}

// Função para imprimir os produtos da lista //
void imprimir_lista(bloco *cabeca) {
    bloco *atual = cabeca;
    while (atual != NULL) {
        printf("%s", atual->produto);
        if (atual->proximo != NULL) {
            printf(" "); // Imprime um espaço entre os produtos //
        }
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para liberar a memória ocupada pela lista //
void liberar_lista(bloco *cabeca) {
    bloco *atual = cabeca;
    while (atual != NULL) {
        bloco *temporario = atual;
        atual = atual->proximo;
        free(temporario); // Liberar memória do bloco atual //
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // Consumir o \n após o número //

    for (int i = 0; i < n; i++) {
        char linha[1000 * 21];
        fgets(linha, sizeof(linha), stdin);

        // Remover o \n da linha //
        linha[strcspn(linha, "\n")] = '\0';

        // Inicializar a lista encadeada //
        bloco *lista = NULL;

        // Dividir a linha em itens //
        char *token = strtok(linha, " ");
        while (token != NULL) {
            adc_produto(&lista, token);
            token = strtok(NULL, " ");
        }

        // Imprimir a lista ordenada e duplicados //
        imprimir_lista(lista);

        // Liberar a memória da lista //
        liberar_lista(lista);
    }

    return 0;
}
