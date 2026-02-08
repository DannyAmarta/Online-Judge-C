#include <stdio.h>
#include <string.h>

void strip_newline(char *s) {
    int len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0';
        len--;
    }
}

void read_nonempty_line(char *buf, int size) {
    do {
        if (!fgets(buf, size, stdin)) return;
        strip_newline(buf);
    } while (buf[0] == '\0');  // skip blank lines
}

typedef struct {
    char code[20];
    char name[120];
    int credits;
} Course;

int main() {
    char buf[200];
    int N;

    // Read N safely
    read_nonempty_line(buf, sizeof(buf));
    sscanf(buf, "%d", &N);

    Course arr[1005];

    for (int i = 0; i < N; i++) {
        read_nonempty_line(arr[i].code, sizeof(arr[i].code));
        read_nonempty_line(arr[i].name, sizeof(arr[i].name));

        read_nonempty_line(buf, sizeof(buf));
        sscanf(buf, "%d", &arr[i].credits);
    }

    int Q;
    read_nonempty_line(buf, sizeof(buf));
    sscanf(buf, "%d", &Q);

    for (int i = 1; i <= Q; i++) {
        read_nonempty_line(buf, sizeof(buf));
        int X;
        sscanf(buf, "%d", &X);
        X--;

        printf("Query #%d:\n", i);
        printf("Code: %s\n", arr[X].code);
        printf("Name: %s\n", arr[X].name);
        printf("Credits: %d\n", arr[X].credits);
    }

    return 0;
}
