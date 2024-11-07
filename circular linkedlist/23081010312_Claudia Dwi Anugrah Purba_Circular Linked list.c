#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **pList);
void tambahData(node **pList);
void tambahAkhir(node **pList);
void tranverse(node *pList);
void hapusAwal(node **pList);
void hapusData(node **pList);
void hapusAkhir(node **pList);
void cariData(node **pList);
void jumlahData(node **pList);
void totalData(node **pList);



//========================================================

int main()
{
  node *pList;
  int pilih;

  pList = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list \n");
     printf("4. cetak isi list\n");
     printf("5. hapus data di awal\n");
     printf("6. hapus data ditengah list\n");
     printf("7. hapus data di akhir list\n");
     printf("8. cari data didalam list\n");
     printf("9. jumlah data didalam list\n");
     printf("10. hasil penjumlahan semua data dalam list\n");

     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%d", &pilih);
     if (pilih == 1)
     		tambahAwal(&pList);
      else if (pilih == 2)
         tambahData(&pList);
      else if (pilih == 3)
         tambahAkhir(&pList);
      else if (pilih == 4){
      tranverse(pList);
      getch();
      }
      else if (pilih == 5)
         hapusAwal(&pList);
      else if (pilih == 6)
         hapusData(&pList);
      else if (pilih == 7)
         hapusAkhir(&pList);
      else if (pilih == 8)
         cariData(&pList);
      else if (pilih == 9)
         jumlahData(&pList);
      else if (pilih == 10)
         totalData(&pList);

  } while (pilih != 0);

  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================
