#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main ()
{
struct beli{
	float hargabeli;
	char tanggal[99];

}he;

	FILE *emas;
	
	emas=fopen("beli emas.dat", "wb");
	printf ("==Update Harga Emas==\n");
	printf("Hari/Tanggal : ");gets(he.tanggal);
	printf("Harga Emas : Rp  ");scanf("%f", &he.hargabeli);
	fwrite(&he,sizeof(he),1,emas);

	fclose(emas);
	
	return 0;
}
