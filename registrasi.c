#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *log;

void depositoadmin();
void lihatpembeli();

struct login {
	char namadepan[100], namabelakang[20], username[20], password[20], ttl[99], kelamin[99], alamat[99], umur[99];
}tab;

//menu utama//
main()
{	
	system("cls");
	int masuk;
	printf("==========SELAMAT DATANG DI DASKOM SAVE==========\n\n\n");
	printf("Masuk sebagai : \n1. User \n2. Admin \n3. Keluar\n");
	printf("Pilih : ");scanf("%d", &masuk);
	if(masuk==1)
	{
		system("CLS");
		user();
	}
	else if(masuk==2)
	{
		system("CLS");
		pilihanadmin();
	}
	else if(masuk==3)
	{
		system("CLS");
		printf("$$$ Terima kasih telah melakukan transaksi $$$");
	}
}

//menu user//
void user ()
{
	int regis;
	
	printf("Pilih 1 jika belum memiliki akun!\nPilih 2 jika sudah memiliki akun!");
	printf("\n\n1. Registrasi \n2. login\n");
	printf("Pilih : ");scanf("%d", &regis);
	if(regis==1)
	{
		system("CLS");
		registrasi();
	}
	else if(regis==2)
	{
		system("CLS");
		login();
	}
}

//menu registrasi//
void registrasi()
{
	log=fopen("login.dat", "ab");
	printf("=====MENU REGISTRASI=====\n\n");
	printf("Masukan Nama Depan 	: ");fflush(stdin);gets(tab.namadepan);
	printf("Masukan Nama Belakang 	: ");gets(tab.namabelakang);
	printf("TTL 			: ");gets(tab.ttl);
	printf("Alamat 			: ");gets(tab.alamat);
	printf("Jenis Kelamin (P/L) 	: ");gets(tab.kelamin);
	printf("Umur 			: ");gets(tab.umur);
	printf("Masukan Username 	: ");gets(tab.username);
	printf("Masukan Password 	: ");gets(tab.password);
	fwrite(&tab,sizeof(tab),1,log);
	
	fclose(log);
	system("pause");
	system("CLS");
	
	log=fopen("login.dat", "rb");
	printf("\nRegistrasi berhasil! \nData Anda telah disimpan!\n");
	printf("\nNama Depan 	: %s\n", tab.namadepan);
	printf("Nama Belakang 	: %s\n", tab.namabelakang);
	printf("TTL 		: %s\n", tab.ttl);
	printf("Alamat 		: %s\n", tab.alamat);
	printf("Jenis Kelamin 	: %s\n", tab.kelamin);
	printf("Umur 		: %s\n", tab.umur);
	printf("Username	: %s\n", tab.username);
	printf("Password 	: %s\n", tab.password);

	fclose(log);
	
	system("pause");
	system("CLS");
	main();
}

//menu login//
void login()
{
	struct{		
		char username[20],password[20];
	}temp;
	
	int x = 0;
	
	printf("===Silahkan login===\n\n");
	printf("Username : ");scanf("%s", &temp.username);
	printf("Password : ");scanf("%s", &temp.password);
	
	log=fopen("login.dat","rb");
	
	while(fread(&tab,sizeof(tab),1,log)==1)
	{
		if(strcmp(temp.username, tab.username)==0 && strcmp(temp.password, tab.password)==0)
		 {
		 	printf ("\nLOGIN BERHASIL!\n");
		 	system("pause");
		 	system("CLS");
		 	x=1;
			fclose(log);
		 	tabungan();
		 }
	}
	if(x==0){
		printf("\n\nLOGIN GAGAL!\n\nPeriksa kembali username dan password anda!\nAtau silakan registrasi terlebih dahulu!\n\nSilahkan coba lagi!\n");
		system("pause");
		system("cls");
		user();
	}
}

//menu pilih tabungan//
void tabungan ()
{
	int menutab;
	
	printf("==Menu Tabungan==\n");
	printf("1. Deposito \n2.Tabungan Emas\n3. Keluar\n");
	printf("Silahkan pilih tabungan yang ingin diajukan!\n");
	printf("Pilih : ");scanf("%d", &menutab);
	if(menutab==1) //menu deposito//
	{
		system("CLS");
		deposito();
}
	else if(menutab==2) // menu tabungan emas //
	{
		system("CLS");
		menuemas();
	}
	else if(menutab==3) //menu keluar //
	{ 
		main();
	}
}

