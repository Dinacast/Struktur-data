#include <stdio.h>

// Fungsi non-rekursif untuk perkalian
int perkalian(int a, int b) {
    int hasil = 0;
    for (int i = 0; i < b; i++) {
        hasil += a;
    }
    return hasil;
}

int main() {
    int a, b;
    printf ("angka = ");
    scanf ("%d", &a);
    printf ("angka yang dikakli dengan angka sebelumnya = ");
        scanf ("%d", &b);
    printf("Hasil perkalian %d dan %d (non-rekursif): %d\n", a, b, perkalian(a, b));
    return 0;
}

