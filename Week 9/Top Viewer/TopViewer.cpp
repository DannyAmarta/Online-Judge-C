#include<stdio.h>
#include<string.h>
FILE *fptr;
typedef struct{
    char title[1001];
    char artist[1001];
    int view;
}Video;
void merge(Video video[], int left, int mid, int right){
    int left_len = mid - left + 1;
    int right_len = right - mid;
    Video left_arr[left_len], right_arr[right_len];
    for(int i = 0; i < left_len; i++){
        left_arr[i] = video[i + left];
    }
    for(int i = 0; i < right_len; i++){
        right_arr[i] = video[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while(i < left_len && j < right_len){
        if(left_arr[i].view > right_arr[j].view ||
            (left_arr[i].view == right_arr[j].view &&
            strcmp(left_arr[i].title, right_arr[j].title) < 0)
        ){
            video[k++] = left_arr[i++];
        }
        else{
            video[k++] = right_arr[j++];
        }
    }
    while(i < left_len){
        video[k++] = left_arr[i++];
    }
    while(j < right_len){
        video[k++] = right_arr[j++];
    }
}
void mergeSort(Video video[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(video, left, mid);
        mergeSort(video, mid+1, right);
        merge(video, left, mid, right);
    }
}
int main(){
    fptr = fopen("testdata.in", "r");

    Video video[101];
    int x = 0;
    while(fscanf(fptr, "%[^#]#%[^#]#%d\n", video[x].title, video[x].artist, &video[x].view) == 3){
        x++;
    }
    mergeSort(video, 0, x-1);
    for(int i = 0; i < x; i++){
        printf("%s by %s - %d\n", video[i].title, video[i].artist, video[i].view);
    }

    return 0;
}