//menu deposito
void deposito()
{
struct deposit {
	float pokok, bunga;
	int bulan;
	char nama[99], tanggal[99];
}dp;
	int i;
	float bunga=0.07/12;
	FILE*depo;
	
	depo=fopen("Data deposito.dat", "ab");
	printf("Bunga Deposito	 : 7 persen (pertahun)\n");
	printf("Tanggal (hh/bb/tttt) : ");fflush(stdin);gets(dp.tanggal);
	printf("Nama nasabah : ");fflush(stdin);gets(dp.nama);
	printf("Jangka waktu (bulan) 	 : ");scanf("%d", &dp.bulan);
	printf("Masukkan jumlah deposito : Rp ");scanf("%f", &dp.pokok);
	
	printf("\n\n==Sertifikat Deposito==\n\n");
	printf("Tanggal : %s", dp.tanggal);
	printf("\nNama nasabah : %s", dp.nama);
	printf("\nJumlah Deposito : Rp %.2f", dp.pokok);
	
	for(i=1; i<=dp.bulan; i++)
	{
		dp.pokok = dp.pokok + (dp.pokok*bunga);
	}
	printf("\nSaldo akhir deposito setelah %d bulan : Rp %.2f\n\n", i-1,dp.pokok);
	fwrite(&dp, sizeof(dp), 1, depo);
	
	fclose(depo);
	system("pause");
	system("CLS");
	tabungan();
}

//menu tabungan emas//
void menuemas ()
{
	int emas;
	
	printf("==Menu Tabungan Emas==\n");
	printf("1. Beli\n2. Jual \n3.Riwayat Pembelian \n4.keluar\n");
	printf("Pilih : ");scanf("%d", &emas); //pilih tabungan emas//
	if(emas==1)
	{
		system("CLS"); //beli emas
		beliemas(); 
	}
	else if (emas==2) //jual emas
	{
		system("CLS");
		jualemas();	
	}
	else if(emas==3) // riwayat beli emas
	{
		system("CLS");
		riwayatbeliemas();
	}
	else if(emas==4) //keluar
	{
		system("CLS");
		tabungan();
	}
}

//proses pembelian emas
void beliemas()
{
FILE*emas;


struct beli{
	float hargabeli, jumlah;
	char tanggal[99];
}he;

struct jumlahbeli{
	float total, n, saldo;	
	char nama[99];
}be;

	emas=fopen("beli emas.dat", "rb");
	printf("==Pembelian emas==\n\n");
	while(fread(&he, sizeof(he), 1, emas)==1){
		printf("Hari/Tanggal : %s", he.tanggal); //memperlihatkan tangga dan harga
		printf("\nHarga Beli Emas (/gram) : Rp %.0f", he.hargabeli);
	}
	
	FILE*belimas;
	belimas=fopen("jumlah beli.dat", "ab");// input jumlah pembelian
	printf("\n\nNama Nasabah : ");fflush(stdin);gets(be.nama);
	printf("Jumlah Pembelian (gram) : ");scanf("%f", &be.n);
	be.total=be.n*he.hargabeli;
	printf("\nTotal harga : Rp %.0f\n", be.total);//total pembelian

	fwrite(&be, sizeof(be), 1, belimas);

	fclose(emas);
	fclose(belimas);

	system("pause");
	system("CLS");
	riwayatbeliemas();//riwayat pembelian
}


//jual emas
void jualemas()
{
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

struct jualmas{
	float total, n;
}je;

float saldobeli, saldojual;


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
	printf("\n\nSaldo Emas saat ini : %.0f\n", be.saldo);
	fwrite(&je, sizeof(je), 1, jual);
	
	fclose(belimas);
	fclose(emas);
	fclose(jual);

	system("pause");
	system("CLS");
	
	riwayatjualemas();//riwayat penjualan
}

