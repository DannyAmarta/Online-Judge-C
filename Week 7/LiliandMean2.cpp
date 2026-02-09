#include <stdio.h>

typedef struct {
    char id[20];
    char name[30];
    int score;
} Student;

Student arr[50005];   // <-- MOVE HERE (GLOBAL)

int main() {
    int N;
    scanf("%d", &N);

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i].id);
        scanf(" %[^\n]", arr[i].name);
        scanf("%d", &arr[i].score);
        sum += arr[i].score;
    }

    double mean = (double)sum / N;

    for (int i = 0; i < N; i++) {
        if (arr[i].score >= mean) {
            printf("%s %s\n", arr[i].id, arr[i].name);
        }
    }

    return 0;
}
