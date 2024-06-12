#include <stdio.h>

int main() {
    char input[100];

    printf("Masukkan nama: ");
    scanf("%[^\n]s", input);

    printf("Karakter unik pada nama tersebut adalah: ");

    for (int i = 0; input[i]; i++) {
        int karakter = 1;
        for (int j = 0; j < i; j++) {
            if (input[i] == input[j]){
                karakter = 0;}
            }if(karakter){
            printf("%c", input[i]);}
    }

    return 0;
}
