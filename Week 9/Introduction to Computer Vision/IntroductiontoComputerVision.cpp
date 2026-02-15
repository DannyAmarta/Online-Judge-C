#include<stdio.h>
void merge(int arr[], int left, int mid, int right){
    int l_len = mid - left + 1;
    int r_len = right - mid;
    int l_arr[l_len];
    int r_arr[r_len];
    for(int i = 0; i < l_len; i++){
        l_arr[i] = arr[i+left];
    }
    for(int j = 0; j < r_len; j++){
        r_arr[j] = arr[j+mid+1];
    }
    int i = 0, j = 0, k = left;
    while(i < l_len && j < r_len){
        if(l_arr[i] <= r_arr[j]){
            arr[k++] = l_arr[i++]; 
        }
        else{
            arr[k++] = r_arr[j++]; 
        }
    }
    while(i < l_len){
        arr[k++] = l_arr[i++]; 
    }
    while(j < r_len){
        arr[k++] = r_arr[j++];
    }
}
void mergeSort(int arr[], int left, int right){
    int mid = (left + right) / 2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
FILE *fptr;
int main(){
   fptr = fopen("testdata.in", "r");
    if(!fptr) return 0;

    int Tc;
    fscanf(fptr, "%d", &Tc);

    for(int tc = 1; tc <= Tc; tc++){
        int N, M;
        fscanf(fptr, "%d %d", &N, &M);

        int total = N * M;
        int pixels[10000];

        int idx = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                fscanf(fptr, "%d", &pixels[idx++]);
            }
        }

        mergeSort(pixels, 0, total - 1);

        int K;
        if(total % 2 == 1){
            K = pixels[total / 2];
        } else {
            int a = pixels[total / 2 - 1];
            int b = pixels[total / 2];
            K = (a + b + 1) / 2; 
        }

        printf("Case #%d: %d\n", tc, K);
    }

    fclose(fptr);
    return 0;
}