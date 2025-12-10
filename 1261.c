#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_CHAR 100

typedef struct {
    char word[MAX_CHAR];
    int value;
} Dict;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    Dict dict[MAX_WORDS];

    for (int i = 0; i < m; i++) {
        scanf("%s %d", dict[i].word, &dict[i].value);
    }

    char word[MAX_CHAR];
    long long sum;

    for (int i = 0; i < n; i++) {
        sum = 0;

        while (scanf("%s", word)) {
            if (strcmp(word, ".") == 0) break;

            for (int j = 0; j < m; j++) {
                if (strcmp(word, dict[j].word) == 0) {
                    sum += dict[j].value;
                    break;
                }
            }
        }
        printf("%lld\n", sum);
    }

    return 0;
}