#include <stdio.h>

double getValue(char c) {
    switch (c) {
        case 'W': return 1.0;
        case 'H': return 0.5;
        case 'Q': return 0.25;
        case 'E': return 0.125;
        case 'S': return 0.0625;
        case 'T': return 0.03125;
        case 'X': return 0.015625;
    }
    return 0.0;
}

int main() {
    char line[300];

    while (scanf("%s", line) && line[0] != '*') {
        double sum = 0.0;
        int count = 0;

        for (int i = 1; line[i] != '\0'; i++) {
            if (line[i] == '/') {
                if (sum == 1.0)
                    count++;
                sum = 0.0;
            } else {
                sum += getValue(line[i]);
            }
        }

        printf("%d\n", count);
    }

    return 0;
}