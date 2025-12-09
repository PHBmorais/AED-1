#include <stdio.h>

#define MAX 1024

char grid[MAX][MAX];
int visited[MAX][MAX];
int N, M;

typedef struct {
    int x, y;
} Point;

Point queue[MAX * MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int startX, int startY) {
    int front = 0, back = 0;
    queue[back++] = (Point){startX, startY};
    visited[startX][startY] = 1;

    while (front < back) {
        Point p = queue[front++];
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx >= 0 && nx < N &&
                ny >= 0 && ny < M &&
                !visited[nx][ny] &&
                grid[nx][ny] == '.') {

                visited[nx][ny] = 1;
                queue[back++] = (Point){nx, ny};
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int regions = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                bfs(i, j);
                regions++;
            }
        }
    }

    printf("%d\n", regions);

    return 0;
}