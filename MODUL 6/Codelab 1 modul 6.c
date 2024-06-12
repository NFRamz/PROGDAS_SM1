#include<stdio.h>

int panjang, lebar, tinggi, luas, volume; 
void rumus_penghitung_luas_permukaan_balok(), rumus_penghitung_volume_balok();

int main(){

    printf("=== KALKULATOR MENGHITUNG BALOK ===\n");
    
    printf("Masukkan panjang balok : ");
    scanf("%d", &panjang);

    printf("Masukkan lebar balok : ");
    scanf("%d", &lebar);
    
    printf("Masukkan tinggi balok : ");
    scanf("%d", &tinggi);

    rumus_penghitung_luas_permukaan_balok();
    rumus_penghitung_volume_balok();

    printf("\nLuas permukaan balok adalah %d cm^2\n", luas);
    printf("Volume balok adalah %d cm^3 \n", volume);
    return 0;
}

void rumus_penghitung_luas_permukaan_balok(){
    luas    = 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
}

void rumus_penghitung_volume_balok(){
    volume  =   panjang * lebar * tinggi;
}
