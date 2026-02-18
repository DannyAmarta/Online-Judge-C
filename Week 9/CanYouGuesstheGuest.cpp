#include <stdio.h>
#include <stdlib.h>

void merge(long long arr[], int left, int mid, int right){
    int left_i = mid - left + 1;
    int right_i = right - mid;
    long long left_arr[left_i];
    long long right_arr[right_i];
    for(int i = 0; i < left_i; i++){
        left_arr[i] = arr[left+i];
    }
    for(int i = 0; i < right_i; i++){
        right_arr[i] = arr[mid+1+i];
    }
    int i = 0, j = 0, k = left;
    while(i < left_i && j < right_i){
        if(left_arr[i] < right_arr[j]){
            arr[k++] = left_arr[i++];
        }
        else{
            arr[k++] = right_arr[j++];
        }
    }
    while(i < left_i){
        arr[k++] = left_arr[i++];
    }
    while(j < right_i){
        arr[k++] = right_arr[j++];
    }
}
void mergeSort(long long arr[], int left, int right){
    int mid = (left+right) / 2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        long long S[25];
        for (int i = 0; i < 25; i++) {
            scanf("%lld", &S[i]);
        }

        // sort all sums
        mergeSort(S, 0, 25-1);

        long long M[5];
        int used[25] = {0};

        // smallest = 2 * M1
        M[0] = S[0] / 2;
        used[0] = 1;

        // find remaining Mi
        for (int i = 1; i < 5; i++) {
            // find next unused smallest sum
            int idx = -1;
            for (int j = 0; j < 25; j++) {
                if (!used[j]) {
                    idx = j;
                    break;
                }
            }

            long long val = S[idx];
            M[i] = val - M[0];   // Mi = (M1 + Mi) - M1

            // mark all M[k] + M[i] as used
            for (int k = 0; k <= i; k++) {
                long long target = M[k] + M[i];
                int times = (k == i ? 1 : 2);   // 🔑 THIS IS THE KEY

                for (int t = 0; t < times; t++) {
                    int found = 0;
                    for (int j = 0; j < 25; j++) {
                        if (!used[j] && S[j] == target) {
                            used[j] = 1;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) break;
                }
            }

        }

        // output
        printf("Case #%d:", tc);
        for (int i = 0; i < 5; i++) {
            printf(" %lld", M[i]);
        }
        printf("\n");
    }

    return 0;
}
