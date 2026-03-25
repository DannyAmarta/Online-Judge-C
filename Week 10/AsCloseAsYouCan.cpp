// #include<stdio.h>
// void merge(int arr[], int left, int mid, int right){
//     int left_len = mid - left + 1;
//     int right_len = right - mid;
//     int left_arr[left_len], right_arr[right_len];
//     for(int i = 0; i < left_len; i++){
//         left_arr[i] = arr[i + left];
//     }
//     for(int i = 0; i < right_len; i++){
//         right_arr[i] = arr[i + mid + 1];
//     }
//     int i = 0, j = 0, k = left;
//     while(i < left_len && j < right_len){
//         if(left_arr[i] < right_arr[j]){
//             arr[k++] = left_arr[i++];
//         }
//         else{
//             arr[k++] = right_arr[j++];
//         }
//     }
//     while(i < left_len){
//         arr[k++] = left_arr[i++];
//     }
//     while(j < right_len){
//         arr[k++] = right_arr[j++];
//     }
// }
// void mergeSort(int arr[], int left, int right){
//     if(left < right){
//         int mid = (left + right)/2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid+1, right);
//         merge(arr, left, mid, right);
//     }
// }
// int binarySearch(unsigned long long arr[], int N, unsigned long long x){
//     int left = 0, right = N - 1;
//     int ans = -1;
//     while(left <= right){
//         int mid = (left + right)/2;
//         if(arr[mid] <= x){
//             ans = mid;
//             left = mid + 1;
//         }
//         else{
//             right = mid - 1;
//         }
//     }
//     return ans;
// }

// int main(){
//     int N, A[100001];
//     scanf("%d", &N);
//     for(int i = 0; i < N; i++){
//         scanf("%d", &A[i]);
//     }
//     mergeSort(A, 0, N-1);
//     int Q;
//     scanf("%d", &Q);
//     unsigned long long x;

//     unsigned long long prefix[100001];
//     prefix[0] = A[0];
//     for(int i = 1; i < N; i++){
//         prefix[i] = prefix[i-1] + A[i];
//     }

//     for(int i = 0; i < Q; i++){
//         scanf("%llu", &x);
//         int idx = binarySearch(prefix, N, x);
//         if(idx == -1)
//             printf("Case #%d: -1\n", i+1);
//         else
//             printf("Case #%d: %d\n", i+1, idx + 1);
//     }
//     return 0;
// }
#include <stdio.h>

#define MAXN 100005

int A[MAXN];
int temp[MAXN];

void merge(int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right){
        if(A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while(i <= mid)
        temp[k++] = A[i++];

    while(j <= right)
        temp[k++] = A[j++];

    for(int x = left; x <= right; x++)
        A[x] = temp[x];
}

void mergeSort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int binarySearch(unsigned long long arr[], int N, unsigned long long x){
    int left = 0, right = N - 1, ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] <= x){
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    // mergeSort(0, N - 1);

    unsigned long long prefix[MAXN];
    prefix[0] = A[0];
    for(int i = 1; i < N; i++){
        prefix[i] = prefix[i - 1] + A[i];
    }

    int Q;
    scanf("%d", &Q);

    for(int i = 0; i < Q; i++){
        unsigned long long x;
        scanf("%llu", &x);
        int idx = binarySearch(prefix, N, x);
        printf("Case #%d: %d\n", i + 1, idx == -1 ? -1 : idx + 1);
    }

    return 0;
}
