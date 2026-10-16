#include <stdio.h>

int main() {
    int nilai[5] = {85, 90, 78, 92, 88};

    printf("CONTOH ARRAY 1 DIMENSI\n");
    for (int i = 0; i < 5; i++) {
        printf("Nilai siswa ke-%d: %d\n", i + 1, nilai[i]);
    }

    nilai[2] = 80;
    printf("\nNilai siswa ke-3 setelah diubah: %d\n\n", nilai[2]);

    int matriks[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("Contoh 2 array matrix\n");
    for (int baris = 0; baris < 2; baris++) {
        for (int kolom = 0; kolom < 3; kolom++) {
            printf("%d ", matriks[baris][kolom]);
        }
        printf("\n");
    }

    return 0;
}
