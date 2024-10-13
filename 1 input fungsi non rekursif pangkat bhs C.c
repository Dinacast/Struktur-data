#include <stdio.h>
int fpangkat (int angka, int pangkat) {
    int i;
    int hasil = 1;
    for (i = 1; i <= pangkat; i = i + 1){
        hasil = hasil * angka;
    }
    return hasil;
}
main(){
    int angka, pangkat;
    printf ("Angka = ");
    scanf ("%d", &angka);
    printf ("Pangkat = ");
        scanf ("%d", &pangkat);
    printf ("Hasil = %d\n", fpangkat (angka, pangkat));
}