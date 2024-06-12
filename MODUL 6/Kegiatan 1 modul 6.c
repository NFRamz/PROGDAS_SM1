#include<stdio.h> // Mengimpor file header standar input-output
#include<stdlib.h> // Mengimpor file header standar library
#include<conio.h> // Mengimpor file header console input-output

// Deklarasi fungsi
int create_new_book(), Display_list_book(), update_book_information(), delete_book(), menu_pintasan(), keyakinan();

// Deklarasi variabel global
int ID_buku, ID_duplikat, ID_tersimpan, Jumlah_halaman, pilihan, update_id_buku, hapus_ID;
char teks[300], Judul_buku[300], Nama_author[300], Genre_buku[300], teks_baru[300];

int main(){ // Fungsi utama
    printf("==== LIBRARY BOOK ====\n"); // Menampilkan teks ke layar
    printf("Selamat datang di library book, silahkan pilih menu yang telah tersedia dibawah ini.\n");
    printf("\n1.Create new book \n2.Display list book \n3.Update book information \n4.Delete book \n5.Keluar \n \n");
    pilihan = getch() - '0'; // Membaca input dari pengguna
    switch(pilihan){ // Memilih aksi berdasarkan input pengguna
        case 1:
            system("cls"); // Membersihkan layar
            create_new_book(); // Memanggil fungsi untuk membuat buku baru
        break;
        
        case 2:
            system("cls");
            Display_list_book(); // Memanggil fungsi untuk menampilkan daftar buku
        break;

        case 3:
            system("cls");
            update_book_information(); // Memanggil fungsi untuk memperbarui informasi buku
        break;
        case 4:
            system("cls");
            delete_book(); // Memanggil fungsi untuk menghapus buku
        break;
        case 5:
            keyakinan(); // Memanggil fungsi untuk keluar
        break;
        default :
        printf("Menu tidak tersedia. \nPilih angka 1-4.\n \n");
        system("pause"); // Menahan layar
        system("cls");
        return main(); // Mengembalikan ke fungsi utama
    }
    return 0; // Mengakhiri program
}

int create_new_book(){ // Fungsi untuk membuat buku baru
    printf("==== Buat Buku Baru ====\n");
    
    FILE *file = fopen("Library_books.txt", "r"); // Membuka file dalam mode baca
    
    printf("a. ID buku        :");
    scanf("%d", &ID_buku); // Membaca input dari pengguna
    
    ID_duplikat = 0;
    while(fgets(teks, sizeof(teks), file)){ // Membaca file baris per baris
        sscanf(teks, "a. ID buku         :   %d\n", &ID_tersimpan); // Memindai string dari file
        if(ID_buku == ID_tersimpan){ // Memeriksa apakah ID buku sudah ada
            ID_duplikat = 1;
            break;
        }

    }
    fclose(file); // Menutup file

    if(ID_duplikat){
        printf("ID buku ini sudah ada.\n");
        return create_new_book(); // Mengembalikan ke fungsi ini jika ID buku sudah ada
    }
    file = fopen("Library_books.txt", "a"); // Membuka file dalam mode tambah

    getchar();
    printf("b. Judul buku     :");
    scanf("%[^\n]s", Judul_buku); // Membaca input dari pengguna

    getchar();
    printf("c. Nama author    :");
    scanf("%[^\n]s", Nama_author); // Membaca input dari pengguna

    getchar();
    printf("d. Jumlah halaman :");
    scanf("%d", &Jumlah_halaman); // Membaca input dari pengguna

    getchar();
    printf("e. Genre buku     :");
    scanf("%[^\n]s", Genre_buku); // Membaca input dari pengguna

    fprintf(file, "a. ID buku         :   %d\n", ID_buku); // Menulis ke file
    fprintf(file, "b. Judul buku      :   %s\n", Judul_buku);
    fprintf(file, "c. Nama author     :   %s\n", Nama_author);
    fprintf(file, "d. Jumlah halaman  :   %d\n", Jumlah_halaman);
    fprintf(file, "e. Genre_buku      :   %s\n", Genre_buku);
    fprintf(file, "\n");
    fclose(file); // Menutup file
    printf("Buku sudah ditambahkan!\n \n ");
    menu_pintasan(); // Memanggil fungsi menu pintasan
    system("cls");
    return main(); // Mengembalikan ke fungsi utama
}

int Display_list_book(){ // Fungsi untuk menampilkan daftar buku
    printf("=== List Buku ===\n");
    FILE *file = fopen("Library_books.txt", "r"); // Membuka file dalam mode baca
    while(fgets(teks, sizeof(teks), file)){ // Membaca file baris per baris
        printf("%s", teks); // Menampilkan teks ke layar
    }
    fclose(file); // Menutup file

    printf("[1] untuk menampilkan menu pintasan     [0] untuk kembali ke menu utama \n");
    pilihan = getch() - '0'; // Membaca input dari pengguna
    switch(pilihan){
    case 0:
        system("cls");
        return main(); // Mengembalikan ke fungsi utama
    break;
    
    case 1:
        return menu_pintasan(); // Memanggil fungsi menu pintasan
    break;
    }
    return main(); // Mengembalikan ke fungsi utama
}


