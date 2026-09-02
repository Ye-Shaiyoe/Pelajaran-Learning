#include <stdio.h>
#include <string.h>

// Deklarasi Struct
struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
};

// Fungsi yang menerima parameter Struct
void tampilkanMahasiswa(struct Mahasiswa m) {
    printf("NIM  : %d\n", m.nim);
    printf("Nama : %s\n", m.nama);
    printf("IPK  : %.2f\n", m.ipk);
}

int main() {
    // Inisialisasi data struct
    struct Mahasiswa mhs1;
    strcpy(mhs1.nama, "Akrom");
    mhs1.nim = 123456;
    mhs1.ipk = 3.85;

    printf("Data mahasiswa\n");
    tampilkanMahasiswa(mhs1);

    return 0;
}
