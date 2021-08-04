#include<stdio.h>

FILE *deposit;
main()
{
	float pokok, bunga;
	int bulan, i;
	bunga=0.07/12;
	
	printf("Bunga 			 : 7 persen (pertahun)\n");
	printf("Jangka waktu (bulan) 	 : ");scanf("%d", &bulan);
	printf("Masukkan jumlah deposito : ");scanf("%f", &pokok);
	
	printf("==Sertifikat Deposito==\n\n");
	printf("Jumlah Deposito : %.2f", pokok);
	
	for(i=1; i<=bulan; i++)
	{
		pokok = pokok + (pokok*bunga);
	}
	printf("\nSaldo akhir deposito setelah %i bulan : %.2f", i-1,pokok);
	
	
	return 0;
}
