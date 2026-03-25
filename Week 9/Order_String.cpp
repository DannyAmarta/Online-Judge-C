#include<stdio.h>
#include<string.h>
int compare(char a, char b){
    int la = a >= 'a'? (a - 32) : a;
    int lb = b >= 'a'? (b - 32) : b;

    if(la != lb){
        return la < lb;
    }
    return a < b;
}
void merge(char arr[], int left, int mid, int right){
    int left_len = mid - left + 1;
    int right_len = right - mid;
    int left_arr[left_len], right_arr[right_len];
    for(int i = 0; i < left_len; i++){
        left_arr[i] = arr[i + left];
    }
    for(int i = 0; i < right_len; i++){
        right_arr[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while(i < left_len && j < right_len){
        if(compare(left_arr[i], right_arr[j])){
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
void mergeSort(char arr[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    char string[10000000];
    scanf("%s", string);

    mergeSort(string, 0, strlen(string)-1);
    printf("%s\n", string);
    return 0;
}