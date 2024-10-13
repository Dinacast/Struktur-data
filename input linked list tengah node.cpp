#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node buku
struct BukuNode {
    char judul[50];            // Menyimpan judul buku
    struct BukuNode* berikutnya; // Menunjuk ke node berikutnya
};

// Fungsi untuk membuat node buku baru
struct BukuNode* buatNode(char* judul) {
    struct BukuNode* nodeBaru = (struct BukuNode*)malloc(sizeof(struct BukuNode));
    strcpy(nodeBaru->judul, judul);
    nodeBaru->berikutnya = NULL;
    return nodeBaru;
}

// Fungsi untuk menambahkan buku di tengah linked list
void insertDiTengah(struct BukuNode** head, char* judul, int posisi) {
    struct BukuNode* nodeBaru = buatNode(judul);

    if (*head == NULL || posisi == 1) {
        nodeBaru->berikutnya = *head;
        *head = nodeBaru;
        return;
    }

    struct BukuNode* temp = *head;
    for (int i = 1; i < posisi - 1 && temp->berikutnya != NULL; i++) {
        temp = temp->berikutnya;
    }

    nodeBaru->berikutnya = temp->berikutnya;
    temp->berikutnya = nodeBaru;
}

// Fungsi untuk menghapus buku di posisi tengah linked list
void deleteDiTengah(struct BukuNode** head, int posisi) {
    if (*head == NULL) {
        printf("Daftar buku kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    if (posisi == 1) {
        struct BukuNode* nodeHapus = *head;
        *head = (*head)->berikutnya;
        printf("Buku yang dihapus: %s\n", nodeHapus->judul);
        free(nodeHapus);
        return;
    }

    struct BukuNode* temp = *head;
    for (int i = 1; i < posisi - 1 && temp->berikutnya != NULL; i++) {
        temp = temp->berikutnya;
    }

    if (temp->berikutnya == NULL) {
        printf("Posisi melebihi jumlah buku, tidak ada yang bisa dihapus.\n");
        return;
    }

    struct BukuNode* nodeHapus = temp->berikutnya;
    temp->berikutnya = nodeHapus->berikutnya;
    printf("Buku yang dihapus: %s\n", nodeHapus->judul);
    free(nodeHapus);
}

// Fungsi untuk menampilkan semua buku di linked list
void tampilkanBuku(struct BukuNode* head) {
    struct BukuNode* temp = head;
    if (temp == NULL) {
        printf("Daftar buku kosong.\n");
        return;
    }
    
    while (temp != NULL) {
        printf("Buku: %s\n", temp->judul);
        temp = temp->berikutnya;
    }
}

int main() {
    struct BukuNode* head = NULL;

    // Menambahkan beberapa buku di tengah
    insertDiTengah(&head, "Belajar Bahasa C", 1);  // Menambah di posisi pertama (awal)
    insertDiTengah(&head, "Matematika Dasar", 2);  // Menambah di posisi kedua
    insertDiTengah(&head, "Ilmu Pengetahuan Alam", 2);  // Menambah di posisi kedua lagi (di tengah)

    // Menampilkan daftar buku setelah penambahan
    printf("Daftar Buku setelah penambahan:\n");
    tampilkanBuku(head);

    // Menghapus buku di tengah
    printf("\nMenghapus buku di tengah:\n");
    deleteDiTengah(&head, 2);

    // Menampilkan daftar buku setelah penghapusan
    printf("\nDaftar Buku setelah penghapusan:\n");
    tampilkanBuku(head);

    return 0;
}

