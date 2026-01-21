#include<stdio.h>
int main(){
    int testcase;
    int A[101],B[101];
    int full_res[101];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
    
    for(int i=0; i < testcase; i++){
        int place = 1;
        full_res[i] = 0;
        while (A[i] > 0 || B[i] > 0) {
            int da = A[i] % 10;
            int db = B[i] % 10;
            int sum = (da + db) % 10; // add without carry
            full_res[i] += sum * place;

            A[i] /= 10;
            B[i] /= 10;
            place *= 10;
        }
    }

    for(int i=0; i < testcase; i++){
        printf("Case #%d: %d\n", i+1, full_res[i]);
    }
    return 0;
}