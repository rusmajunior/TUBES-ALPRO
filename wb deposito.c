#include<stdio.h>
#include<string.h>
#include<stdlib.h>


main()
{
	
struct deposit {
	float pokok, bunga;
	int bulan;
	char nama[99];
}dp;
	int i;
	float bunga=0.07/12;
	FILE*depo;
	
	depo=fopen("Data deposito.dat", "ab");
	printf("Nama nasabah : ");gets(dp.nama);
	printf("Bunga 			 : 7 persen (pertahun)\n");
	printf("Jangka waktu (bulan) 	 : ");scanf("%d", &dp.bulan);
	printf("Masukkan jumlah deposito : Rp ");scanf("%f", &dp.pokok);
	
	printf("\n\n==Sertifikat Deposito==\n\n");
	printf("Nama nasabah : %s", dp.nama);
	printf("\nJumlah Deposito : Rp %.2f", dp.pokok);
	
	for(i=1; i<=dp.bulan; i++)
	{
		dp.pokok = dp.pokok + (dp.pokok*bunga);
	}
	printf("\nSaldo akhir deposito setelah %d bulan : Rp %.2f\n\n", i-1,dp.pokok);
	fwrite(&dp, sizeof(dp), 1, depo);
	
	fclose(depo);
	
}
