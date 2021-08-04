#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE*depo;

struct deposit {
	float pokok, bunga, total;
	int bulan; char nama[99];
}dp, temp[99], temp2;

void sorting_FS();

main(){
	printf("Sorting file sekuensial !\n");
	system("pause");
	sorting_FS();
	return 0;
}

void sorting_FS(){
	
	int i=0, n=0, j;
	
	depo=fopen("Data deposito.dat", "rb");
	while(fread(&dp,sizeof(dp), 1, depo)==1){
		temp[i] = dp;
		i++;
		n++;

	}
	
	for (i=n-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if(strcmp(temp[j-1].nama,temp[j].nama)>0){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}	
	for(i=0;i<n;i++){
		printf("\n\n%d. Nama Nasabah : %s", i+1,temp[i].nama);
		printf("\nJangka waktu : %d", temp[i].bulan);
		printf("\nJumlah Deposito yang akan diterima :%.2f\n", temp[i].pokok);
	}
	system("pause");
	fclose(depo);
}
