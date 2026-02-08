#include <stdio.h>

typedef struct {
    char id[20];
    char name[30];
    int score;
} Student;

int main() {
    int N;
    scanf("%d", &N);

    Student arr[50005];
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i].id);       // ID has no spaces
        scanf(" %[^\n]", arr[i].name); // NAME may have spaces
        scanf("%d", &arr[i].score);   // Score
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
