#include <stdio.h>

enum Namafilm {
    Unstoppable, 
    Insidious,   
    Us           
};

int main() {
    enum Namafilm Genrefilm;
    int input;

    printf("Masukkan nama film:\n");
    printf("1. Unstoppable\n");
    printf("2. Insidious\n");
    printf("3. Us\n");
    printf("Pilihan Anda: ");
    scanf("%d", &input);
    switch(input){
        case 1:
        Genrefilm=Unstoppable;
        break;
        case 2:
        Genrefilm=Insidious;
        break;
        case 3:
        Genrefilm=Us;
        break;
    }
    switch(Genrefilm){
        case Unstoppable:
        printf("Film Horror\n");
        break;
        case Insidious:
            printf("Film World\n");
        break;
        case Us:
        printf("film kejut");
        break;
        }
    return 0;
    }


