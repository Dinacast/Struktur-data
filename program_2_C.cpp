#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
	//deklarasi struct
	system("clear");
	struct mahasiswa
{
char nim[10];
char nama[10];
int nilai;
}mhs[10];
int i=0;
int n=0;

//deskripsi
printf("masukan jumlah data :");
scanf("%d",&n);
for(i=1; i <=n;i++)

{
	printf("\nnim = "); scanf("%s",&mhs[i].nim);
	printf("\nnama = "); scanf("%s",&mhs[i].nama);
	printf("\nnilai = "); scanf("%d",&mhs[i].nilai);
	printf("\n");
}
for(i=1; i <=n; i++)
{
	printf("\nnim = %s",mhs[i].nim);
	printf("\nnama = %s",mhs[i].nama);
	printf("\nnilai = %d",mhs[i].nilai);
	printf("\n");
}
getche();
}

