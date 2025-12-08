#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int pilha[MAX], topo = 0;
        int fila[MAX], inicio = 0, fim = 0;
        int prioridade[MAX], tam_prioridade = 0;
        
        int eh_pilha = 1, eh_fila = 1, eh_prioridade = 1;
        
        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);
            
            if (op == 1) { // inserir
                pilha[topo++] = x;
                
                fila[fim++] = x;
                
                prioridade[tam_prioridade++] = x;
            } else {
                if (eh_pilha) {
                    if (topo == 0 || pilha[topo-1] != x) eh_pilha = 0;
                    else topo--;
                }
                
                if (eh_fila) {
                    if (inicio == fim || fila[inicio] != x) eh_fila = 0;
                    else inicio++;
                }
                
                if (eh_prioridade) {
                    if (tam_prioridade == 0) {
                        eh_prioridade = 0;
                    } else {
                        int max = prioridade[0], idx = 0;
                        for (int j = 1; j < tam_prioridade; j++) {
                            if (prioridade[j] > max) {
                                max = prioridade[j];
                                idx = j;
                            }
                        }
                        if (max != x) eh_prioridade = 0;
                        else {
                            for (int j = idx; j < tam_prioridade-1; j++)
                                prioridade[j] = prioridade[j+1];
                            tam_prioridade--;
                        }
                    }
                }
            }
        }
        
        int total = eh_pilha + eh_fila + eh_prioridade;
        if (total == 0) printf("impossible\n");
        else if (total > 1) printf("not sure\n");
        else if (eh_pilha) printf("stack\n");
        else if (eh_fila) printf("queue\n");
        else printf("priority queue\n");
    }
    
    return 0;
}