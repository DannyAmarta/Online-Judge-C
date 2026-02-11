#include <stdio.h>

FILE *fptr;
int main() {
    fptr = fopen("testdata.in", "r");
    int T;
    fscanf(fptr, "%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        fscanf(fptr, "%d", &N);

        int X[105];
        for (int i = 0; i < N; i++) {
            fscanf(fptr, "%d", &X[i]);
        }

        // Area
        int area = 0;
        for (int i = 0; i < N; i++) {
            area += 4 * X[i];
        }

        // Perimeter
        int perimeter = 0;

        // Top and bottom
        perimeter += 2 * N; // bottom
        perimeter += 2 * N; // top

        // Leftmost and rightmost heights
        perimeter += 2 * X[0];
        perimeter += 2 * X[N - 1];

        // Height differences
        for (int i = 1; i < N; i++) {
            if(X[i] > X[i-1]){
                perimeter += 2 * (X[i] - X[i - 1]);
            }
            else{
                perimeter += 2 * (X[i - 1] - X[i]);
            }
        }

        printf("Case #%d: %d %d\n", t, perimeter, area);
    }
    fclose(fptr);
    return 0;
}
