#include <stdio.h>

int main() {
    int testcase;
    unsigned long long overall[21];
    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        int child, chocolate;
        unsigned long long weight[501][501];
        scanf("%d %d", &child, &chocolate);

        for (int j = 0; j < child; j++) {
            for (int k = 0; k < chocolate; k++) {
                scanf("%llu", &weight[j][k]);
            }
        }

        overall[i] = 0;
        for (int j = 0; j < child; j++) {
            unsigned long long max = weight[j][0];
            for (int k = 1; k < chocolate; k++) {
                if (weight[j][k] > max) {
                    max = weight[j][k];
                }
            }
            overall[i] += max;
        }
    }

    for (int k = 0; k < testcase; k++) {
        printf("Case #%d: %llu\n", k + 1, overall[k]);
    }

    return 0;
}
