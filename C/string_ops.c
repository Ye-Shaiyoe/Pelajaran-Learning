#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Halo";
    char str2[] = " Dunia";
    char str3[50];

    printf("Panjang str1: %lu\n", strlen(str1));

    strcat(str1, str2);
    printf("Hasil gabung: %s\n", str1);

    strcpy(str3, str1);
    printf("Hasil copy ke str3: %s\n", str3);

    if (strcmp(str1, str3) == 0) {
        printf("str1 dan str3 sama\n");
    }

    return 0;
}