//menambah data di awal
void tambahAwal(node **pList){
  int bil;
  node *pNew, *pcur;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;

      if (*pList == NULL)
      {
        pNew->next = pNew;
      //add before first logical node or to an empty list
        *pList = pNew;
      }else
      {
         pcur = *pList;
         while (pcur->next != *pList)
         {
            pcur = pcur->next;
         }

         pNew->next = *pList;
         pcur->next = pNew;
         *pList = pNew;
      }
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================
//menambah data di tengah
void tambahData(node **pList){
  int pos, bil;
  node *pnew, *pcur;

  system("cls");
  tranverse(*pList);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

 pcur = *pList;
 if (pcur == NULL){
     printf("\nlist kosong");
     getch();
  }
do
{
   if(pcur->data == pos){
      break;
   }
   pcur = pcur->next;
} while (pcur != *pList);

  pnew = (node *)malloc(sizeof(node));

  if (pcur->data != pos)
  {
   printf("\nnode tidak ditemukan");
   getch();
  }
  else if (pnew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }

     pnew->data = bil;
     pnew -> next = pcur -> next;
     pcur -> next = pnew;
}

//========================================================

void tranverse(node *pList){
   //traverse a circular list
	node *pWalker;

   system("cls");
	pWalker = pList;

   if (pList == NULL)
   {
      printf("\nNULL");
      getch();
      return;
   }

   printf("\nlist data :\n");

   printf("%d ", pWalker->data);
   printf(" -> ");


	while (pWalker->next != pList){
      pWalker = pWalker -> next;
      printf("%d ", pWalker -> data);
      printf(" -> ");
	}
     printf("\nkembali ke awal %d", pList->data);
}

//========================================================
// menambah data diakhir

void tambahAkhir(node **pList){
   int bil;
   node *pnew, *pcur;

   system("cls");
   fflush(stdin);
   printf("masukkan sebuah bilangan : ");
   fflush(stdin);
   scanf("%d", &bil);

   pnew = (node *)malloc(sizeof(node));
   if (pnew != NULL)
   {
      pnew->data = bil;

      if (*pList == NULL)
      {
         pnew->next = pnew;
         *pList= pnew;
      }else{
         pcur = *pList;
         while (pcur->next != *pList)
         {
            pcur= pcur->next;
         }
         pnew->next = *pList;
         pcur->next = pnew;
      }
   } else{
      printf("\nalokasi memori gagal");
      getch();
   }
}

//========================================================
//hapus data awal

void hapusAwal(node **pList){
   node *pcur, *ppre;
   if (*pList == NULL)
   {
      printf("list kosong\n");
      getch();
      return;
   }

   pcur = *pList;
   ppre = *pList;

   if (pcur->next == pcur)
   {
      free(pcur);
      *pList = NULL;
      printf("\ndata berhasil dihapus");
      getch();
      return;
   }


   if (pcur == *pList)
   {
      while (ppre->next != *pList)
      {
         ppre = ppre->next;
      }

      ppre->next = pcur->next;
      *pList = pcur->next;
      free(pcur);
      printf("\ndata berhasil dihapus");
      getch();
   }

}
//========================================================
//hapus data tengah

void hapusData(node **pList){
   int  bil;
   node *pcur, *ppre;

   system("cls");
   tranverse(*pList);
   printf("\nbilangan :  ");
   fflush(stdin);
   scanf("%d", &bil);

   if (*pList == NULL)
   {
      printf("\nlist kosong.");
      getch();
      return;
   }

   pcur = *pList;
   ppre = NULL;

   do
   {
      if (pcur->data == bil)
      {
         break;
      }
      ppre= pcur;
      pcur= pcur->next;
   } while (pcur != *pList);

   if (pcur == *pList && pcur->data != bil)
   {
      printf("\ndata tidak ditemukan");
      getch();
      return;
   }

   if (pcur == *pList )
   {
      if (pcur->next == *pList)
      {
         free(pcur);
         *pList = NULL;
      } else
      {
      ppre= *pList;
      while (ppre->next != *pList)
      {
         ppre = ppre->next;
      }
      ppre->next = pcur->next;
      *pList= pcur->next;
      free(pcur);
      }
   }else
   {
      ppre->next = pcur->next;
      free(pcur);
   }

   printf("\ndata berhasil dihapus");
   getch();
}
//========================================================
//hapus data akhir

void hapusAkhir(node **pList){
   node *pcur, *ppre;

   if (*pList == NULL)
   {
      printf("list kosong\n");
      getch();
      return;
   }

   pcur = *pList;
   ppre = NULL;

   if (pcur->next == pcur)
   {
      free(pcur);
      *pList = NULL;
      printf("\ndata berhasil dihapus");
      getch();
      return;
   }

   ppre = pcur;
   while (pcur->next != *pList)
   {
         ppre= pcur;
         pcur = pcur->next;
   }


   ppre->next = *pList;
   free(pcur);
   printf("\ndata berhasil dihapus");
   getch();

}

//========================================================
//cari data
void cariData(node **pList){
   int target, index = 0;
   node *pcur;

   system("cls");
   fflush(stdin);
   printf("masukkan angka yang dicari: ");
   fflush(stdin);
   scanf("%d", &target);

   if (*pList == NULL){
      printf("\nlist kosong");
      getch();
      return;
   }

   pcur = *pList;

   do
   {
      if (pcur->data == target)
      {
      printf("\ndata %d ditemukan pada index : %d ", target, index);
      getch();
      return;
      }

      pcur= pcur->next;
      index++;
   } while (pcur != *pList);


   printf("\ndata tidak ditemukan");
   getch();

}

//========================================================
//jumlah data
void jumlahData(node **pList){
   int count = 0;
   node *pcur;
   if (*pList == NULL)
   {
     printf("\nlist kosong");
     getch();
     return;
   }

   pcur= *pList;

   do
   {
      count++;
      pcur= pcur->next;
   } while (pcur != *pList);

   printf("jumlah data dalam list adalah %d\n",count);
   getch();
}


//========================================================
//total data
void totalData(node **pList){
   int total = 0;
   node *pcur;
   if (*pList == NULL)
   {
     printf("\nlist kosong");
     getch();
     return;
   }

   pcur= *pList;

   do
   {
      total += pcur->data;
      pcur= pcur->next;
   } while (pcur != *pList);

   printf("total nilai data dalam list adalah %d\n",total );
   getch();
}