int update_book_information() { // Fungsi untuk memperbarui informasi buku
    printf("=== Update Informasi Buku ===\n");
    FILE *file = fopen("Library_books.txt", "r"); // Membuka file dalam mode baca
    FILE *update = fopen("update.txt", "w"); // Membuka file baru dalam mode tulis

    printf("Masukkan ID buku yang ingin Anda perbarui: ");
    scanf("%d", &ID_buku); // Membaca input dari pengguna
    while(fgets(teks, sizeof(teks), file)) { // Membaca file baris per baris
        sscanf(teks, "a. ID buku : %d", &update_id_buku); // Memindai string dari file
        if(update_id_buku == ID_buku) { // Memeriksa apakah ID buku sama dengan ID yang ingin diperbarui
            printf("Masukkan ID buku baru: ");
            scanf("%d", &update_id_buku); // Membaca input dari pengguna
            sprintf(teks_baru, "a. ID buku         :   %d\n", update_id_buku); // Menyimpan string baru ke variabel
            fputs(teks_baru, update); // Menulis string baru ke file
            printf("ID buku sudah diganti/diperbarui\n \n");
        } else {
            fputs(teks, update); // Menulis string asli ke file
        }
    }

    fclose(file); // Menutup file
    fclose(update); // Menutup file
    remove("Library_books.txt"); // Menghapus file asli
    rename("update.txt", "Library_books.txt"); // Mengubah nama file baru menjadi nama file asli
    menu_pintasan(); // Memanggil fungsi menu pintasan

    system ("cls"); // Membersihkan layar
    return main(); // Mengembalikan ke fungsi utama
}

int delete_book() { // Fungsi untuk menghapus buku
    printf("=== Hapus Buku ===\n");
    FILE *file = fopen("Library_books.txt", "r"); // Membuka file dalam mode baca
    FILE *update = fopen("update.txt", "w"); // Membuka file baru dalam mode tulis

    printf("Masukkan ID buku yang ingin Anda hapus: ");
    scanf("%d", &ID_buku); // Membaca input dari pengguna
    int pencarian = 0;
    while(fgets(teks, sizeof(teks), file)) { // Membaca file baris per baris
        sscanf(teks, "a. ID buku : %d", &hapus_ID); // Memindai string dari file
        if(hapus_ID != ID_buku) { // Memeriksa apakah ID buku tidak sama dengan ID yang ingin dihapus
            fputs(teks, update); // Menulis string asli ke file
        }else{
            pencarian = 1; // Menandai bahwa buku ditemukan
        }
    }

    fclose(file); // Menutup file
    fclose(update); // Menutup file
    remove("Library_books.txt"); // Menghapus file asli
    rename("update.txt", "Library_books.txt"); // Mengubah nama file baru menjadi nama file asli

    if(pencarian){
        printf("Buku dengan ID %d telah dihapus.\n \n \n", ID_buku); // Menampilkan pesan bahwa buku telah dihapus
    }else{printf("Buku dengan ID %d tidak ada/udah terhapus\n \n \n", ID_buku);} // Menampilkan pesan bahwa buku tidak ditemukan
    menu_pintasan(); // Memanggil fungsi menu pintasan
    system("cls"); // Membersihkan layar
    return main(); // Mengembalikan ke fungsi utama
}

int menu_pintasan(){ // Fungsi untuk menampilkan menu pintasan
    printf("== Menu pintasan ==\n");
    printf("[0] Menu utama \n[1] Buat buku baru \n[2] Tampilkan buku yang terdaftar \n[3] Update informasi buku \n[4] Hapus buku \n");
    printf("Masukkan pilihan : ");
    scanf("%d",&pilihan); // Membaca input dari pengguna
    switch(pilihan){ // Memilih aksi berdasarkan input pengguna
        case 0:
            system("cls"); // Membersihkan layar
            return main(); // Mengembalikan ke fungsi utama
        break;

        case 1:
            return create_new_book(); // Memanggil fungsi untuk membuat buku baru
        break;

        case 2:
            return Display_list_book(); // Memanggil fungsi untuk menampilkan daftar buku
        break;

        case 3:
            return update_book_information(); // Memanggil fungsi untuk memperbarui informasi buku
        break;

        case 4:
            return delete_book(); // Memanggil fungsi untuk menghapus buku
        break;
    }
    return 0; // Mengakhiri program
}

int keyakinan(){ // Fungsi untuk keluar dari program
    printf("Apakah yakin ingin keluar ? \n[1] Ya    [0] Tidak\n");
    pilihan = getch() - '0'; // Membaca input dari pengguna
    switch(pilihan){ // Memilih aksi berdasarkan input pengguna
    case 0:
        system("cls"); // Membersihkan layar
         return main(); // Mengembalikan ke fungsi utama
    case 1:
        return 0; // Mengakhiri program
     default:
     printf("Pilih 0 atau 1\n \n");   
    }
    return keyakinan(); // Mengembalikan ke fungsi ini jika input pengguna tidak valid
}
