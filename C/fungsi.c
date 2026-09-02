#include <stdio.h>

int tambah(int a, int b) {
    return a + b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    
    printf("Hasil tambah: %d\n", tambah(x, y));
    
    printf("Sebelum swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("Sesudah swap: x=%d, y=%d\n", x, y);
    
    return 0;
}
