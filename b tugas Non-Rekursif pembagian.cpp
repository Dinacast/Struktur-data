#include <stdio.h>
// Fungsi Non-Rekursif
int pembagian_non (int a, int b) {
  int hasil = 0;
  while (a >= b) {
    a = a - b;
    hasil = hasil + 1;
  }
  return hasil;
}
main(){
    int a, b;
    printf ("Angka = ");
    scanf ("%d", &a);
    printf ("angka yang akan dibagi dengan angka sebelumnya = ");
        scanf ("%d", &b);
    printf ("Hasil = %d\n", pembagian_non (a, b));
}
