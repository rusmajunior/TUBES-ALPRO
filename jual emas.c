#include<stdio.h>
#include<stdlib.h>
#include<string.h>


FILE*emas;

struct beli{
	float hargabeli;
	char tanggal[99];
}he;

struct jualemas{
	float total, n;
}je;

main()
{
	emas=fopen("beli emas.dat", "rb");
	printf("==Penjualan emas==\n\n");
	while(fread(&he, sizeof(he), 1, emas)==1){
		printf("Hari/Tanggal : %s", he.tanggal);
		printf("\nHarga Emas (/gram) : Rp %.0f", he.hargabeli);
	}
	
	FILE*jual;
	jual=fopen("Jual emas.dat", "ab");
	printf("\n\nJumlah Penjualan (gram) : ");scanf("%f", &je.n);
	je.total=je.n*he.hargabeli;
	printf("\nTotal harga penjualan : Rp %.0f\n", je.total);
	fwrite(&je, sizeof(je), 1, jual);
	
	fclose(emas);
	fclose(jual);
	
}
