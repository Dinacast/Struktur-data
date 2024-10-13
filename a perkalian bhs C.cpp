#include <stdio.h>
int perkalian_non_rekursif(int angka1, int angka2) {
    int hasil = 0;
    for (int i = 0; i < angka2; i++) {
        hasil += angka1;
    }
    return hasil;
}

int perkalian_rekursif(int angka1, int angka2) {
    if (angka2 == 0) {
        return 0; // Note: jika angka2 adalah 0, hasil perkalian adalah 0
    } else {
        return angka1 + perkalian_rekursif(angka1, angka2-1);
    }
}
#include <stdio.h>

int main() {
    int angka1, angka2;

    printf("Angka: ");
    scanf("%d", &angka1);
    printf("Masukkan angka yang akan dikali dengan angka sebelumnya: ");
    scanf("%d", &angka2);

    int hasilNonRekursif = perkalian_non_rekursif(angka1, angka2);
    int hasilRekursif = perkalian_rekursif(angka1, angka2);

    printf("Hasil perkalian (non-rekursif): %d\n", hasilNonRekursif);
    printf("Hasil perkalian (rekursif): %d\n", hasilRekursif);

    return 0;
}
