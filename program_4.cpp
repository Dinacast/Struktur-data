#include <stdio.h>
#include <conio.h>
#include <string.h>

struct AlatTransportasi {
	char nama[50];
	char tujuan[90];
};

int main() {
	int n, i;
	
	printf("Masukkan jumlah alat transportasi : ");
	scanf("%d", &n);
	
	//deklarasi struct
	struct AlatTransportasi transportasi[n];
	
	//masukkan data alat transportasi
	for(i = 1; i <= n; i++) {
		printf("\nMasukkan nama alat transportasi ke-%d: ", i);
		scanf(" %[^\n]", transportasi[i-1].nama); //" %[^\n]" untuk membaca string tanpa spasi
		
		printf("\nMasukkan tujuan %d: ",i);
		scanf(" %[^\n]", transportasi[i-1].tujuan);
	}
	//output
	printf("\nData Alat Transportasi: \n");
	for(i =1; i <= n; i++) {
		printf("\nAlat transportasi ke%d:\n",i);
		printf("Nama	: %s\n", transportasi[i-1].nama);
		printf("Tujuan	: %s\n", transportasi[i-1].tujuan);
	}
	getch();
	return 0;
}
