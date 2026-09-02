#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Alokasi Memori Dinamis dengan malloc()
    // Mengalokasikan ruang memori untuk 3 buah integer
    int n = 3;
    int *arr = (int *)malloc(n * sizeof(int));

    // Validasi alokasi memori
    if (arr == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }

    printf("Alokasi memori dinamis\n");
    // Mengisi data ke memori yang telah dialokasikan
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d (Alamat: %p)\n", i, arr[i], (void *)&arr[i]);
    }

    // 2. Mengubah ukuran alokasi memori dengan realloc()
    n = 5;
    int *temp = (int *)realloc(arr, n * sizeof(int));
    if (temp == NULL) {
        printf("Gagal mengubah ukuran memori!\n");
        free(arr); // Bebaskan memori lama jika gagal
        return 1;
    }
    arr = temp;

    // Mengisi elemen tambahan
    arr[3] = 40;
    arr[4] = 50;

    printf("\nSetela realloc\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d (Alamat: %p)\n", i, arr[i], (void *)&arr[i]);
    }

    // 3. Wajib membebaskan memori setelah selesai digunakan
    free(arr);
    arr = NULL; // Menghindari dangling pointer

    printf("\nMemori berhasil dibebaskan (free).\n");

    return 0;
}
