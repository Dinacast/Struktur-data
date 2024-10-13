#include <stdio.h>
// Fungsi Rekursif
int pembagian(int a, int b) {
  if (a < b) {
    return 0; // Jika a lebih kecil dari b, hasilnya 0
  } else {
    return 1 + pembagian(a - b, b);
  }
}
main(){
    int a, b;
    printf ("Angka = ");
    scanf ("%d", &a);
    printf ("angka yang akan dibagi dengan angka sebelumnya = ");
        scanf ("%d", &b);
    printf ("Hasil = %d\n", pembagian (a, b));
}
