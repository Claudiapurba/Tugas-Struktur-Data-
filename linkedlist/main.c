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
void tranverse(node *head);
void tambahAkhir(node **head);   // Tambah data di akhir
void hapusAwal(node **head);     // Hapus data di awal
void hapusTengah(node **head);   // Hapus data di tengah
void hapusAkhir(node **head);    // Hapus data di akhir
void cariData(node *head);       // Pencarian data
void jumlahData(node *head);     // Informasi jumlah data
void sumData(node *head);        // Hasil penjumlahan semua data

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
     printf("3. tambah data di akhir list\n");
     printf("4. cetak isi list\n");
     printf("5. hapus data di awal list\n");
     printf("6. hapus data di tengah list\n");
     printf("7. hapus data di akhir list\n");
     printf("8. cari data\n");
     printf("9. jumlah data di list\n");
     printf("10. jumlah total data di list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
     else if (pilih == '3')
			tambahAkhir(&head);
     else if (pilih == '4'){
     		tranverse(head);
         getch();
     }
     else if (pilih == '5'){
         hapusAwal(&head);
         getch();
     }
     else if (pilih == '6'){
         hapusTengah(&head);
         getch();
     }
     else if (pilih == '7'){
         hapusAkhir(&head);
         getch();
     }
     else if (pilih == '8'){
         cariData(head);
         getch();
     }
     else if (pilih == '9'){
         jumlahData(head);
         getch();
     }
     else if (pilih == '10'){
         sumData(head);
         getch();
     }
  } while (pilih != 'q');

  return 0;
}

//========================================================

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
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

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
     printf("\nnod0e tidak ditemukan");
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

//========================================================

void tambahAkhir(node **head){
  int bil;
  node *pNew, *pCur;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
      pNew->data = bil;
      pNew->next = NULL;

      if (*head == NULL) {
          *head = pNew;
      } else {
          pCur = *head;
          while (pCur->next != NULL) {
              pCur = pCur->next;
          }
          pCur->next = pNew;
      }
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void hapusAwal(node **head){
    node *pTemp;

    if (*head == NULL) {
        printf("List kosong\n");
    } else {
        pTemp = *head;
        *head = (*head)->next;
        free(pTemp);
        printf("Node awal dihapus\n");
    }
}

//========================================================

void hapusTengah(node **head){
    int pos;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*head);
    printf("\nmasukkan nilai data yang akan dihapus: ");
    fflush(stdin);
    scanf("%d", &pos);

    pCur = *head;
    pPrev = NULL;

    while (pCur != NULL && pCur->data != pos) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Node tidak ditemukan\n");
    } else {
        if (pPrev == NULL) {
            *head = pCur->next;
        } else {
            pPrev->next = pCur->next;
        }
        free(pCur);
        printf("Node dengan nilai %d dihapus\n", pos);
    }
}

//========================================================

void hapusAkhir(node **head){
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node terakhir dihapus\n");
    } else {
        pCur = *head;
        pPrev = NULL;
        while (pCur->next != NULL) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        pPrev->next = NULL;
        free(pCur);
        printf("Node terakhir dihapus\n");
    }
}

//========================================================

void cariData(node *head){
    int bil;
    node *pCur;

    system("cls");
    printf("masukkan nilai yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = head;
    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan\n", bil);
            return;
        }
        pCur = pCur->next;
    }
    printf("Data %d tidak ditemukan\n", bil);
}

//========================================================

void jumlahData(node *head){
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah node dalam list: %d\n", count);
}

//========================================================

void sumData(node *head){
    int sum = 0;
    node *pCur = head;

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Jumlah total data dalam list: %d\n", sum);
}
