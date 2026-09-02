#include <stdio.h>

enum Hari {
    SENIN = 1,
    SELASA,
    RABU,
    KAMIS,
    JUMAT,
    SABTU,
    MINGGU
};

typedef unsigned long ulong;
typedef struct {
    int x;
    int y;
} Titik;

int main() {
    enum Hari hariIni = RABU;
    printf("Nilai enum RABU: %d\n", hariIni);

    ulong id = 1000293848UL;
    printf("Typedef ulong: %lu\n", id);

    Titik t1 = {15, 25};
    printf("Titik koordinat: (%d, %d)\n", t1.x, t1.y);

    return 0;
}
