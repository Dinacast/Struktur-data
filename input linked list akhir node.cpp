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

// Fungsi untuk menambahkan buku di akhir linked list
void insertDiAkhir(struct BukuNode** head, char* judul) {
    struct BukuNode* nodeBaru = buatNode(judul);
    if (*head == NULL) {  // Jika daftar masih kosong
        *head = nodeBaru;
        return;
    }

    struct BukuNode* temp = *head;
    while (temp->berikutnya != NULL) {  // Mencari node terakhir
        temp = temp->berikutnya;
    }
    temp->berikutnya = nodeBaru;  // Menambahkan node baru di akhir
}

// Fungsi untuk menghapus buku di akhir linked list
void deleteDiAkhir(struct BukuNode** head) {
    if (*head == NULL) {
        printf("Daftar buku kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    if ((*head)->berikutnya == NULL) {  // Jika hanya ada satu node
        printf("Buku yang dihapus: %s\n", (*head)->judul);
        free(*head);
        *head = NULL;
        return;
    }

    struct BukuNode* temp = *head;
    while (temp->berikutnya->berikutnya != NULL) {  // Mencari node kedua terakhir
        temp = temp->berikutnya;
    }

    struct BukuNode* nodeHapus = temp->berikutnya;  // Node terakhir
    printf("Buku yang dihapus: %s\n", nodeHapus->judul);
    free(nodeHapus);  // Menghapus node terakhir
    temp->berikutnya = NULL;  // Node kedua terakhir menjadi yang terakhir
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

    // Menambahkan beberapa buku di akhir
    insertDiAkhir(&head, "Cerita");
    insertDiAkhir(&head, "Bahasa");
    insertDiAkhir(&head, "Novel");

    // Menampilkan daftar buku setelah penambahan
    printf("Daftar Buku setelah penambahan:\n");
    tampilkanBuku(head);

    // Menghapus buku di akhir
    printf("\nMenghapus buku di akhir:\n");
    deleteDiAkhir(&head);

    // Menampilkan daftar buku setelah penghapusan
    printf("\nDaftar Buku setelah penghapusan:\n");
    tampilkanBuku(head);

    return 0;
}

