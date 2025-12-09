#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

Edge edges[50000];

int parent[40005], rank[40005];

int cmp(const void *a, const void *b){
    Edge *ea = (Edge*)a;
    Edge *eb = (Edge*)b;
    return ea->w - eb->w;
}

int find(int x){
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) parent[x] = y;
    else if(rank[x] > rank[y]) parent[y] = x;
    else { parent[y] = x; rank[x]++; }
}

int main(){
    while(1){
        int M,N;
        scanf("%d %d",&M,&N);
        if(M==0 && N==0) break;

        for(int i=0;i<M;i++){ parent[i]=i; rank[i]=0; }

        for(int i=0;i<N;i++){
            int X,Y,Z;
            scanf("%d %d %d",&X,&Y,&Z);
            edges[i].u=X;
            edges[i].v=Y;
            edges[i].w=Z;
        }

        qsort(edges,N,sizeof(Edge),cmp);

        long long total = 0;
        for(int i=0;i<N;i++){
            int u = edges[i].u;
            int v = edges[i].v;
            if(find(u) != find(v)){
                unite(u,v);
                total += edges[i].w;
            }
        }

        printf("%lld\n", total);
    }
    return 0;
}