#include<stdio.h>

struct login {
	char namadepan[100], namabelakang[20], username[20], password[20];
}tab;

char hapus[99];
FILE *log;
FILE *log2;
int main(){

	FILE *log;
	log=fopen("login.dat", "rb");
	log2=fopen("login2.dat", "wb");
	printf("Silahkan masukkan Username yang akan dihapus: ");gets(hapus);
	while(fread(&tab,sizeof(tab),1,log)==1);{
	fwrite(&tab,sizeof(tab),1,log);
	
	if (strcmp(tab.username, hapus)!=0){
	fwrite(&tab, sizeof(tab), 1, log2);
}
}
	fclose(log);
	fclose(log2);
	remove("login.dat");
	rename("login2.dat","login.dat");
	fclose(log);
}
