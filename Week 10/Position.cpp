#include<stdio.h>
int number[100001];
int binarySearch(int Q, int N){
    int left = 0, right = N;
    while(left < right){
        int mid = (left + right)/2;
        // if(number[mid] == Q){
        //     return mid;
        // }
        if(number[mid] < Q){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    } 
    return left;
}
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int Q[100001];
    for(int i = 0; i < N; i++){
        scanf("%d", &number[i]);
    }
    for(int j = 0; j < M; j++){
        scanf("%d", &Q[j]);
    }
    // printf("tes");
    for(int i = 0; i < M; i++){
        int idx = binarySearch(Q[i], N);
        // printf("idx %d", idx);
        // if(idx == -1){
        //     printf("-1\n");
        // }
        // else{
        //     printf("%d\n", idx);
        // }
        if(idx < N && number[idx] == Q[i]){
            printf("%d\n", idx + 1);
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}