// riwayat pembelian emas
void riwayatbeliemas ()
{
FILE*belimas;
FILE*jual;

struct jumlahbeli{
	float total, n, saldo;	
	char nama[99];
}be;

struct jualemas{
	float total, n;
}je;


	belimas=fopen("jumlah beli.dat", "rb");// input jumlah pembelian
	while(fread(&be,sizeof(be),1,belimas)==1){
		printf("\nJumlah Pembelian (gram) : %.0f", be.n);
	}
	
	jual=fopen("Jual emas.dat", "rb");
	while(fread(&je,sizeof(je),1,jual)==1){
	je.n=(-1*je.n);
	printf("\nJumlah Penjualan (gram) : %.0f", je.n);
	}
	
	
	belimas=fopen("jumlah beli.dat", "rb");
	while(fread(&be,sizeof(be),1,belimas)==1){
	be.saldo = be.saldo+be.n;
	}
	printf("\n\nTotal kepemilikan emas : %.0f \n", be.saldo);
	
	fclose(belimas);
	fclose(jual);

	system("pause");
	system("CLS");
	menuemas();
}

//riwayat penjualan emas
void riwayatjualemas()
{
FILE*emas;

struct beli{
	float hargabeli, jumlah;
	char tanggal[99];
}he;

struct jualemas{
	float total, n;
}je;

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
	
	system("pause");
	system("CLS");
	
	menuemas();

}




// menu admin
void pilihanadmin()
{
	char user[50], pass[50];
	printf("\t===LOGIN ADMIN===");
	printf("\nMasukkan Username \t: ");fflush(stdin);gets(user);
	printf("\nMasukkan Password \t: "); gets(pass);
	
	if (strcmp(user, "admin")==0 && strcmp(pass, "123")==0) //Lengkapi sintaksnya
	{
		printf("\nLogin Berhasil");
		printf("\nSilahkan Lanjutkan...\n");
		system("pause");
		system("CLS");
		admin();
	}
	else
	{
	printf("\nUsername atau password salah!\n");
	printf("Silahkan Ulang");
	system("pause");
	system("CLS");
	main();
	}	
}
void admin()
{
	int x;
	
	printf("==Menu Admin==\n");
	printf("1.Input harga emas \n2.User deposito \n3.User tabungan emas \n4.Keluar\n");
	printf("Pilih : ");scanf("%d", &x);
	if(x==1)
	{
		system("CLS");
		emasadmin();
	}
	else if (x==2)
	{
		system("CLS");
		depositadmin();
	}
	else if(x==3)
	{
		system("CLS");
		lihatpembeli();
	}
	else if(x==4)
	{
		system("CLS");
		main();
	}
}

// menu input harga emas dan tanggal
void emasadmin()
{
struct beli{
	float hargabeli, jumlah;
	char tanggal[99];
}he;

	FILE *emas;
	
	emas=fopen("beli emas.dat", "wb");
	printf ("==Update Harga Emas==\n");
	printf("Hari/Tanggal : ");fflush(stdin);gets(he.tanggal);
	printf("Harga Emas : Rp  ");scanf("%f", &he.hargabeli);
	fwrite(&he,sizeof(he),1,emas);

	fclose(emas);
	
	system("pause");
	system("CLS");
	admin();

}

//melihat penabung deposito
void depositadmin()
{
FILE*depo;

struct deposit {
	float pokok, bunga;
	int bulan; 
	char nama[99], tanggal[99];
}dp, temp[99], temp2;

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
		printf("\n\nTanggal : %s", temp[i].tanggal);
		printf("\n%d. Nama Nasabah : %s", i+1,temp[i].nama);
		printf("\nJangka waktu : %d bulan", temp[i].bulan);
		printf("\nJumlah :Rp %.2f\n", temp[i].pokok);
	}
	system("pause");
	fclose(depo);
	system("CLS");
	admin();
}

//meihat penabung emas (belum mencari)
void lihatpembeli()
{
	FILE*belimas;

struct jumlahbeli{
	float total, n, saldo;	
	char nama[99];
}be, temp[99],temp2;


	
	int i=0, n=0, j;
	belimas=fopen("jumlah beli.dat", "rb");
	while(fread(&be,sizeof(be),1,belimas)==1){
		temp[i]=be;
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
		printf("\nJumlah gram : %.0f", temp[i].n);
		printf("\nTotal Harga :%.0f\n", temp[i].total);
	}
	system("pause");
	fclose(belimas);
	system("CLS");
	admin();
}
