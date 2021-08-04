#include<stdio.h>
#include<string.h>

struct login {
	char namadepan[100], namabelakang[20], username[20], password[20];
}tab;
FILE *log;

main()
{

log=fopen("login.dat", "rb");
	while(fread(&tab,sizeof(tab),1,log)==1){
	
	printf("\nNama Depan 		: %s\n", tab.namadepan);
	printf("Nama Belakang 		: %s\n", tab.namabelakang);
	printf("Username 		: %s\n", tab.username);
	printf("Password 		: %s\n", tab.password);
}
	fclose(log);
}
