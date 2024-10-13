#include <stdio.h>
int pembagianNonRekursif(int angka1, int angka2) {
    if (angka2 == 0) {
        printf("Pembagi tidak boleh 0 (nol)!\n");
        return 0;
    }
    int hasil = 0;
    while (angka1 >= angka2) {
        angka1 -= angka2;
        hasil++;
    }
    return hasil;
}
int pembagianRekursif(int angka1, int angka2) {
    if (angka2 == 0) {
        printf("Pembagi tidak boleh 0 (nol)!\n");
        return 0;
    }
    if (angka1 < angka2) {
        return 0;
    } else {
        return 1 + pembagianRekursif(angka1 - angka2, angka2);
    }
}
#include <stdio.h>

int main() {
    int angka1, angka2;

    printf("Angka yang akan dibagi: ");
    scanf("%d", &angka1);
    printf("Angka pembagi: ");
    scanf("%d", &angka2);

    if (angka2 == 0) {
        printf("Pembagian dengan nol tidak terdefinisi.\n");
    } else {
        int hasilNonRekursif = pembagianNonRekursif(angka1, angka2);
        int hasilRekursif = pembagianRekursif(angka1, angka2);

        printf("Hasil pembagian (non-rekursif): %d\n", hasilNonRekursif);
        printf("Hasil pembagian (rekursif): %d\n", hasilRekursif);
    }

    return 0;
}
