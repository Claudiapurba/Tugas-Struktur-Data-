
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct node {
	char nama[100];
    char jenis_kelamin;
    struct node *next;
};
typedef struct node node;

void tambahMahasiswa(node **pList);
void tranverse(node *pList);
void keluarLingkaran(node **pList);
void pisahLingkaran(node **pList);


//========================================================

int main()
{
  node *pList;
  int pilih;

  pList = NULL;
  do{
     system("cls");
     printf("Masukkan pilihan\n");
     printf("1. Keluar dari lingkaran\n");
     printf("2. Mahasiswa keluar lingkaran\n");
     printf("3. Tampilkan urutan Menyanyi\n");
     printf("4. Pisahkan menjadi 2 lingkaran\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);


     scanf("%d", &pilih);
     if (pilih == 1)
     	tambahMahasiswa(&pList);
      else if (pilih == 2)
         keluarMahasiswa(&pList);
      else if (pilih == 3){
      tranverse(pList);
      getch();
      }
      else if (pilih == 4)
         pisahLingkaran(&pList);
      }

   while (pilih != 'q');

  return 0;
}
//===========================================================================

void tambahMahasiswa(node **pList){
  char nama[100];
  char jenis_kelamin;
  node *pNew, *pcur;

  system("cls");
  fflush(stdin);
  printf("Masukkan nama Mahasiswa (huruf awal huruf kapital) : ");
  fflush(stdin);
  scanf("%s", &nama);

  printf("masukkan jenis kelamin P(perempuan)/L(laki-laki): ");
  fflush(stdin);
  scanf(" %c", &jenis_kelamin);

  pNew = (node *)malloc(sizeof(node));

   if (strcmp(nama, "Cindy") == 0) {
    pcur = *pList;
    int wanita_count = 0; // Menghitung jumlah mahasiswi
    if (*pList != NULL) {
        do {
            if (pcur->jenis_kelamin == 'P') {
                wanita_count++; // Menambah jumlah mahasiswi
            }
            pcur = pcur->next;
        } while (pcur != *pList);
    }

    // Memeriksa apakah ada setidaknya dua mahasiswi
    if (wanita_count < 2) {
        printf("Cindy tidak dapat bergabung karena harus ada minimal 2 mahasiswi lain.\n");
        getch();
        return; // Cindy tidak ikut lingkaran
    }
}

  if (pNew != NULL){
  	  strcpy(pNew->nama, nama);
      pNew->jenis_kelamin = jenis_kelamin;

      if (*pList == NULL)
      {
        pNew->next = pNew;
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
      printf("data berhasil ditambahkan\n");
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void keluarMahasiswa(node **pList) {
   char nama[100];
   node *pcur, *ppre;

   system("cls");

   if (*pList == NULL) {
      printf("\nTidak ada mahasiswa dalam lingkaran.");
      getch();
      return;
   }

   tranverse(*pList);
   printf("\nNama mahasiswa yang akan keluar lingkaran: ");
   fflush(stdin);
   scanf("%s", nama);

   // Menghitung jumlah mahasiswi dalam lingkaran saat ini
   pcur = *pList;
   int wanita_count = 0;
   int cindy_present = 0; // memeriksa keberadaan Cindy
   do {
      if (pcur->jenis_kelamin == 'P') {
         wanita_count++;
      }
      if (strcmp(pcur->nama, "Cindy") == 0) {
         cindy_present = 1; // Menandai Cindy ada dalam lingkaran
      }
      pcur = pcur->next;
   } while (pcur != *pList);

   // Memeriksa apakah yang akan keluar adalah salah satu dari 2 wanita terakhir
   if (cindy_present && wanita_count == 3 && strcmp(nama, "Cindy") != 0) {
      printf("\nTidak bisa mengeluarkan %s, karena hanya ada 2 wanita yang tersisa dan Cindy masih dalam lingkaran.\n", nama);
      getch();
      return;
   }

   pcur = *pList;
   ppre = NULL;

   do {
      if (strcmp(pcur->nama, nama) == 0) {
         break;
      }
      ppre = pcur;
      pcur = pcur->next;
   } while (pcur != *pList);

   if (pcur == *pList && strcmp(pcur->nama, nama) != 0) {
      printf("\nMahasiswa tidak ada dalam lingkaran.");
      getch();
      return;
   }

   if (pcur == *pList) {
      if (pcur->next == *pList) {
         free(pcur);
         *pList = NULL;
      } else {
         ppre = *pList;
         while (ppre->next != *pList) {
            ppre = ppre->next;
         }
         ppre->next = pcur->next;
         *pList = pcur->next;
         free(pcur);
      }
   } else {
      ppre->next = pcur->next;
      free(pcur);
   }

   printf("\nMahasiswa %s keluar dari lingkaran.", nama);
   getch();
}

//===============================================================

void tranverse(node *pList){
	node *pWalker, *pLast;


   system("cls");
	pWalker = pList;

   if (pList == NULL)
   {
      printf("\nTidak ada mahasiswa dalam lingkaran");
      getch();
      return;
   }


   printf("\nlist data Mahasiswa dalam lingkaran:\n");
   do
   {
    if (pWalker == pList) {
            printf("- %s, '%c' sedang bernyanyi -> \n", pWalker->nama, pWalker->jenis_kelamin);
        } else {
            printf("- %s, '%c' -> \n", pWalker->nama, pWalker->jenis_kelamin);
        }

        pLast= pWalker;
        pWalker = pWalker->next;
   } while (pWalker !=pList);

    printf("\n %s bergandengan dengan mahasiswa pertama", pLast->nama);
    getch();
}

//========================================================

void pisahLingkaran(node **pList) {
    if (*pList == NULL) {
        printf("List kosong, tidak ada mahasiswa.\n");
        return;
    }

    node *pCur = *pList;
    node *pLastPria = NULL;
    node *pLastWanita = NULL;

    node *headPria = NULL;      // Kepala lingkaran pria
    node *headWanita = NULL;    // Kepala lingkaran wanita

    // Pisahkan lingkaran pria dan wanita
    do {
        node *pNew = (node *)malloc(sizeof(node));
        if (pNew == NULL) {
            printf("Alokasi memori gagal.\n");
            return;
        }

        // Salin data dari node asli
        strcpy(pNew->nama, pCur->nama);
        pNew->jenis_kelamin = pCur->jenis_kelamin;

        if (pCur->jenis_kelamin == 'L') { //Jika mahasiswa pria
            if (headPria == NULL) {
                headPria = pNew;
                pNew->next = headPria;
            } else {
                pLastPria->next = pNew;
                pNew->next = headPria;
            }
            pLastPria = pNew;
        } else if (pCur->jenis_kelamin == 'P') { // Jika mahasiswa wanita
            if (headWanita == NULL) {
                headWanita = pNew;
                pNew->next = headWanita;
            } else {
                pLastWanita->next = pNew;
                pNew->next = headWanita;
            }
            pLastWanita = pNew;
        }

        pCur = pCur->next;
    } while (pCur != *pList);

    printf("\nLingkaran mahasiswa pria dan wanita:\n");

    if (headPria != NULL && headWanita != NULL) {
        printf("\nMahasiswa pria:\n");
        tranverse(headPria);
        printf("\nMahasiswi wanita:\n");
        tranverse(headWanita);
    } else if(headPria == NULL){
        printf("Tidak ada mahasiswa dalam lingkaran.\n");
    }else if(headWanita == NULL){
        printf("Tidak ada mahasiswa dalam lingkaran.\n");

    }


}
