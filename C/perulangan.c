#include <stdio.h>

int main() {
    printf("For loop\n");
    for (int i = 1; i <= 5; i++) {
        printf("Perulangan for ke-%d\n", i);
    }

    printf("\nWhile loop\n");
    int count = 1;
    while (count <= 3) {
        printf("Hitungan while: %d\n", count);
        count++;
    }

    printf("\nDo while loop\n");
    int j = 1;
    do {
        printf("Perulangan do-while minimal jalan 1x (nilai j: %d)\n", j);
        j++;
    } while (j <= 2);

    return 0;
}
