#include <stdio.h>

typedef struct {
    char nama[105];
    char nim[15];
    int umur;
    char kodePos[10];
    char tempatLahir[105];
    char tanggalLahir[105];
    char almamater[105];
    int jumlahSaudara;
    int tinggi;
    char rekening[15];
} Student;

Student arr[105]; // GLOBAL ? SAFE, NO CRASH

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        scanf(" %[^\n]", arr[i].nama);
        scanf(" %s", arr[i].nim);
        scanf("%d", &arr[i].umur);
        scanf(" %s", arr[i].kodePos);
        scanf(" %[^\n]", arr[i].tempatLahir);
        scanf(" %[^\n]", arr[i].tanggalLahir);
        scanf(" %[^\n]", arr[i].almamater);  // HAS SPACES
        scanf("%d", &arr[i].jumlahSaudara);
        scanf("%d", &arr[i].tinggi);
        scanf(" %s", arr[i].rekening);
    }

    for (int i = 0; i < N; i++) {
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: %s\n", arr[i].nama);
        printf("NIM: %s\n", arr[i].nim);
        printf("Umur: %d\n", arr[i].umur);
        printf("Kode Pos: %s\n", arr[i].kodePos);
        printf("Tempat Lahir: %s\n", arr[i].tempatLahir);
        printf("Tanggal Lahir: %s\n", arr[i].tanggalLahir);
        printf("Almamater SMA: %s\n", arr[i].almamater);
        printf("Jumlah Saudara Kandung: %d\n", arr[i].jumlahSaudara);
        printf("Tinggi Badan: %d\n", arr[i].tinggi);
        printf("NOMOR REKENING: %s\n", arr[i].rekening);

//        if (i != N - 1) printf("\n");
    }

    return 0;
}
