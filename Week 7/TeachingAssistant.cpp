#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        // groups[g][i][j]
        char groups[21][205][15]; 
        int count[21] = {0};

        for (int i = 0; i < N; i++) {
            char name[15];
            int g;
            scanf("%s %d", name, &g);
            strcpy(groups[g][count[g]++], name);
        }

        printf("Case #%d:\n", tc);

        for (int g = 1; g <= 20; g++) {
            if (count[g] > 0) {
                printf("Group %d(%d):\n", g, count[g]);
                for (int i = 0; i < count[g]; i++) {
                    printf("%s\n", groups[g][i]);
                }
                // if (g != 20) printf("\n"); 
            }
        }
    }

    return 0;
}
