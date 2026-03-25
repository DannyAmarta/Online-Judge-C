#include<stdio.h>
int main(){
    int N, A[5001];
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
        unsigned long long x;
        scanf("%llu", &x);

        int j = 0, count = 0;
        unsigned long long total = 0;
        for(int l = 0; l < N; l++){
            total += A[l];
            while(total > x && j <= l){
                total -= A[j];
                j++;
            }
            if(total <= x){
                int len = l - j + 1;
                if(len > count) count = len;
            }
        }
        if(count == 0) count = -1; 
        printf("Case #%d: %d\n", i+1, count);
    }

    return 0;
}