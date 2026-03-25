#include<stdio.h>
void merge(int arr[], int left, int mid, int right){
    int left_len = mid - left + 1;
    int right_len = right - mid;
    int left_arr[left_len], right_arr[right_len];
    for(int i = 0; i < left_len; i++){
        left_arr[i] = arr[i+left];
    }
    for(int i = 0; i < right_len; i++){
        right_arr[i] = arr[i+mid+1];
    }
    int i = 0, j = 0, k = left;
    while(i < left_len && j < right_len){
        if(left_arr[i] < right_arr[j]){
            arr[k++] = left_arr[i++];
        }
        else{
            arr[k++] = right_arr[j++];
        }
    }
    while(i < left_len){
        arr[k++] = left_arr[i++];
    }
    while(j < right_len){
        arr[k++] = right_arr[j++];
    }
    
}
void mergeSort(int arr[], int left, int right){
    int mid = (left+right)/2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
int binarySearch(int height[], int n, int curr){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (right + left)/2;
        if(height[mid] == curr){
            return mid + 1;
        }
        else if(height[mid] > curr){
            right = mid - 1;
        }
        else if(height[mid] < curr){
            left = mid + 1;
        }
    }
    return -1;
}
int main(){
    int N;
    scanf("%d", &N);
    int height[100001];
    for(int i = 0; i < N; i++){
        scanf("%d", &height[i]);
    }
    mergeSort(height, 0, N-1);
    int order;
    int curr;
    scanf("%d", &order);
    for(int i = 0; i < order; i++){
        scanf("%d", &curr);
        // int j;
        // for(j = 0; j < N; j++){
        //     if(height[j] == curr){
        //         printf("%d\n", j+1);
        //         break;
        //     }
        // }
        // if(j == N) printf("-1\n");
        printf("%d\n", binarySearch(height, N, curr));
    }
    return 0;
}