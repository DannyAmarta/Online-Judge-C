#include <stdio.h>
#include <math.h>

int main() {
    int testcase;
    int A[101],B[101];
    int counter[101];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
    for(int i=0; i < testcase; i++){
        int full = A[i];   
        int empty = A[i];       
        counter[i] = full;       

        while (empty >= B[i]) {
            int exchanged = floor(empty / B[i]);
            counter[i] += exchanged;        
            empty = exchanged + (empty % B[i]);
        }
    }
    for(int i=0; i < testcase; i++){
        printf("Case #%d: %d\n", i + 1, counter[i]);
    }

    return 0;
}
