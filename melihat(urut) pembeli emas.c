#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE*belimas;

struct jumlahbeli{
	float total, n;	
	char nama[99];
}be, temp[99],temp2;


void sorting_FS();

main(){
	printf("Sorting file sekuensial !\n");
	system("pause");
	sorting_FS();
	return 0;
}

void sorting_FS(){
	int i=0, j=0, n;
	belimas=fopen("jumlah beli.dat", "rb");
	while(fread(&be,sizeof(be),1,belimas)==1){
		strcpy(temp[i].nama, be.nama);
		temp[i].n = be.n;
		temp[i].total = be.total;
		i++;
		n=i;
	}
	
	fclose(belimas);
	i=0,j=0;
	for (i=n-1;i>=1;i--){
		for(j=1;j<=i;j++){
			if(temp[j-1].nama<temp[j].nama){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("\n\n%d. Nama Nasabah : %s", i+1,temp[i].nama);
		printf("\nJumlah gram : %.0f", temp[i].n);
		printf("\nTotal Harga :%.0f\n", temp[i].total);
	}
	system("pause");
}
