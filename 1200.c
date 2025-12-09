#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char value;
    struct node *left, *right;
} Node;

Node* insert(Node *root, char value) {
    if (!root) {
        Node *n = malloc(sizeof(Node));
        n->value = value;
        n->left = n->right = NULL;
        return n;
    }
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

int search(Node *root, char value) {
    if (!root) return 0;
    if (root->value == value) return 1;
    if (value < root->value) return search(root->left, value);
    return search(root->right, value);
}

int first;

void printPre(Node *root) {
    if (!root) return;
    if (!first) printf(" %c", root->value);
    else { printf("%c", root->value); first = 0; }
    printPre(root->left);
    printPre(root->right);
}

void printIn(Node *root) {
    if (!root) return;
    printIn(root->left);
    if (!first) printf(" %c", root->value);
    else { printf("%c", root->value); first = 0; }
    printIn(root->right);
}

void printPost(Node *root) {
    if (!root) return;
    printPost(root->left);
    printPost(root->right);
    if (!first) printf(" %c", root->value);
    else { printf("%c", root->value); first = 0; }
}

int main() {
    Node *root = NULL;
    char cmd[10], value;

    while (scanf("%s", cmd) != EOF) {

        if (!strcmp(cmd, "I")) {
            scanf(" %c", &value);
            root = insert(root, value);
        }
        else if (!strcmp(cmd, "P")) {
            scanf(" %c", &value);
            if (search(root, value))
                printf("%c existe\n", value);
            else
                printf("%c nao existe\n", value);
        }
        else if (!strcmp(cmd, "PREFIXA")) {
            first = 1;
            printf("Pre: ");   // 👈 espaço após o dois pontos
            printPre(root);
            printf("\n");
        }
        else if (!strcmp(cmd, "INFIXA")) {
            first = 1;
            printf("In: ");    // 👈 espaço após o dois pontos
            printIn(root);
            printf("\n");
        }
        else if (!strcmp(cmd, "POSFIXA")) {
            first = 1;
            printf("Pos: ");   // 👈 espaço após o dois pontos
            printPost(root);
            printf("\n");
        }
    }

    return 0;
}