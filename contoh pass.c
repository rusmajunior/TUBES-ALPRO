#include <stdio.h>//file header
#include <string.h>//file header
 
int main (void)//untuk mendeklarasikan variabel utama
{//untuk menandakan awal program
 
    char uss[15];//deklarasi variabel
    char pass[15];//deklarasi variabel
    int i = 0;//deklarasi dan inisialisasi variabel
    int result1, result2;//deklarasi variabel
 
    while (i < 3)// semntar jika kondisi i kurang dari 3
    {//awal dari perulangan while
 
        printf("---------- LOGIN ----------\n\n");//menapilkan data ke layar 
        printf("Please Input Username\t: ");//menapilkan data ke layar 
        scanf("%s", uss);//membaca masukan data uss dan menyimpannya
 
        printf("Please Input Password\t: ");//menapilkan data ke layar
        scanf("%s", pass);//membaca masukan data pass dan menyimpannya
            //strcmp = untuk membandingkan dua buah string
        result1 = strcmp (uss, "brainy"); // membandingkan uss dengan 'brainy'
        result2 = strcmp (pass, "123"); // membandingkan pass dengan '123'
 
        if (result1 == 0 && result2 == 0){// && = benar jika keduanya benar
            break;//jika benar maka akan keluar dari perulanagan tanpa mengerjakan perintah di bawahnya
        }else{//jika tidak
                printf("Password Error...\n");//menapilkan data ke layar
                i++;// operasi increment untuk langkah perulangan
        }//akhir dari kondisi
    }//akhir dari perulangan while
 
    if (i < 3){// jika i kurang dari 3 
        printf("Login Succsess\n");//menapilkan data ke layar
    }else{// jika i tidak kurang dari 3
        printf("Sorry, you can't acces this program...\n");//menapilkan data ke layar
    }//akhir dari kondisi
 
    return 0;//untuk mengembalikan nilai 0
}//untuk menandakan akhir program
