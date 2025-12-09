#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000003
#define MAXLEN 1000050

typedef struct Node {
    unsigned long long hash;
    struct Node* next;
} Node;

Node* table[MOD];

unsigned long long calc_hash(char* s){
    unsigned long long h = 0;
    for(int i=0; s[i]; i++){
        h = h * 131 + s[i]; // hash polinomial
    }
    return h;
}

int main(){
    char buffer[MAXLEN];
    int unique = 0;

    while(scanf("%s", buffer) != EOF){
        unsigned long long h = calc_hash(buffer);
        int idx = h % MOD;

        Node* p = table[idx];
        int found = 0;
        while(p){
            if(p->hash == h){ found = 1; break; }
            p = p->next;
        }

        if(!found){
            Node* n = (Node*)malloc(sizeof(Node));
            n->hash = h;
            n->next = table[idx];
            table[idx] = n;
            unique++;
        }
    }

    printf("%d\n", unique);
    return 0;
}