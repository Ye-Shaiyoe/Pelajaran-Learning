#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[100];

    fp = fopen("catatan.txt", "w");
    if (fp == NULL) {
        printf("Gagal membuka file untuk menulis\n");
        return 1;
    }
    fprintf(fp, "Belajar File I/O di bahasa C\nBaris kedua file");
    fclose(fp);

    fp = fopen("catatan.txt", "r");
    if (fp == NULL) {
        printf("Gagal membaca file\n");
        return 1;
    }
    printf("Isi file catatan.txt:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    printf("\n");
    fclose(fp);

    remove("catatan.txt");

    return 0;
}
