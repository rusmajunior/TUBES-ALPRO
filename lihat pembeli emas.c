#include <stdio.h>
#include<stdlib.h>


FILE*emas;

struct beli{
	float hargabeli;
	char tanggal[99];
}he;

struct jumlahbeli{
	float total, n;	
	char nama[99];
}be;


main()
{
	
	emas=fopen("beli emas.dat", "rb");
	while(fread(&he,sizeof(he),1,emas)==1){
	printf("\n== Riwayat Pembelian emas==\n");
	printf("Hari/Tanggal : %s", he.tanggal);
	printf("\nHarga Beli Emas (/gram) : Rp %.2f", he.hargabeli);
}
	fclose(emas);
	
	FILE*belimas;
	belimas=fopen("jumlah beli.dat", "rb");
	while(fread(&be,sizeof(be),1,belimas)==1){
	printf("\n\nNama Nasabah : %s", be.nama);
	printf("\n\nJumlah gram : %.0f ", be.n);
	printf("\nTotal harga : Rp %.0f ", be.total);
	}

	fclose(belimas);


	return 0;
}
