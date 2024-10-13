#include <stdio.h>
// Rekursif
int perkalian (int a, int b) {
    if (b == 0) {
        return 0;
    } else {
        return a + perkalian(a, b - 1);
    }
}
main(){
	int a, b;
	printf ("angka = ");
	scanf ("%d", &a);
	printf ("angka yang akan dikali dengan angka sebelumnya = ");
		scanf ("%d", &b);
	printf ("Hasil = %d\n", perkalian (a, b));
}
