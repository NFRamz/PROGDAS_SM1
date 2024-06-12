#include<stdio.h>

int main(){
    int matriks_1[2][2]={{1,2},{3,4}};
    int matriks_2[2][2]={{5,6},{7,8}};
    
    matriks_1[0][0]= matriks_1[0][0] + matriks_2[0][0];
    matriks_1[1][0]= matriks_1[0][1] + matriks_2[0][1];
    matriks_2[0][0]= matriks_1[0][1] + matriks_2[1][1];
    matriks_2[1][0]= matriks_1[1][1] + matriks_2[1][1];

    printf("Hasil penjumlahan matriks:\n");
    printf("%d %d\n%d %d", matriks_1[0][0], matriks_1[1][0], matriks_2[0][0], matriks_2[1][0]);
    
return 0;
}