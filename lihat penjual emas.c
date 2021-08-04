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
	while(fread(&he,sizeof(he),1,emas)==1){
	printf("\n== Riwayat Penjualan emas==\n");
	printf("Hari/Tanggal : %s", he.tanggal);
	printf("\nHarga Beli Emas (/gram) : Rp %.2f", he.hargabeli);
}
	
	FILE*jual;
	jual=fopen("Jual emas.dat", "rb");
	while(fread(&je,sizeof(je),1,jual)==1){
	printf("\n\nJumlah Penjualan (gram) : %.0f", je.n);
	printf("\nTotal harga penjualan : Rp %.0f\n", je.total);
	}
	fclose(emas);
	fclose(jual);
	

}
