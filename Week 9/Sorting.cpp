#include <stdio.h>

int temp[100000];  // buffer global

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    int arr[100000];
    for (int i = 0; i < T; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, T - 1);

    int max = arr[1] - arr[0];
    for (int i = 1; i < T - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff > max)
            max = diff;
    }

    int count = 0;
    for (int i = 0; i < T - 1; i++)
        if (arr[i + 1] - arr[i] == max)
            count++;

    int printed = 0;
    for (int i = 0; i < T - 1; i++) {
        if (arr[i + 1] - arr[i] == max) {
            printf("%d %d", arr[i], arr[i + 1]);
            printed++;
            if (printed < count)
                printf(" ");
        }
    }
    printf("\n");

    return 0;
}
