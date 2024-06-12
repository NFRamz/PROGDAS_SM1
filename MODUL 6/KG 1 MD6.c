#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int create_new_book(), Display_list_book(), update_book_information(), delete_book(), menu_pintasan(), keyakinan(), tampilkan_menu_pintasan();

int ID_buku, ID_duplikat, ID_tersimpan, Jumlah_halaman, pilihan, update_id_buku, hapus_ID;
char teks[300], Judul_buku[300], Nama_author[300], Genre_buku[300], teks_baru[300];

int main(){
    printf("==== LIBRARY BOOK ====\n");
    printf("Selamat datang di library book, silahkan pilih menu yang telah tersedia dibawah ini.\n");
    printf("\n1.Create new book \n2.Display list book \n3.Update book information \n4.Delete book \n5.Keluar \n \n");
    pilihan = getch() - '0';
    switch(pilihan){
        case 1:
            system("cls");
            create_new_book();
        break;
        
        case 2:
            system("cls");
            Display_list_book();
        break;

        case 3:
            system("cls");
            update_book_information();
        break;
        case 4:
            system("cls");
            delete_book();
        break;
        case 5:
            keyakinan();
        break;
        default :
        printf("Menu tidak tersedia. \nPilih angka 1-4.\n \n");
        system("pause");
        system("cls");
        return main();
    }
    return 0;
}

int create_new_book(){
    printf("==== Buat Buku Baru ====\n");
    
    FILE *file = fopen("Library_books.txt", "r");
    
    printf("a. ID buku        :");
    scanf("%d", &ID_buku);
    
    ID_duplikat = 0;
    while(fgets(teks, sizeof(teks), file)){
        sscanf(teks, "a. ID buku         :   %d\n", &ID_tersimpan);
        if(ID_buku == ID_tersimpan){
            ID_duplikat = 1;
             printf("ID buku ini sudah ada.\n");
             return create_new_book();
            break;
        }

    }
    fclose(file);

    file = fopen("Library_books.txt", "a");


    getchar();
    printf("b. Judul buku     :");
    scanf("%[^\n]s", Judul_buku);

    getchar();
    printf("c. Nama author    :");
    scanf("%[^\n]s", Nama_author);

    getchar();
    printf("d. Jumlah halaman :");
    scanf("%d", &Jumlah_halaman);

    getchar();
    printf("e. Genre buku     :");
    scanf("%[^\n]s", Genre_buku);

    fprintf(file, "a. ID buku         :   %d\n", ID_buku);
    fprintf(file, "b. Judul buku      :   %s\n", Judul_buku);
    fprintf(file, "c. Nama author     :   %s\n", Nama_author);
    fprintf(file, "d. Jumlah halaman  :   %d\n", Jumlah_halaman);
    fprintf(file, "e. Genre_buku      :   %s\n", Genre_buku);
    fprintf(file, "\n");
    fclose(file);
    printf("Buku sudah ditambahkan.\n \n ");
    tampilkan_menu_pintasan();
    return main();
}

int Display_list_book(){
    printf("=== List Buku ===\n");
    FILE *file = fopen("Library_books.txt", "r");
    while(fgets(teks, sizeof(teks), file)){
        printf("%s", teks);
    }
    fclose(file);
    tampilkan_menu_pintasan();

    return main();
}

int update_book_information() {
    printf("=== Update Informasi Buku ===\n");
    FILE *file = fopen("Library_books.txt", "r");
    FILE *update = fopen("update.txt", "w");

    printf("Masukkan ID buku yang ingin Anda perbarui: ");
    scanf("%d", &ID_buku); 
    while(fgets(teks, sizeof(teks), file)) {
        sscanf(teks, "a. ID buku : %d", &update_id_buku);
        if(update_id_buku == ID_buku) {
            printf("Masukkan ID buku baru: ");
            scanf("%d", &update_id_buku);
            sprintf(teks_baru, "a. ID buku         :   %d\n", update_id_buku);
            fputs(teks_baru, update);
             printf("ID buku sudah diganti/diperbarui\n \n");
        } else {
            fputs(teks, update);
        }
    }

    
    fclose(file);
    fclose(update);
    remove("Library_books.txt");
    rename("update.txt", "Library_books.txt");
    tampilkan_menu_pintasan();

    return main();
}

int delete_book() {
    printf("=== Hapus Buku ===\n");
    FILE *file = fopen("Library_books.txt", "r");
    FILE *update = fopen("update.txt", "w");

    printf("Masukkan ID buku yang ingin dihapus: ");
    scanf("%d", &ID_buku);
    int pencarian = 0;
    while(fgets(teks, sizeof(teks), file)) {
        sscanf(teks, "a. ID buku : %d", &hapus_ID);
        if(hapus_ID == ID_buku) {
            pencarian = 1;
            printf("Buku dengan ID %d telah dihapus.\n \n \n", ID_buku);
        }else{
            fputs(teks, update);
            printf("Buku dengan ID %d tidak ada/udah terhapus\n \n \n", ID_buku);
        }
    }

    fclose(file);
    fclose(update);
    remove("Library_books.txt");
    rename("update.txt", "Library_books.txt");

    tampilkan_menu_pintasan();
    system("cls");
    return main();
}

int menu_pintasan(){
    printf("== Menu pintasan ==\n");
    printf("[0] Menu utama \n[1] Buat buku baru \n[2] Tampilkan buku yang terdaftar \n[3] Update informasi buku \n[4] Hapus buku \n");
    printf("Masukkan pilihan : ");
    scanf("%d",&pilihan);
    switch(pilihan){
        case 0:
            system("cls");
            return main();
        break;

        case 1:
            return create_new_book();
        break;

        case 2:
            return Display_list_book();
        break;

        case 3:
            return update_book_information();
        break;

        case 4:
            return delete_book();
        break;
        default:
        printf("Menu tidak ada.\n \n");
    }
    return menu_pintasan();
}

int keyakinan(){
    printf("Apakah yakin ingin keluar ? \n[1] Ya    [0] Tidak\n");
    pilihan = getch() - '0';
    switch(pilihan){
    case 0:
        system("cls");
         return main();
    case 1:
        return 0;
     default:
     printf("Pilih 0 atau 1\n \n");   
    }
    return keyakinan();
}

int tampilkan_menu_pintasan(){
    printf("[1] untuk menampilkan menu pintasan     [0] untuk kembali ke menu utama \n");
    pilihan = getch() - '0';
    switch(pilihan){
    case 0:
        system("cls");
        return main();
    break;
    
    case 1:
        return menu_pintasan();
    break;
    default:
        printf("Pilih 1 atau 0\n \n");
        break;
    }
    return tampilkan_menu_pintasan();
}