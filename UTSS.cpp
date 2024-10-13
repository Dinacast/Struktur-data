#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KONTAK 10 // Jumlah maksimum kontak yang dapat disimpan

// Struktur untuk menyimpan kontak
typedef struct Kontak {
    char nama[10]; // Nama kontak
    char nomor[20]; // Nomor telepon kontak
} Kontak;

// ADT untuk daftar kontak
typedef struct {
    Kontak kontak[MAX_KONTAK]; // Array untuk menyimpan kontak
    int jumlah; // Jumlah kontak yang tersimpan
} ListKontak;

// Prototipe fungsi
void initListKontak(ListKontak *list);
void tambahKontak(ListKontak *list, const char *nama, const char *nomor);
void menampilkanKontak(const ListKontak *list);
void cariKontak(const ListKontak *list, const char *nama);
int cariKontakRekursif(const ListKontak *list, const char *nama, int index);
void dequeue(ListKontak *list);
void hapusKontak(ListKontak *list);

// Inisialisasi daftar kontak
void initListKontak(ListKontak *list) {
    list->jumlah = 0; // Inisialisasi jumlah kontak
}

// Menambahkan kontak baru
void tambahKontak(ListKontak *list, const char *nama, const char *nomor) {
    if (list->jumlah >= MAX_KONTAK) {
        printf("Daftar kontak sudah penuh.\n");
        return;
    }

    // Enqueue: Menambahkan kontak baru ke belakang queue
    strcpy(list->kontak[list->jumlah].nama, nama);
    strcpy(list->kontak[list->jumlah].nomor, nomor);
    list->jumlah++; // Increment jumlah kontak

    printf("Kontak berhasil ditambahkan.\n");
}

// Menampilkan semua kontak
void menampilkanKontak(const ListKontak *list) {
    if (list->jumlah == 0) {
        printf("Daftar kontak kosong.\n");
        return;
    }

    printf("Daftar Kontak:\n");
    for (int i = 0; i < list->jumlah; i++) {
        printf("Nama: %s, Nomor Telepon: %s\n", list->kontak[i].nama, list->kontak[i].nomor);
    }
}

// Mencari kontak berdasarkan nama
void cariKontak(const ListKontak *list, const char *nama) {
    if (cariKontakRekursif(list, nama, 0) == -1) {
        printf("Kontak dengan nama '%s' tidak ditemukan.\n", nama);
    }
}

// Fungsi rekursif untuk mencari kontak
int cariKontakRekursif(const ListKontak *list, const char *nama, int index) {
    if (index >= list->jumlah) {
        return -1; // Kontak tidak ditemukan
    }
    if (strcmp(list->kontak[index].nama, nama) == 0) {
        printf("Kontak Ditemukan: Nama: %s, Nomor Telepon: %s\n", list->kontak[index].nama, list->kontak[index].nomor);
        return index; // Kontak ditemukan
    }
    return cariKontakRekursif(list, nama, index + 1); // Pemanggilan diri untuk kontak berikutnya
}

// Menghapus kontak dari queue
void dequeue(ListKontak *list) {
    if (list->jumlah == 0) {
        printf("Daftar kontak kosong. Tidak ada yang bisa dihapus.\n");
        return;
    }

    // Menghapus kontak pertama
    printf("Kontak dengan nama '%s' berhasil dihapus.\n", list->kontak[0].nama);
    
    // Geser kontak ke kiri untuk menghapus yang pertama
    for (int i = 1; i < list->jumlah; i++) {
        list->kontak[i - 1] = list->kontak[i];
    }

    list->jumlah--; // Decrement jumlah kontak
}

// Membersihkan seluruh daftar kontak
void hapusKontak(ListKontak *list) {
    list->jumlah = 0; // Reset jumlah kontak
}

int main() {
    ListKontak listkontak;
    initListKontak(&listkontak);

    int choice;
    char nama[10];
    char nomor[20];

    while (1) {
        printf("\nKelompok 7\n");
        printf("Nama : Lindra Oktavia Sianturi (23081010027)\n");
        printf("Nama : Dina Cahyanti (23081010084)\n");
        printf("\nMenu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Tampilkan Semua Kontak\n");
        printf("3. Cari Kontak\n");
        printf("4. Hapus Kontak\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar();  // Menghapus karakter newline dari buffer

        switch (choice) {
            case 1:
                printf("Masukkan Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0'; // Menghapus newline dari input

                printf("Masukkan Nomor Telepon: ");
                fgets(nomor, sizeof(nomor), stdin);
                nomor[strcspn(nomor, "\n")] = '\0'; // Menghapus newline dari input

                tambahKontak(&listkontak, nama, nomor);
                break;
            case 2:
                menampilkanKontak(&listkontak);
                break;
            case 3:
                printf("Masukkan Nama untuk Dicari: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0'; // Menghapus newline dari input

                cariKontak(&listkontak, nama);
                break;
            case 4:
                dequeue(&listkontak);
                break;
            case 5:
                hapusKontak(&listkontak);  // Membersihkan data
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}