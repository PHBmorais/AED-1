#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Amigo {
    char nome[40];
    struct Amigo *proximo;
} Amigo;

// Função para criar um novo amigo //
Amigo *criaAmigo(const char *nome) {
    Amigo *novo = (Amigo *)malloc(sizeof(Amigo));
    strcpy(novo->nome, nome);
    novo->proximo = NULL;
    return novo;
}

// Função para adicionar um novo amigo ao final da lista //
void adcFinalLista(Amigo **lst, const char *nome) {
    Amigo *novo = criaAmigo(nome);
    if (*lst == NULL) {
        *lst = novo;
    } else {
        Amigo *temp = *lst;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

// Função para adicionar uma lista antes do nome determinado //
void adcAntesAmigo(Amigo **lst, const char *antesAmigo, Amigo *novaLista) {
    if (*lst == NULL) return;

    if (strcmp((*lst)->nome, antesAmigo) == 0) {
        Amigo *temporario = novaLista;
        while (temporario->proximo != NULL) {
            temporario = temporario->proximo;
        }
        temporario->proximo = *lst;
        *lst = novaLista;
        return;
    }

    Amigo *atual = *lst;
    while (atual->proximo != NULL && strcmp(atual->proximo->nome, antesAmigo) != 0) {
        atual = atual->proximo;
    }
   
    if (atual->proximo != NULL) {
        Amigo *temporario = novaLista;
        while (temporario->proximo != NULL) {
            temporario = temporario->proximo;
        }
        temporario->proximo = atual->proximo;
        atual->proximo = novaLista;
    }
}

// Função para exibir a lista de amigos sem espaço extra no final //
void exibeLista(Amigo *lst) {
    Amigo *temporario = lst;
    int primeiro = 1; // Controla se é o primeiro nome //
    while (temporario != NULL) {
        if (!primeiro) printf(" "); // Adiciona espaço apenas após o primeiro nome //
        printf("%s", temporario->nome);
        primeiro = 0;
        temporario = temporario->proximo;
    }
    printf("\n");
}

// Libera a memória alocada para a lista //
void liberaLista(Amigo *lst) {
    Amigo *temporario;
    while (lst != NULL) {
        temporario = lst;
        lst = lst->proximo;
        free(temporario);
    }
}

int main() {
    char linha[250];
   
    gets(linha);
    Amigo *lstAmigos = NULL;
    char *nome = strtok(linha, " ");
    while (nome != NULL) {
        adcFinalLista(&lstAmigos, nome);
        nome = strtok(NULL, " ");
    }
   
    gets(linha);
    Amigo *novaLSTAmigos = NULL;
    nome = strtok(linha, " ");
    while (nome != NULL) {
        adcFinalLista(&novaLSTAmigos, nome);
        nome = strtok(NULL, " ");
    }
   
    gets(linha);
   
    if (strcmp(linha, "nao") == 0) {
        Amigo *temporario = novaLSTAmigos;
        while (temporario != NULL) {
            adcFinalLista(&lstAmigos, temporario->nome);
            temporario = temporario->proximo;
        }
    } else {
        adcAntesAmigo(&lstAmigos, linha, novaLSTAmigos);
    }
   
    exibeLista(lstAmigos);

    liberaLista(lstAmigos);
    liberaLista(novaLSTAmigos);
   
    return 0;
}