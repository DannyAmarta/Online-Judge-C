#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y, dist;
} Node;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int minKnightMoves(int startX, int startY, int endX, int endY) {
    int visited[8][8] = {0};
    Node queue[64];  // max 64 positions in 8x8 board
    int front = 0, rear = 0;
    queue[rear++] = (Node){startX, startY, 0};
    visited[startX][startY] = 1;

    while(front < rear){
        Node current = queue[front++];
        if(current.x == endX && current.y == endY)
            return current.dist;

        for(int i=0;i<8;i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if(nx>=0 && nx<8 && ny>=0 && ny<8 && !visited[nx][ny]){
                visited[nx][ny] = 1;
                queue[rear++] = (Node){nx, ny, current.dist+1};
            }
        }
    }
    return -1; // tidak mungkin
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        char start[3], end[3];
        scanf("%s %s", start, end);
        int x1 = start[0]-'A';
        int y1 = start[1]-'1';
        int x2 = end[0]-'A';
        int y2 = end[1]-'1';
        int steps = minKnightMoves(x1, y1, x2, y2);
        printf("Case #%d: %d\n", t, steps);
    }
    return 0;
}
