#include<stdio.h>
int main(){
    int size;
    int A[1001], B[1001];
    scanf("%d", &size);
    for(int i=0; i < size; i++){
        scanf("%d", &A[i]);
    }
    for(int i=0; i < size; i++  ){
        scanf("%d", &B[i]);
    }
    int temp[1001];
    for(int i=0; i < size; i++){
        temp[A[i]] = B[i];
    }
    for(int i=0; i < size; i++){
        if(i == size-1){
            printf("%d\n", temp[i]);
        }
        else{
            printf("%d ", temp[i]);
        }
    }

    return 0;
}