#include <stdio.h>
#include<stdlib.h>
#include<string.h>
FILE*emas;


struct beli{
	float hargabeli;
	char tanggal[99];
}he;

struct jumlahbeli{
	float total, n;	
	char nama[99];
}be;


main(){
	emas=fopen("beli emas.dat", "rb");
	printf("==Pembelian emas==\n\n");
	while(fread(&he, sizeof(he), 1, emas)==1){
		printf("Hari/Tanggal : %s", he.tanggal);
		printf("\nHarga Beli Emas (/gram) : Rp %.0f", he.hargabeli);
	}
	
	FILE*belimas;
	belimas=fopen("jumlah beli.dat", "wb");
	printf("\n\nNama Nasabah : ");gets(be.nama);
	printf("Jumlah Pembelian (gram) : ");scanf("%f", &be.n);
	be.total=be.n*he.hargabeli;
	printf("\nTotal harga : Rp %.0f ", be.total);
	fwrite(&be, sizeof(be), 1, belimas);

	fclose(emas);
	fclose(belimas);
}
