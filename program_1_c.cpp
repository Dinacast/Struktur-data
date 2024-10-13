#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

// deklarasi type data

typedef int angka;
typedef float pecahan;
typedef char huruf;

// deskripsi program

int main()
{ 
system ("clear");
angka umur;
pecahan pecah;
huruf h;
huruf nama[10];

	printf("Masukkan umur anda : "); scanf("%d",&umur);
	printf("Umur anda adalah %d",umur);
	printf("\nMasukkan bilangan pecahan :");scanf("%f",&pecah);
	printf("Bilangan pecahan %f",pecah);
	printf("\nMasukkan huruf : ");h=getche();
	printf("\nHuruf anda %c",h);
	printf("\nMasukkan nama : ");scanf("%s",nama);
	printf("Nama anda %s",nama);
	getch();

}
