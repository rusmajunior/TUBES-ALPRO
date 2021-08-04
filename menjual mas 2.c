#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct jumlahbeli{
	float total, n, saldo;	
	char nama[99];
}be;

FILE*emas;
FILE*belimas;
FILE*jual;

struct beli{
	float hargabeli, jumlah;
	char tanggal[99];
}he;

struct jualemas{
	float total, n;
}je;

float saldobeli, saldojual;
main()
{
	emas=fopen("beli emas.dat", "rb");
	printf("==Penjualan emas==\n\n");
	while(fread(&he, sizeof(he), 1, emas)==1){
		printf("Hari/Tanggal : %s", he.tanggal); //menampilkan harga emas terkini
		printf("\nHarga Emas (/gram) : Rp %.0f", he.hargabeli);
	}
	
	belimas=fopen("jumlah beli.dat", "rb");
	while(fread(&be,sizeof(be),1,belimas)==1){
	be.saldo = be.saldo+be.n;
	}
	printf("\n\nTotal kepemilikan emas : %.0f \n", be.saldo);
	
	
	jual=fopen("Jual emas.dat", "ab");
	printf("\nJumlah Penjualan (gram) : ");scanf("%f", &je.n);// input penjualan emas
	be.saldo=be.saldo-je.n;
	je.total=je.n*he.hargabeli;
	printf("Total harga penjualan : Rp %.0f", je.total); //total penjualan
	printf("\n\nSaldo Emas saat ini : %.0f", be.saldo);
	fwrite(&je, sizeof(je), 1, jual);
	
	fclose(belimas);
	fclose(emas);
	fclose(jual);
}
