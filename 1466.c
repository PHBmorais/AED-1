#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, int val){
    if(root == NULL){
        Node* n = (Node*)malloc(sizeof(Node));
        n->val = val;
        n->left = n->right = NULL;
        return n;
    }
    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

typedef struct Queue{
    Node* nodes[510]; // até 500 níveis, seguro
    int front, rear;
} Queue;

void initQueue(Queue* q){
    q->front = 0;
    q->rear = 0;
}

int empty(Queue* q){
    return q->front == q->rear;
}

void push(Queue* q, Node* n){
    q->nodes[q->rear++] = n;
}

Node* pop(Queue* q){
    return q->nodes[q->front++];
}

int main(){
    int C;
    scanf("%d",&C);
    for(int t=1; t<=C; t++){
        int N;
        scanf("%d",&N);
        Node* root = NULL;
        for(int i=0;i<N;i++){
            int x;
            scanf("%d",&x);
            root = insert(root, x);
        }

        // BFS
        Queue q;
        initQueue(&q);
        push(&q, root);

        printf("Case %d:\n", t);
        int first = 1;
        while(!empty(&q)){
            Node* cur = pop(&q);
            if(first){ printf("%d", cur->val); first=0; }
            else printf(" %d", cur->val);

            if(cur->left) push(&q, cur->left);
            if(cur->right) push(&q, cur->right);
        }
        printf("\n\n");
    }
    return 0;
}