	/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "spnrsll.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define NAMA 50
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>


void Menu(){
	printf("Pilih Menu Di bawah ini :\n");
	printf("1. Tambah Kota\n");
	printf("2. Tambah Warga Baru\n");
	printf("3. Hapus Kota\n");
	printf("4. Hapus Warga\n");
	printf("5. Tampilkan Seluruh Informasi Kota\n");
	printf("6. Keluar Program");

	printf("\n\nPilihan : ");
}
int main(){
	/* Kamus Lokal */
		NodeKota ListKota;
		int i;
		int pilihMenu;
		int pilihanList;
		infotype X;
		addressK cari;

	/* Program */
	
	
	CreateList (&ListKota);
	do{
		system("cls");
		printf("========================================\n");
		printf("    Program Kota Memakai Linked List\n");
		printf("========================================\n\n");
		PrintKota(ListKota);
		Menu();
		scanf("%d",&pilihMenu);

		switch(pilihMenu){
			case 1 :{ //insert kota
				printf("Pilih Nomor Kota : ");
				scanf("%d",&pilihanList);
				X = (infotype)malloc(sizeof(infotype) * NAMA);
				printf("Masukan Nama Kota : ");
				scanf("%s",X);
				
				if(pilihanList >= 1 && pilihanList <= 5){	
					if(Searchkota(ListKota, X) == Nil){
						InsVLast(&ListKota,X);		
						printf("\nKota %s berhasil dibuat\n", X);
					}
					else{		
						printf("Sudah Terdapat Kota Pada Nomor Tersebut !");		
					}
				}
				else{
					printf("Masukan Nama Kota Yang Valid !");
				}
				break;
				InsVLast(&ListKota, X);
        		printf("\nKota %s berhasil dibuat\n", X);
        		
				getch();
				system("cls");			
				break;
		}
			case 2 : {//insert warga
				
				printf("Pilih Nama Kota yang akan ditambah warga : ");
				infotype namaKota = (infotype)malloc(sizeof(infotype) * NAMA);
				scanf("%s", namaKota);
				
				cari = Searchkota(ListKota,namaKota);
				if (cari == Nil) {
        			printf("Kota Tidak Ada !");            
    			}
    			else{
    				printf("Masukan Nama Warga : ");
					X = (infotype)malloc(sizeof(infotype) * NAMA);
					scanf("%s",X);
					InsVFirst(cari,X);
					printf("Warga berhasil ditambahkan ke %s.\n", namaKota);
				}
				getch();	
				system("cls");	
				break;
		}
			case 3 :{ //hapus kota
				printf("Masukkan Nama Kota Yang Akan Di Hapus : "); //asalnya pake nomor tp bingung malah ga kehapus jdinya pake nama aja
				X = (infotype)malloc(sizeof(infotype) * NAMA);
				scanf("%s",X);
				
					if(ListKota.First != Nil){
						printf("Kota %s Berhasil Dihapus !",X);
						DelKota(&ListKota, X);
					}
					else{
						printf("Kota Tidak Ada, Tidak Perlu Dihapus !");
					}
				
				
				getch();		
				break;
		}
			case 4 : {//hapus warga
				printf("Masukkan Nama Kota Dari Warga Yang Akan Di Hapus : ");
				X = (infotype)malloc(sizeof(infotype) * NAMA);
				scanf("%s",X);
				
				
					cari = Searchkota(ListKota, X);
					if(cari == Nil){
						printf("Kota Tidak Ada, Tidak Perlu Dihapus !");
					}
					else{
						X = (infotype)malloc(sizeof(infotype) * NAMA);
						printf("Masukan Nama Warga Yang Akan Dihapus : ");
						scanf("%s",X);
                			DelP(cari, X);
                			printf("Warga dengan nama %s berhasil dihapus dari kota %s\n", X, cari->namaKota);
					}
				getch();		
				break;
			}
			case 5 : {
					PrintKota(ListKota);
				getch();
				break;
			}
				
				
			case 6 :{
				printf("Program dihentikan!");
				break;
			}
				
			default : printf("Masukan insert yang valid!");break;
		}

		}while(pilihMenu != 6);
}




