#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir (node **head);
void hapusAwal (node **head);
void hapusData (node **head);
void hapusAkhir (node **head);
void cariData (node **head);
void jumlahData(node **head);
void totalData (node **head);
void tranverse(node *head);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir\n");
     printf("4. hapus data di awal\n");
     printf("5. hapus data di tengah\n");
     printf("6. hapus data di akhir\n");
     printf("7. cari data\n");
     printf("8. tampilkan informasi jumlah data\n");
     printf("9. menampilkan hasil penjumlahan seluruh data\n");
     printf("10. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
     else if (pilih == '3')
            tambahAkhir (&head);
     else if (pilih == '4')
            hapusAwal (&head);
     else if (pilih == '5')
            hapusData (&head);
     else if (pilih == '6')
            hapusAkhir (&head);
     else if (pilih == '7')
            cariData (&head);
     else if (pilih == '8')
            jumlahData (&head);
     else if (pilih == '9')
            totalData (&head);
     else if (pilih == '10'){
     		tranverse(head);
         getch();
     }
  } while (pilih != 'q');

  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================
//tambah data di awal  linked list
void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
      //add before first logical node or to an empty list
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================
//Tambah data di tengah linked list
void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}
//========================================================
//Tambah data di akhir linked list
void tambahAkhir(node **head){
  int bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL) {
        pNew ->data = bil;
    pNew->next = NULL;
    //add before first logical node or to an empty list
        pNew->next = *head;
    *head = pNew;
  } else{
    printf("Alokasi  memori gagal");
    getch();}
  }
//========================================================
//Hapus data di awal linked list
void hapusAwal(node **head){
    node *pCur;
    if (*head == NULL){
        printf("list kosong\n");
        getch();
    }else{
        pCur = *head;
        *head = (*head) ->next;
        free(pCur);
        printf("\ndata berhasil dihapus");
        getch();
    }
}
//========================================================
//Hapus data di tengah linked list
void hapusData(node **head){
    int bil;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    printf("\nmasukkan bilangan yang akan di hapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    pPre = NULL;

    while (pCur != NULL && pCur->data != bil) {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("\ndata tidak ditemukan\n");
    }
        if (pPre == NULL) {
            *head = pCur->next;
        } else {
            pPre->next = pCur->next;
        }
        free(pCur);
        printf("\ndata berhasil dihapus");
        getch();

}
//========================================================
//Hapus data di akhir linked list
void hapusAkhir(node **head){
    node *pCur, *pPre;

    if (*head == NULL){
        printf("list kosong\n");
        getch();
        return;
    }

    pCur = *head;
    pPre = NULL;
    while (pCur->next != NULL){
        pPre = pCur;
        pCur = pCur->next;
        }

    if (pPre == NULL){
        *head = pCur ->next;
    }else{
        pPre->next = NULL;
    }
        free(pCur);
        printf("\ndata beerhasil dihapus");
        getch();
    }

//========================================================
//Pemcarian data dalam linked list
void cariData(node **head){
    int target, index = 0;
    node *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan angka yang dicari: ");
    fflush(stdin);
    scanf ("%d", &target);

    if (*head == NULL){
        printf("\nlist kosong");
        getch();
        return;

   pCur = *head;
   while (pCur != NULL){
      if(pCur->data == target){
         printf("\ndata %d ditemukan pada index : %d ", target, index);
         getch();
         return;
      }

      pCur= pCur->next;
      index++;
    }

    }

}
//========================================================
//Menampilkan informasi jumlah data di linked list
void jumlahData(node **head){
    int count = 0;
    node *pCur;
    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }
    pCur = *head;

    while (pCur != NULL)
    {
        count++;
        pCur=pCur->next;
    }

    printf("jumlah data dalam list adalah %d", count);
    getch();
}

//========================================================
//Menampilkan hasil penjumlahan dari semua data
void totalData(node **head){
    int total;
    node *pCur;

    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    pCur = *head;
    while (pCur != NULL)

    {
        total += pCur->data;
        pCur = pCur -> next;
    }
    printf("total penjumlahan data dalam list adalah %d", total);
    getch();
}

//========================================================

void tranverse(node *head){
    //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
        while (pWalker != NULL){
        printf("%d\t", pWalker -> data);
        pWalker = pWalker -> next;
        printf(" -> ");
	}
   printf("NULL");
   }

