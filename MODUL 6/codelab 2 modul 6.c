#include <stdio.h>
    void pertanyaan_untuk_menjalankan_looping(), input_data();
    char nama[100], prodi[100];
    int nim, jumlah_data_yang_ingin_diinput;

int main() {
 
    FILE *file = fopen("data_mahasiswa.txt", "w");

    if (file != NULL) {
        pertanyaan_untuk_menjalankan_looping();
        for(int input = 0; input < jumlah_data_yang_ingin_diinput; input++){
  
            input_data();
            
            
            fprintf(file, "\nNama: %s\n", nama);
            fprintf(file, "NIM: %d\n", nim);
            fprintf(file, "Program Studi: %s\n", prodi);



         }
            printf("\nData mahasiswa telah ditulis ke dalam file.");
            fclose(file);
        } else {
        printf("Tidak dapat membuka file data_mahasiswa.txt\n");
    }
    return 0;
}


void pertanyaan_untuk_menjalankan_looping(){
        printf("Berapa data yang ingin di input ?  ");
        scanf("%d", &jumlah_data_yang_ingin_diinput);

}

void input_data(){
            
            getchar();
            printf("\nMasukkan nama: ");
            scanf("%[^\n]s", nama);
            
            printf("Masukkan NIM: ");
            scanf("%d", &nim);

            getchar();
            printf("Masukkan program studi: ");
            scanf("%[^\n]s", prodi);
}