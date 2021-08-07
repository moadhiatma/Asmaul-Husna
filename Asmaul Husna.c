#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

void menu();
void cari();
void daftar();
int pil,back,i,j,n,id;
FILE *asma;
char kar;
char cnama[max];
char numb[1000];
char asmaulhusna [max][max]={"Ar Rahman","Ar Rohim","Al Malik","Al Quddus",
							"As Salam","Al Mumin","Al Muhaimin","Al Aziz",
							"Al Jabbar","Al Muttakabir","Al Khaliq","Al Baari",
							"Al Mushawir","Al Ghaffar","Al Qahar","Al Wahab",
							"Ar Razaq","Al Fattah","Al Alim","Al Qobidh",
							"Al Basith","Al Khaafith","Ar Rafi","Al Muiz",
							"Al Mundzil","As Samiy","Al Bashir","Al Hakam",
							"Al Adl","Al Latiif","Al Khabir","Al Haliim",
							"Al Adzim","Al Ghafur","As Syakuur","Al Aliy",
							"Al Kabiir","Al Khafiidz","Al Muqiit","Al Hasiib",
							"Al Jaliil","Al Kariim","Ar Raqib","Al Mujiib",
							"Al Waasi","Al Hakiim","Al Waduud","Al Majiid",
							"Al Baaits","As Syahid","Al Haqqu","Al Wakil",
							"Al Qowiiy","Al Matiin","Al Walii","Al Hamiid",
							"Al Muhshi","Al Mubdii","Al Muid","Al Muhyi",
							"Al Mumiit","Al Hayyu","Al Qoyyum","Al Wajid",
							"Al Maajid","Al Wahid","Al Ahad","As Shamad",
							"Al Qaadir","Al Muqtadir","Al Muqoddim",
							"Al Muakhir","Al Awal","Al Aakhir","Ad Dzohir",
							"Al Bathin","Al Waali","Al Mutaali","Al Bar",
							"At Tawwab","Al Muntaqim","Al Afuw","Ar Rauf",
							"Maalikul Mulk","Dzaljalali wal ikhram",
							"Al Muqsith","Al Jaami","Al Ganii","Al Mugni",
							"Al Aani","Ad Dhaar","An Nafi","An Nur","Al Haadi",
							"Al Badii","Al Baaqi","Al Waarist","Ar Rasyiid",
							"As Shabuur"};

int main()
{
	menu();
	return 0;
}

void menu()
{
	printf("==========MENU==========\n\n");
	printf("1. Daftar Asmaul Husna\n");
	printf("2. Cari Asmaul Husna\n");
	printf("3. Exit\n");
	printf("\nPilihan : ");
	scanf("%d", &pil);
	switch(pil)
	{
	case 1 :
		daftar();
		break;
	case 2 :	
		cari();
		break;
	case 3 :
		system("cls");
		exit(1);
	}
}

void daftar(){
	system("cls");
	asma=fopen("Asmaul.txt","r");
	while((kar=fgetc(asma))!=EOF)
	{
		putchar(kar);
	}
	fclose(asma);
	balik1:
	printf("\n\n");
	printf("Ketik 0 untuk kembali ke menu : ");
	scanf("%d",&back);
	if (back==0)
	{
		system("cls");
		menu();
	}
	else
	{
		printf("\nMasukan anda salah, harap masukkan kembali!");
		goto balik1;
	}
}

void cari(){
	system("cls");
	printf("Masukkan Asmaul Husna yang ingin anda cari : ");
	gets(cnama);
	gets(cnama);
	n=0;
	for(i=0;i<100;i++)
	{
		if(strncmp(cnama,asmaulhusna[i], sizeof(asmaulhusna[i]))==0)
		{
			n++;
			break;
		}
	}
	if(n==0)
	{
		printf("\nAsmaul Husna tidak ditemukan!!!\n");
		balik2:
		printf("\nKetik 0 untuk ke menu atau ketik 1 untuk mencari kembali : ");
		scanf("%d",&back);
		if (back==0)
		{
			system("cls");
			menu();
		}
		else if (back==1)
		{
			system("cls");
			cari();
		}
		else
		{
			printf("\nMasukan anda salah, harap masukkan kembali!\n");
			goto balik2;
		}
	}
	else
	{
		system("cls");
		asma=fopen("E:/tugas UMM/Tugas Besar/MaknaAsma.txt","r");
		for (j=0;j!=EOF;j++) 
		{
		   	fscanf(asma,"%s",numb);
		   	id=atoi(numb);
			if (id==i+1) 
			{
				fgets(numb,1000,(FILE*)asma);
			   	printf("%d. %s",id,numb);
			   	break;
	   		}
	    }
	    balik3:
		printf("\n\nKetik 0 untuk ke menu atau 1 untuk mencari kembali : ");
		scanf("%d",&back);
		if (back==0)
		{
			system("cls");
			menu();
		}	
		else if (back==1)
		{
			system("cls");
			cari();
		}
		else
		{
			printf("\nMasukan anda salah, harap masukkan kembali!");
			goto balik3;
		}
	}	
}