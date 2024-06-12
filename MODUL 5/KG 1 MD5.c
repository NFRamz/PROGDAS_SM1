#include<stdio.h>

int main(){
    int jumlah_elemen,elemen,pengurutan,genap = 0, ganjil = 0;
    
    printf("Masukkan jumlah elemen yang akan diinput:");
    scanf("%d", &jumlah_elemen);
    
    int array[jumlah_elemen], arrayGenap[jumlah_elemen], arrayGanjil[jumlah_elemen];

    printf("Masukkan %d elemen:\n", jumlah_elemen);
    for(pengurutan = 0; pengurutan < jumlah_elemen; pengurutan++){
        scanf("%d", &elemen);
        array[pengurutan] = elemen; 
        if(elemen % 2 == 0){
            arrayGenap[genap] = array[pengurutan];
            genap++; 
        }else{
            arrayGanjil[ganjil] = array[pengurutan];
            ganjil++;
        }
    }

        printf("Bilangan ganjil dalam array:");
        for(pengurutan = 0; pengurutan < ganjil; pengurutan++){
            printf("%d ", arrayGanjil[pengurutan]);
        }
        printf("\nBilangan genap dalam array:");
        for(pengurutan = 0; pengurutan < genap; pengurutan++){
            printf("%d ", arrayGenap[pengurutan]);
        }
return 0;
}