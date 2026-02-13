#include <stdio.h>
#include <string.h>

typedef struct {
    char id[11];   // 10 digits + null terminator
    char name[21]; // max length 20 + null terminator
} Student;

int binarySearch(Student arr[], int n, char key[]) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid].id, key);

        if (cmp == 0) return mid;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }

    return -1; // not found
}

int main() {
    FILE *fp = fopen("testdata.in", "r");
    if (!fp) return 0;

    int N;
    fscanf(fp, "%d", &N);

    Student list[105];

    for (int i = 0; i < N; i++) {
        fscanf(fp, "%s %s", list[i].id, list[i].name);
    }

    int T;
    fscanf(fp, "%d", &T);

    char searchID[11];
    for (int t = 1; t <= T; t++) {
        fscanf(fp, "%s", searchID);

        int index = binarySearch(list, N, searchID);

        if (index == -1)
            printf("Case #%d: N/A\n", t);
        else
            printf("Case #%d: %s\n", t, list[index].name);
    }

    fclose(fp);
    return 0;
}
