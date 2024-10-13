#include <stdio.h>
#include <string.h>

#define MAX_STACK 6

typedef struct {
    int top;
    char data[MAX_STACK][50]; // Stack untuk menyimpan judul buku
} stack;

void stackKosong(stack *s) {
    s->top = -1;
}

// Mengecek apakah stack penuh
int isFull(stack *s) {
    if (s->top == MAX_STACK - 1) {
        return 1;
    }
    return 0;
}

// Mengecek apakah stack kosong
int isEmpty(stack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

// Mengosongkan stack
void clear(stack *s) {
    s->top = -1;
    printf("\nStack dikosongkan\n");
}

// Menambahkan buku ke stack
void push(stack *s, char value[]) {
    if (isFull(s)) {
        printf("Stack penuh, kosongkan dulu\n");
    } else {
        s->top++;
        strcpy(s->data[s->top], value);
        printf("Buku \"%s\" sudah dimasukkan ke atas stack\n", value);
    }
}

// Mengeluarkan buku dari stack
void pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack sudah kosong, bisa diisi\n");
    } else {
        printf("Buku yang diambil: \"%s\"\n", s->data[s->top]);
        s->top--;
    }
}

// Menampilkan buku teratas di stack
void top(stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong, tidak dapat menampilkan buku teratas\n");
    } else {
        printf("Buku paling atas adalah: \"%s\"\n", s->data[s->top]);
    }
}

// Mencetak semua buku dalam stack
void printStackSemua(stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong, tidak ada buku yang dapat dicetak\n");
    } else {
        printf("Isi stack adalah:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%s\n", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    stack s;
    stackKosong(&s);

    // Menambahkan beberapa buku ke stack
    push(&s, "Buku Bahasa");
    push(&s, "Buku Mesin");
    push(&s, "Buku Sejarah");
    push(&s, "Buku Cerita");
    
    // Mencetak semua buku
    printStackSemua(&s);

    // Mengambil beberapa buku dari stack
    pop(&s);
    printStackSemua(&s);
    pop(&s);
    printStackSemua(&s);

    // Menampilkan buku teratas
    top(&s);

    // Mengosongkan stack
    printf("\nStack coba dikosongkan menggunakan clear\n");
    clear(&s);

    // Mencoba mencetak semua buku lagi
    printf("Mencoba print semua stack lagi\n");
    printStackSemua(&s);
    printf("\n");

    return 0;
}

