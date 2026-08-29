#include<stdio.h>

int main () {

    int angka1 = 10;             //int untuk bilangan bulat
    float angka2 = 10.5;         // float untuk bilangan desimal presisi rendah
    double angka3 = 10.5;        // double untuk bilangan desimal presisi tinggi
    char angka4 = 'A';           // char untuk bilangan karakter

    printf("Integer : %d\n", angka1);
    printf("Float : %f\n", angka2);
    printf("Double : %lf\n", angka3);
    printf("Char : %c\n", angka4);

    int umur = 18;
    float tinggi = 165.5;
    double berat = 45.5; 
    char nama[10] = "Akrom"; 
    char hobi[10] = "Muncak"; 

    printf("BIODATA SAYA\n");
    printf("======================\n"); 
    printf("Nama : %s\n", nama);
    printf("Umur : %d\n", umur);
    printf("Tinggi : %f\n", tinggi);
    printf("Berat : %lf\n", berat);
    printf("Hobi: %s\n", hobi); 
    printf("======================\n"); 

    printf("Yokoso Watashi no Mono\n"); 
    return 0;
}