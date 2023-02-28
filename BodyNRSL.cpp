/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define NAMA 50


/**** Konstruktor/Kreator List Kosong ****/
void CreateList (NodeKota * L) //list kota
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 (*L).First = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}


/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (addressK L, infotype X) // warga
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	address P;
	 /* Aloritma */
	P = Alokasi (X);
	if (P != Nil)
	{	InsertFirst (L, P);		}
	P->next = Nil;
}

void InsVLast (NodeKota * L, infotype X) //createkota
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	addressK P;
	 /* Algoritma */
	P = alokasiKota(X);
	if (P != Nil)
	{	InsertLast (&(*L), P);		}
}
/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = First(*L);
		  *X = Info(P);
	First(*L) = Next(First(*L));
	DeAlokasi (P);
}

void DelVLast (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	PDel = First(*L);
	DelLast (&(*L), &PDel);
	(*X) = Info(PDel);
	DeAlokasi (PDel);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (addressK L, address P) //warga
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	if ((*L).nextList != Nil)
	{
		 Last = (*L).nextList;
		while (Next(Last) != Nil){	
		 	Last = Next(Last); 	
		}
		 Next(Last) = P;
	}
		else
	{	(*L).nextList = P;		}
}

addressK alokasiKota(infotype X){	//baru
	addressK P;
	P = (addressK) malloc (sizeof(kota));
	if(P != Nil){
		P->namaKota = X;
		P->nextKota = Nil;
		P->nextList = Nil;
	}
	return (P);
}

void InsertLast (NodeKota * L, addressK P) // insertkota
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	addressK Last;
	 /* Algoritma */
	if (First(*L) != Nil)
	{
		 Last = First(*L);
		while (Last->nextKota != Nil){	
		 	Last = Last->nextKota; 	
		}
		 Last->nextKota = P;
	}
		else
	{	First(*L) = P;		}
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (kota * L, address * P) //warga
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	 *P = (*L).nextList;
	 (*L).nextList = (*L).nextList->next;
}


void DelP (addressK L, infotype X) //warga
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, Prec;
	boolean found=false;
	 /* Algoritma */
		Prec = Nil;
	P = (L)->nextList;
	while ((P != Nil) && (!found))
	{
		 if (strcasecmp(Info(P),X) == 0)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = P->next;
		 }
	} /* P = Nil Atau Ketemu */

	if (found)
	{
//		printf("Warga %s Berhasil Dihapus !",X);
		 if (Prec == Nil && Next(P) == Nil)		/* Hanya 1 elemen */
		 {	L->nextList = Nil;	}
		 else if (Prec == Nil)			/* Ketemu di elemen 1*/
		 {	L->nextList = P->next;	}
		 else		/* Ketemu di elemen list yang ditengah/akhir */
		 {	Next(Prec) = Next(P);	}
		 Next(P) = Nil;
		 DeAlokasi (P);
	}
}

void DelLast (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Kamus Lokal */
	address Prec;
	 /* Algoritma */
	*P = First(*L);
	Prec = Nil;
	while (Next(*P) != Nil)
	{
		 Prec = *P;
		 *P = Next (*P);
	}

	if (Prec == Nil)	/* Hanya 1 elemen */
	{	First(*L) = Nil;	}
	else	/* List Lebih dari 1 elemen */
	{	Next(Prec) = Nil;	}
}


/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (kota L) //warga
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	if (L.nextList == Nil)
	{
		 printf ("Warga Tidak Ada\a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = L.nextList;
		 for (;;)
		 {
		if (P == Nil)
		{
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir List */
		{
			 printf ("- %s \n",Info(P));
			 
			
		}P = Next(P);
		 }
	}
}

void PrintKota (NodeKota L) 
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	addressK P;
	int i = 1;
	 /* Algoritma */
	 printf(" List Kota\n");
	 printf("===========\n");
	if (First(L) == Nil)
	{
		 printf ("Kota Tidak Ada\a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = First(L);
		 for (;;)
		 {
		if (P == Nil)
		{
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir List */
		{
			 printf ("%d. %s : \n", i,P->namaKota);
			 PrintInfo(*P);
			 P = P->nextKota;
			 
		}
		i++;
		 }
	}
}

void DelAll (addressK L) //warga
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	PDel = L->nextList;
	while (PDel != Nil)
	{
		 DelFirst (&(*L), &PDel);
		 DeAlokasi (PDel);
		 PDel = L->nextList;
	}
	(*L).nextList = Nil;
}

addressK Searchkota (NodeKota first, infotype X) //msh kurang
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 addressK P;
	 boolean found =  false;
	 /* algoritma */
	 P = first.First;
	 while ((P != Nil) && (!found))
	 {
	if (strcasecmp(P->namaKota, X) == 0)
	{	found = true; 	}
	else
	{	P = P->nextKota;	}
	 }	/* P = Nil atau Ketemu */
	 return (P);
}



void DelKota(NodeKota *L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    /* Kamus Lokal */
    addressK P, Prec;
    boolean found = false;
    /* Algoritma */
    Prec = Nil;
    P = (L)->First;
    while ((P != Nil) && (!found))
    {
        if (strcasecmp(P->namaKota, X) == 0) //! Mengubah menjadi string compare
        {
            found = true;
        }
        else
        {
            Prec = P;
            P = P->nextKota;
        }
    } /* P = Nil Atau Ketemu */

    if (found)
    {
        DelAll(P);
        if (Prec == Nil && P->nextKota == Nil) /* Hanya 1 elemen */
        {
            First(*L) = Nil;
        }
        else if (Prec == Nil) /* Ketemu di elemen 1*/
        {
            First(*L) = P->nextKota;
        }
        else /* Ketemu di elemen list yang ditengah/akhir */
        {
            Prec->nextKota = P->nextKota;
        }
        P->nextKota = Nil;
        free(P);
    }
}

boolean FSearch (List L, infotype X)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (strcmp(Info(PSearch), X) == 0)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 return (found);
}





