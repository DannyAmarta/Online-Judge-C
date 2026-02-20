#include<stdio.h>
void merge(int list[], int left, int mid, int right){
    int left_len = mid - left + 1;
    int right_len = right - mid;
    int left_arr[left_len], right_arr[right_len];
    int i = 0, j = 0, k = left;
    for(int i = 0; i < left_len; i++){
        left_arr[i] = list[i + left];
    }
    for(int i = 0; i < right_len; i++){
        right_arr[i] = list[i + mid + 1];
    }
    while(i < left_len && j < right_len){
        if(left_arr[i] >= right_arr[j]){
            list[k++] = left_arr[i++];
        }
        else{
            list[k++] = right_arr[j++];
        }
    }
    while(i < left_len){
        list[k++] = left_arr[i++];
    }
    while(j < right_len){
        list[k++] = right_arr[j++];
    }
}
void mergeSort(int list[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}
// void compare(int list[], int T, int x){
//     int odd[T];
//     int even[T];
//     int j = 0, k = 0;
//     for(int i = 0; i < T; i++){
//         if(list[i] % 2 == 0){
//             even[j++] = list[i];
//         }
//         else{
//             odd[k++] = list[i];
//         }
//     }
//     int evenct = 0, oddct = 0;
//     for(int i = 0; i < j-1; i++){
//         for(int l = i + 1 ; l < j; l++){
//             if(even[i] + even[l] >= x){
//                 evenct++;
//             }
//         }
//     }
//     for(int i = 0; i < k-1; i++){
//         for(int l = i + 1 ; l < k; l++){
//             if(odd[i] + odd[l] >= x){
//                 oddct++;
//             }
//         }
//     }
//     printf("%d %d\n", oddct, evenct);
// }
void compare(int list[], int T, int M){
    static int odd[100000], even[100000];
    int o = 0, e = 0;

    for(int i = 0; i < T; i++){
        if(list[i] % 2 == 0)
            even[e++] = list[i];
        else
            odd[o++] = list[i];
    }

    long long oddct = 0, evenct = 0;

    // ===== ODD =====
    int l = 0, r = o - 1;
    while(l < r){
        if(odd[l] + odd[r] >= M){
            oddct += (r - l);
            l++;
        } else {
            r--;
        }
    }

    // ===== EVEN =====
    l = 0; r = e - 1;
    while(l < r){
        if(even[l] + even[r] >= M){
            evenct += (r - l);
            l++;
        } else {
            r--;
        }
    }

    printf("%lld %lld\n", oddct, evenct);
}
int main(){
    int T;
    scanf("%d", &T);
    int list[100000];
    for(int i = 0; i < T; i++){
        scanf("%d", &list[i]);
    }
    mergeSort(list, 0, T-1);
    int Tc;
    scanf("%d", &Tc);
    int x;
    for(int i = 0; i < Tc; i++){
        scanf("%d", &x);
        printf("Case #%d: ", i+1);
        compare(list, T, x);
    }
    return 0;
}