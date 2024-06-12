#include <stdio.h>

int main() {
    int matriks1[3][3], matriks2[3][3], hasil[3][3];
    int pilihan, baris, kolom, samping;

    printf("Pilih operasi:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n");
    scanf("%d", &pilihan);
    switch(pilihan){
        case 1 :
            break;
        case 2 :
            break;
        case 3 :
            break;
            
        default: 
            printf("\nINPUTAN TIDAK VALID\n \n"); 
            return main();
            }

    printf("Masukkan elemen pada matriks pertama (3x3):\n");
    for(int baris = 0; baris < 3; baris++) {
        for(int kolom = 0; kolom < 3; kolom++) {
            scanf("%d", &matriks1[baris][kolom]);
        }
    }

    printf("Masukkan elemen pada matriks kedua (3x3):\n");
    for(int baris = 0; baris < 3; baris++) {
        for(int kolom = 0; kolom < 3; kolom++) {
            scanf("%d", &matriks2[baris][kolom]);
        }
    }
    printf("matriks pertama:\n");
    for(int baris = 0; baris < 3; baris++){
        for(int kolom = 0; kolom < 3; kolom++){
        printf("%d ", matriks1[baris][kolom]);

        }
        printf("\n");
    };

    printf("matriks kedua:\n");
    for(baris = 0; baris < 3; baris++){
        for(kolom = 0; kolom < 3; kolom++){
            printf("%d ",matriks2[baris][kolom]);
        }
        printf("\n");
    };

    switch(pilihan) {
        case 1:
         printf("Hasil penjumlahan matriks:\n");
            for(baris = 0; baris < 3; baris++) {
                for(kolom = 0; kolom < 3; kolom++) {
                    hasil[baris][kolom] = matriks1[baris][kolom] + matriks2[baris][kolom];
                     printf("%d ", hasil[baris][kolom]);

                }
                printf("\n");
            }
            break;
        case 2:
            printf("Hasil pengurangan matriks:\n");
            for(int baris = 0; baris < 3; baris++) {
                for(int kolom = 0; kolom < 3; kolom++) {
                    hasil[baris][kolom] = matriks1[baris][kolom] - matriks2[baris][kolom];
                    printf("%d ", hasil[baris][kolom]);
                }
                printf("\n");
            }
            break;
        case 3:
                      printf("Hasil perkalian matriks:\n");
            for(baris = 0; baris < 3; baris++) {
                for(kolom = 0; kolom < 3; kolom++) {
                    hasil[baris][kolom] = 0;
                    for(samping = 0; samping < 3; samping++) {
                        hasil[baris][kolom] += matriks1[baris][samping] * matriks2[samping][kolom];
                    }
                    printf("%d ", hasil[baris][kolom]);
                }
                printf("\n");
            }
            break;
        default: 
            printf("\nINPUTAN TIDAK VALID\n \n"); 
    }
    return 0;
}
