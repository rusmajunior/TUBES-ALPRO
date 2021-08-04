#include<stdio.h>


int main (){
	int operasi;
	float a, b, hasil;

	printf("KALKULATOR SEDERHANA\n");
	printf("Operasi yang tersedia : \n");
	printf(" '1'Penjumlahan\n '2'Pengurangan\n '3'Perkalian\n '4'Pembagian\n Pilih operasi : ");
	scanf("%d", &operasi);
	
	printf("Masukkan angka pertama : ");scanf("%f", &a);
	printf("Masukkan angka kedua   : ");scanf("%f", &b);
	
	if (operasi==1){
		hasil = a+b;
		printf("%.2f+%.2f=%.2f", a,b,hasil);
	}
	else if (operasi==2){
		hasil = a-b;
		printf("%.2f-%.2f=%.2f", a,b,hasil);
	}
	else if (operasi==3){
		hasil = a*b;
		printf("%.2f+%.2f=%.2f", a,b,hasil);
	}
	
	else if (operasi==4){
		hasil = a/b;
		printf("%.2f : %.2f=%.2f", a,b,hasil);
	}
	else printf("Mohon maaf, operasi tidak ditemukan");
}
