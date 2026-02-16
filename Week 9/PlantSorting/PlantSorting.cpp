#include<stdio.h>
#include<string.h>
FILE *fptr;
typedef struct{
    int number;
    char string[41];
}Bio;

void merge(Bio biology[], int left, int mid, int right){
    int left_len = mid - left + 1;
    int right_len = right - mid;
    Bio bio1[left_len], bio2[right_len];
    for(int i = 0; i < left_len; i++){
        bio1[i] = biology[i + left];
    }
    for(int i = 0; i < right_len; i++){
        bio2[i] = biology[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while(i < left_len && j < right_len){
        if(strcmp(bio1[i].string, bio2[j].string) <= 0){
            biology[k++] = bio1[i++];
        }
        else{
            biology[k++] = bio2[j++];
        }
    }
    while(i < left_len){
        biology[k++] = bio1[i++];
    }
    while(j < right_len){
        biology[k++] = bio2[j++];
    }
}
void mergeSort(Bio biology[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(biology, left, mid);
        mergeSort(biology, mid+1, right);
        merge(biology, left, mid, right);
    }
}

int main(){
    fptr = fopen("testdata.in", "r");
    int T;
    fscanf(fptr, "%d", &T);
    Bio biology[1001];
    for(int i = 0; i < T; i++){
        fscanf(fptr, "%d#%[^\n]", &biology[i].number, biology[i].string);
    }
    mergeSort(biology, 0, T-1);
    for(int i = 0; i < T; i++){
        printf("%d %s\n", biology[i].number, biology[i].string);
    }
    return 0;
}