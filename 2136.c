#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5050

char yes[MAX][30];
char no[MAX][30];
char used[MAX][30];  // nomes já usados

int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int exists(char arr[][30], int size, char *s) {
    for (int i = 0; i < size; i++)
        if (strcmp(arr[i], s) == 0)
            return 1;
    return 0;
}

int main() {
    char name[30], status[5];
    int y = 0, n = 0, u = 0;
    char longest[30] = "";

    while (1) {
        scanf("%s", name);
        if (strcmp(name, "FIM") == 0)
            break;

        scanf("%s", status);

        // Ignora nomes repetidos
        if (exists(used, u, name))
            continue;

        strcpy(used[u++], name);

        if (strcmp(status, "YES") == 0) {
            strcpy(yes[y++], name);
            if (strlen(name) > strlen(longest))
                strcpy(longest, name);
        } else {
            strcpy(no[n++], name);
        }
    }

    qsort(yes, y, sizeof(yes[0]), cmp);
    qsort(no, n, sizeof(no[0]), cmp);

    for (int i = 0; i < y; i++)
        printf("%s\n", yes[i]);

    for (int i = 0; i < n; i++)
        printf("%s\n", no[i]);

    printf("\nAmigo do Habay:\n%s\n", longest);

    return 0;
}