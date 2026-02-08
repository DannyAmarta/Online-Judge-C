#include <stdio.h>

typedef struct {
    char father[35];
    char mother[35];
    int siblings;
} Family;

typedef struct {
    char code[35];
    char name[35];
    char gender[35];
    Family fam;
} Student;

typedef struct {
    char code[35];
    char name[35];
    char gender[35];
    int studentCount;
    Student students[105];
} Lecturer;

int main() {
    int N;
    scanf("%d", &N);

    Lecturer lec[105];

    for (int i = 0; i < N; i++) {
        scanf("%s", lec[i].code);
        scanf("%s", lec[i].name);
        scanf("%s", lec[i].gender);
        scanf("%d", &lec[i].studentCount);

        for (int j = 0; j < lec[i].studentCount; j++) {
            scanf("%s", lec[i].students[j].code);
            scanf("%s", lec[i].students[j].name);
            scanf("%s", lec[i].students[j].gender);
            scanf("%s", lec[i].students[j].fam.father);
            scanf("%s", lec[i].students[j].fam.mother);
            scanf("%d", &lec[i].students[j].fam.siblings);
        }
    }

    int K;
    scanf("%d", &K);
    K--; // convert to 0-based

    // Print Lecturer
    printf("Kode Dosen: %s\n", lec[K].code);
    printf("Nama Dosen: %s\n", lec[K].name);
    printf("Gender Dosen: %s\n", lec[K].gender);
    printf("Jumlah Mahasiswa: %d\n", lec[K].studentCount);

    // Print each student
    for (int i = 0; i < lec[K].studentCount; i++) {
        Student *s = &lec[K].students[i];
        printf("Kode Mahasiswa: %s\n", s->code);
        printf("Nama Mahasiswa: %s\n", s->name);
        printf("Gender Mahasiswa: %s\n", s->gender);
        printf("Nama Ayah: %s\n", s->fam.father);
        printf("Nama Ibu: %s\n", s->fam.mother);
        printf("Jumlah Saudara Kandung: %d\n", s->fam.siblings);
    }

    return 0;
}
