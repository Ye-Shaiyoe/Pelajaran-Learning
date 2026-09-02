#include <stdio.h>

int main() {
    unsigned char a = 5;  // 0000 0101
    unsigned char b = 9;  // 0000 1001

    printf("a & b  = %d\n", a & b);  // AND: 0000 0001 (1)
    printf("a | b  = %d\n", a | b);  // OR:  0000 1101 (13)
    printf("a ^ b  = %d\n", a ^ b);  // XOR: 0000 1100 (12)
    printf("~a     = %d\n", (unsigned char)~a); // NOT
    printf("a << 1 = %d\n", a << 1); // Left Shift (dikali 2)
    printf("a >> 1 = %d\n", a >> 1); // Right Shift (dibagi 2)

    return 0;
}
