#include <stdio.h>
#include <stdlib.h>

int compareEven(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);   // crescente
}

int compareOdd(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);   // decrescente
}

int main() {
    int N;
    scanf("%d", &N);

    int even[100000], odd[100000];
    int e = 0, o = 0;

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        if (x % 2 == 0)
            even[e++] = x;
        else
            odd[o++] = x;
    }

    qsort(even, e, sizeof(int), compareEven);
    qsort(odd, o, sizeof(int), compareOdd);

    for (int i = 0; i < e; i++)
        printf("%d\n", even[i]);

    for (int i = 0; i < o; i++)
        printf("%d\n", odd[i]);

    return 0;
}