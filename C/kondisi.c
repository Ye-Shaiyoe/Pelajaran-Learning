#include <stdio.h>

int main() {
    int nilai = 75;

    printf("Contoh percabangan (If - Else)\n");
    printf("Nilai Anda: %d\n", nilai);

    if (nilai >= 85) {
        printf("Predikat: A (Sangat Baik)\n");
    } else if (nilai >= 70) {
        printf("Predikat: B (Baik)\n");
    } else if (nilai >= 55) {
        printf("Predikat: C (Cukup)\n");
    } else {
        printf("Predikat: D (Kurang)\n");
    }

    printf("\nContoh Switch Case\n");
    char grade = 'B';
    switch (grade) {
        case 'A':
            printf("Luar biasa, pertahankan!\n");
            break;
        case 'B':
            printf("Bagus, terus tingkatkan!\n");
            break;
        case 'C':
            printf("Cukup, belajar lebih giat lagi.\n");
            break;
        default:
            printf("Perlu bimbingan lebih lanjut.\n");
            break;
    }

    return 0;
}
