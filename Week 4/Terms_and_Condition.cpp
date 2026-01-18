#include <stdio.h>
#include <math.h>

int main() {
    int testcase;
    int A[1001],B[1001], C[1001];
    int result[1001];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
    }
    for(int i=0; i < testcase; i++){
        if(((A[i] * B[i])/100) < C[i]){
            result[i] = ((A[i] * B[i])/100);
        }
        else{
            result[i] = C[i];
        }
    }
    for(int i=0; i < testcase; i++){
        printf("Case #%d: %d\n", i + 1, result[i]);
    }

    return 0;
}
