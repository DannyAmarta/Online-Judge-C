#include <stdio.h>
#include <string.h>

#define MAXN 1000

typedef struct {
    char id[21];
    char name[101];
    int age;
} Student;

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

int main() {
    Student students[MAXN];
    char buf[200];
    int N, Q;

    // Read N
    read_nonempty_line(buf, sizeof(buf));
    sscanf(buf, "%d", &N);

    for (int i = 0; i < N; i++) {
        read_nonempty_line(students[i].id, sizeof(students[i].id));
        read_nonempty_line(students[i].name, sizeof(students[i].name));

        read_nonempty_line(buf, sizeof(buf));
        sscanf(buf, "%d", &students[i].age);
    }

    // Read Q
    read_nonempty_line(buf, sizeof(buf));
    sscanf(buf, "%d", &Q);

    for (int i = 1; i <= Q; i++) {
        read_nonempty_line(buf, sizeof(buf));
        int Xi;
        sscanf(buf, "%d", &Xi);

        printf("Query #%d:\n", i);
        printf("ID: %s\n", students[Xi-1].id);
        printf("Name: %s\n", students[Xi-1].name);
        printf("Age: %d\n", students[Xi-1].age);
    }

    return 0;
}
