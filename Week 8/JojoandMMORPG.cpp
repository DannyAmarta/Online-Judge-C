#include<stdio.h>
void merge(unsigned long long level[101], int left, int mid, int right){
    int left_len = mid - left + 1;
    int right_len = right - mid;
    unsigned long long left_arr[left_len], right_arr[right_len];
    for(int i = 0; i < left_len; i++){
        left_arr[i] = level[i+left];
    }
    for(int i = 0; i < right_len; i++){
        right_arr[i] = level[i+mid+1];
    }
    int i = 0, j = 0, k = left;
    while(i < left_len && j < right_len){
        if(left_arr[i] < right_arr[j]){
            level[k++] = left_arr[i++];
        }
        else{
            level[k++] = right_arr[j++];
        }
    }
    while(i < left_len){
        level[k++] = left_arr[i++];
    }
    while(j < right_len){
        level[k++] = right_arr[j++];
    }
}
void mergeSort(unsigned long long level[101], int left, int right){
    int mid = (left + right) / 2;
    if(left < right){
        mergeSort(level, left, mid);
        mergeSort(level, mid+1, right);
        merge(level, left, mid, right);
    }
}
int main(){
    int N;
    unsigned long long level[101], mc; 
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%llu", &level[i]);
        // printf("s %llu", level[i]);
    }
    scanf("%llu", &mc);
    // printf("s %llu", mc);
    mergeSort(level, 0, N-1);
    int curr = 0;
    while(curr < N){
        if(mc < level[curr]){
            break;
        }
        mc -= level[curr++];
    }
    printf("%d\n", curr);
    return 0;
}