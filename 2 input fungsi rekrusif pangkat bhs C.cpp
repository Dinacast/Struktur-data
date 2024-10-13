//Contoh fungsi rekursif

#include <stdio.h>
int fpangkat (int angka, int pangkat){
	if (pangkat == 0){
	return 1;
	}
	else {
		return fpangkat (angka, pangkat -1)*angka;
	}

}
main(){
	int angka, pangkat;
	printf ("Angka = ");
	scanf ("%d", &angka);
	printf ("Pangkat = ");
		scanf ("%d", &pangkat);
	printf ("Hasil = %d\n", fpangkat (angka,pangkat));
}
