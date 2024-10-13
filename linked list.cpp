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

// Fungsi untuk menambahkan buku di awal linked list
void insertDiAwal(struct BukuNode** head, char* judul) {
    struct BukuNode* nodeBaru = buatNode(judul);
    nodeBaru->berikutnya = *head;
    *head = nodeBaru;  // Buku baru menjadi head (awal) dari linked list
}

// Fungsi untuk menghapus buku di awal linked list
void deleteDiAwal(struct BukuNode** head) {
    if (*head == NULL) {
        printf("Tidak ada buku yang bisa dihapus, daftar kosong.\n");
        return;
    }
    
    struct BukuNode* nodeHapus = *head;  // Simpan node yang akan dihapus
    *head = (*head)->berikutnya;         // Head sekarang pindah ke node berikutnya
    printf("Buku yang dihapus: %s\n", nodeHapus->judul);
    free(nodeHapus);  // Hapus node lama dari memori
}

// Fungsi untuk menampilkan daftar buku
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
    struct BukuNode* head = NULL;  // Awal dari linked list (masih kosong)

    // Menambahkan beberapa buku di awal
    insertDiAwal(&head, "Bahasa");
    insertDiAwal(&head, "Cerita");
    insertDiAwal(&head, "Novel");

    // Menampilkan daftar buku setelah penambahan
    printf("Daftar Buku setelah penambahan:\n");
    tampilkanBuku(head);

    // Menghapus buku di awal
    printf("\nMenghapus buku di awal:\n");
    deleteDiAwal(&head);

    // Menampilkan daftar buku setelah penghapusan
    printf("\nDaftar Buku setelah penghapusan:\n");
    tampilkanBuku(head);

    return 0;
}

