#include <stdio.h>
#include <conio.h>
#include <string.h>

// deklarasi type data
typedef char  String[50];

int main() {
	String tempatLahir, nama, hobi;
	int tahunLahir, umur;
	
	//input data 
	printf("Masukkan tempat lahir :");
	scanf(" %[^\n]", tempatLahir);
	
	printf("Masukkan tahun lahir :");
	scanf(" %d", &tahunLahir);
	
	printf("Masukkan nama :");
	scanf(" %[^\n]", nama);
	
	printf("Masukkan hobi :");
	scanf(" %[^\n]", hobi);
	
	//menghitung umur dengan menambahkan tahun 2024
	umur = 2024 - tahunLahir;
	
	//output data
	printf("\nData Diri:\n");
	printf("Nama 			: %s\n", nama);
	printf("tempat Lahir 		: %s\n", tempatLahir);
	printf("Tahun Lahir 		: %d\n", tahunLahir);
	printf("Umur di tahun 2024 	: %d\n", umur);
	printf("Hobi		 	: %s\n", hobi);
	
	getch();
	return 0;
}
