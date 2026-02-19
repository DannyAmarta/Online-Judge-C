#include <stdio.h>

/* simple bubble sort */
void sort(int a[], int n, int ascending) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if ((ascending && a[i] > a[j]) ||
                (!ascending && a[i] < a[j])) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int N, X;
        scanf("%d %d", &N, &X);

        int a[505];
        for(int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }

        /* MAXIMUM points (shortest first) */
        sort(a, N, 1);
        int time = 0, maxPoint = 0;
        for(int i = 0; i < N; i++) {
            if(time + a[i] <= X) {
                time += a[i];
                maxPoint++;
            } else break;
        }

        /* MINIMUM points (longest first) */
        sort(a, N, 0);
        time = 0;
        int minPoint = 0;
        for(int i = 0; i < N; i++) {
            if(time + a[i] <= X) {
                time += a[i];
                minPoint++;
            } else break;
        }

        printf("Case #%d: %d %d\n", tc, minPoint, maxPoint);
    }

    return 0;
}
