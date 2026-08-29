#include<stdio.h>

void angka (int y){
    y += 20; 
}

int main(){
    int x = 30; 

    int *ptr = &x;

    *ptr = 50;

    printf("Nilai dari x adalah %d\n", x); 
    printf("Alamat memori dari x adalah %p\n", &x);
    printf("Nilai dari pointer ptr adalah %p\n", ptr); 
    printf("Nilai yang ditunjuk oleh pointer ptr adalah %d\n", *ptr);
    printf("Alamat memori dari pointer ptr adalah %p\n", &ptr); 

    printf("\n");
    angka(x);
    printf("Nilai dari x setelah ditambahkan 20 adalah %d\n", x); 

    printf("\n");
    return 0; 
}