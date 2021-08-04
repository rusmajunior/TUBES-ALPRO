#include<stdio.h>
#include<string.h>

char username[99], pass[99];
int i;

main ()
{
	printf("Username : ");gets(username);
	printf("\nPassword : ");gets(pass);
	

	if ((strcmp(username, "Daskom")==0 && strcmp(pass, "dskm20")==0))
	{
		printf("Login berhasil\n");
	}
	else printf("\nLogin gagal, silakan coba lagi!\n\n");
	system("pause");
	system("cls");
	main();
}

