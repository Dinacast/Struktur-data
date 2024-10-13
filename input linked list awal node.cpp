#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node buku
struct BukuNode {
    char judul[50];            // judul buku
    struct BukuNode* berikutnya; // buku berikutnya
};

// Membuat node buku baru
struct BukuNode* buatNode(char* judul) {
    struct BukuNode* nodeBaru = (struct BukuNode*)malloc(sizeof(struct BukuNode));
    strcpy(nodeBaru->judul, judul);
    nodeBaru->berikutnya = NULL;
    return nodeBaru;
}

// Fungsi untuk menambahkan buku di awal daftar
void tambahDiAwal(struct BukuNode** head, char* judul) {
    struct BukuNode* nodeBaru = buatNode(judul);
    nodeBaru->berikutnya = *head;
    *head = nodeBaru;
}
// Fungsi untuk menampilkan semua buku di daftar
void tampilkanBuku(struct BukuNode* head) {
    struct BukuNode* temp = head;
    while (temp != NULL) {
        printf("Buku: %s\n", temp->judul);
        temp = temp->berikutnya;
    }
}


int main() {
    struct BukuNode* head = NULL;

    // Menambahkan buku di awal
    tambahDiAwal(&head, "Struktur Data");
    tambahDiAwal(&head, "Sastra");

    // Menampilkan daftar buku
    printf("Daftar Buku:\n");
    tampilkanBuku(head);

    return 0;
}

