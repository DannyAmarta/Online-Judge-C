#include<stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int N, A[10001];
        unsigned long long M;
        scanf("%d %llu", &N, &M);
        for(int j = 0; j < N; j++){
            scanf("%d", &A[j]);
        }

        int x = 0, count = 0;
        unsigned long long temp = 0;
        for(int j = 0; j < N; j++){
            temp += A[j];
            while(temp > M && x <= j){
                temp -= A[x];
                x++;
            }
            if(temp <= M){
                int len = j - x + 1;
                if(len > count) count = len;
            }
        }
        if(count == 0) count = -1;
        printf("Case #%d: %d\n", i+1, count);
    }
    return 0;
}