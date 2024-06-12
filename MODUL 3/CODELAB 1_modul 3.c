#include <stdio.h>

int main() {
    int nilai; // Mengubah tipe data dari String menjadi int
    printf("Masukkan nilai Anda: ");
    scanf("%d", &nilai);

    if (nilai >= 0 && nilai <= 100) {
        if (nilai >= 90) {// mengubsh <= menjadi >=
            printf("Nilai Anda adalah A.\n"); // Menambahkan titik koma di akhir baris
        } else if (nilai >= 80) { // Mengubah else menjadi else if
            printf("Nilai Anda adalah B.\n"); // Menambahkan titik koma di akhir baris
        } else if (nilai >= 70) { // Mengubah else menjadi else if
            printf("Nilai Anda adalah C.\n"); // Menambahkan titik koma di akhir baris
        } else if (nilai >= 60) { // Mengubah kondisi dari > menjadi >= dan mengubah else menjadi else if
            printf("Nilai Anda adalah D.\n"); // Menambahkan titik koma di akhir baris
        } else {
            printf("Nilai Anda adalah E.\n"); // Menambahkan titik koma di akhir baris
        }//menghapus break dan default karena kode ini tidak pakai switch
    } else { 
        printf("Input tidak valid. Nilai harus berada dalam rentang 0 hingga 100.\n"); // Menghapus 'if' yang tidak perlu dan menambahkan titik koma di akhir baris
    } printf("Program Selesai");// ini dipindahkan yang awalnya di default dpindahkan keluar

    return 0;
}
