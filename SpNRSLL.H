/* File        : spNRSLL.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#ifndef spnrsll_H
#define spnrsll_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First


typedef char *infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype info;
	 address next = Nil;
	 } ElmtList;


typedef struct NodeK *addressK;
typedef struct NodeK {
	infotype namaKota;
	addressK nextKota;
	address nextList; //kota agar nunjuk ke nama
	infotype info; // tambahkan member info di sini
} kota;

//NodeKota ListKota;
typedef struct{
	addressK First;
}NodeKota;
/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct {
	  address First;
} List; //kota

void CreateList (NodeKota * L);
address Alokasi (infotype X);
void DeAlokasi (address P);
void InsVFirst (addressK L, infotype X);
void InsVLast (NodeKota * L, infotype X);
void DelVFirst (List * L, infotype * X);
void DelVLast (List * L, infotype * X);
void InsertFirst (addressK L, address P);
addressK alokasiKota(infotype X);
void InsertLast (NodeKota * L, addressK P);
void DelFirst (kota * L, address * P);
void DelP (addressK L, infotype X);
void DelLast (List * L, address * P);
void PrintInfo (kota L);
void PrintKota (NodeKota L); 
void DelAll (addressK L);
addressK Searchkota (NodeKota first, infotype X);
void DelKota(NodeKota *L, infotype X);
boolean FSearch (List L, infotype X);
addressK GetKota(NodeKota L, int urutan);
#endif
