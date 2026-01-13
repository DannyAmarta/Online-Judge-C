#include <stdio.h>

int main() {
    int testcase;
    int A[100],B[100],C[100],D[100],E[100],F[100];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d %d %d %d %d %d", &A[i], &B[i], &C[i], &D[i], &E[i], &F[i]);
    }
    for(int i=0; i < testcase; i++){
        printf("Case #%d: ", i + 1);
        for(int q=0; q < A[i]; q++){
            printf("a");
        }
        for(int w=0; w < B[i]; w++){
            printf("s");
        }
        for(int r=0; r < C[i]; r++){
            printf("h");
        }
        for(int t=0; t < D[i]; t++){
            printf("i");
        }
        for(int y=0; y < E[i]; y++){
            printf("a");
        }
        for(int u=0; u < F[i]; u++){
            printf("p");
        }
        printf("\n");
    }

    return 0;
}
