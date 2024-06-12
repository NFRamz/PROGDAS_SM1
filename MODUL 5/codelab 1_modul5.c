#include<stdio.h>

int main(){
    char array[5][10]={"Neon","Gekko","Omen","Sage","Jett"};
    printf("Daftar Agen:\n");
    for(int urutan=0;urutan<5;urutan++){
        printf("Agen ke-%d: %s\n",urutan+1,array[urutan]);
    };
    array[3][0]='K';
    printf("\nDaftar Agen setelah perubahan:\n");
    for(int urutan=0;urutan<5;urutan++){
        printf("Agen ke-%d: %s\n",urutan+1,array[urutan]);
    };
    return 0;
}