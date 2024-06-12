#include<stdio.h>

int main(){
    int nilai_N,nilai_pertama=1,hasil_penjumlahan;
    printf("Masukkan nilai N:");
    scanf("%d",&nilai_N);

    while(nilai_pertama<=nilai_N){
        hasil_penjumlahan+=nilai_pertama;
        nilai_pertama++;
    }
        printf("Jumlah angka dari 1 hingga %d adalah %d",nilai_N,hasil_penjumlahan);
    return 0;
}