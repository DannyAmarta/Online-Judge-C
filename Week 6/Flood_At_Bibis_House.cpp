#include <stdio.h>

#define MAX 100

int N, M;
char grid[MAX][MAX];

// Recursive function to count flooded tiles (excluding 'S')
int flood_fill(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return 0;
    if (grid[x][y] == '#' || grid[x][y] == '*') return 0; // wall or visited
    if (grid[x][y] == 'S') return 0; // don't count S itself

    grid[x][y] = '*'; // mark visited
    int count = 1;    // count this tile

    count += flood_fill(x + 1, y);
    count += flood_fill(x - 1, y);
    count += flood_fill(x, y + 1);
    count += flood_fill(x, y - 1);

    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        scanf("%d %d", &N, &M);
        int sx = -1, sy = -1;

        for (int i = 0; i < N; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        int result = 0;
        // Count flooded tiles from neighbors of S
        if (sx != -1 && sy != -1) {
            if (sx > 0) result += flood_fill(sx - 1, sy);
            if (sx < N - 1) result += flood_fill(sx + 1, sy);
            if (sy > 0) result += flood_fill(sx, sy - 1);
            if (sy < M - 1) result += flood_fill(sx, sy + 1);
        }

        printf("Case #%d: %d\n", caseNum, result);
    }

    return 0;
}
