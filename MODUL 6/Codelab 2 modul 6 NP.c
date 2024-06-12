#include<stdio.h>

int main(){
    FILE *file = fopen("E:/TUGAS KULIAH/output/data_mahasiswa.txt", "w");

    fprintf(file, "Nama          :   Kiara Azzahra\n");
    fprintf(file, "NIM           :   202110370311426\n");
    fprintf(file, "Program Studi :   Informatika\n");
    fprintf(file, "\nNama          :   Annisa Artanti Widyadhana\n");
    fprintf(file, "NIM           :   202110370311217\n");
    fprintf(file, "Program Studi :   Teknik Elektro\n");
    fprintf(file, "\nNama          :   Na Jaemin\n");
    fprintf(file, "NIM           :   202110370311425\n");
    fprintf(file, "Program Studi :   Sistem Informasi\n");

    fclose(file);
    printf("Data mahasiswa telah ditulis kedalam file.");
    return 0;
}