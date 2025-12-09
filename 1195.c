#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left, *right;
} Node;

Node* insert(Node *root, int value) {
    if (root == NULL) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void preorder(Node *root) {
    if (!root) return;
    printf(" %d", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf(" %d", root->value);
    inorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->value);
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int C, N, value;
    scanf("%d", &C);

    for (int i = 1; i <= C; i++) {
        scanf("%d", &N);

        Node *root = NULL;

        for (int j = 0; j < N; j++) {
            scanf("%d", &value);
            root = insert(root, value);
        }

        printf("Case %d:\n", i);

        printf("Pre.:");
        preorder(root);

        printf("\nIn..:");
        inorder(root);

        printf("\nPost:");
        postorder(root);

        printf("\n");

        if (i < C) printf("\n"); // linha em branco só entre casos

        freeTree(root);
    }

    return 0;
}