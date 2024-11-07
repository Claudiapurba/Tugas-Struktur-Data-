#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

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
    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list\n");
        printf("4. Cetak isi list\n");
        printf("5. Hapus data di awal\n");
        printf("6. Hapus data di tengah list\n");
        printf("7. Hapus data di akhir list\n");
        printf("8. Cari data di dalam list\n");
        printf("9. Jumlah data di dalam list\n");
        printf("10. Total semua data dalam list\n");

        printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);
        if (pilih == 1)
            tambahAwal(&pList);
        else if (pilih == 2)
            tambahData(&pList);
        else if (pilih == 3)
            tambahAkhir(&pList);
        else if (pilih == 4) {
            tranverse(pList);
            getch();
        } else if (pilih == 5)
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
// Menambah data di awal
void tambahAwal(node **pList)
{
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*pList == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew;
            *pList = pNew;
        } else {
            node *pLast = (*pList)->prev;
            pNew->next = *pList;
            pNew->prev = pLast;
            pLast->next = pNew;
            (*pList)->prev = pNew;
            *pList = pNew;
        }
    } else {
        printf("Alokasi memori gagal\n");
        getch();
    }
}

//========================================================
// Menambah data di tengah
void tambahData(node **pList)
{
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*pList);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *pList;
    if (pCur == NULL) {
        printf("\nList kosong");
        getch();
        return;
    }

    do {
        if (pCur->data == pos) {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *pList);

    if (pCur->data != pos) {
        printf("\nNode tidak ditemukan");
        getch();
        return;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
        return;
    }

    pNew->data = bil;
    pNew->next = pCur->next;
    pNew->prev = pCur;
    pCur->next->prev = pNew;
    pCur->next = pNew;
}

//========================================================
// Traverse list
void tranverse(node *pList)
{
    node *pWalker;

    system("cls");
    if (pList == NULL) {
        printf("\nList kosong");
        getch();
        return;
    }

    pWalker = pList;
    printf("\nList data:\n");

    do {
        printf("%d ", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    } while (pWalker != pList);

    printf("\nKembali ke awal %d", pList->data);
}

//========================================================
// Menambah data di akhir
void tambahAkhir(node **pList)
{
    int bil;
    node *pNew, *pLast;

    system("cls");
    fflush(stdin);
    printf("Masukkan sebuah bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        if (*pList == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew;
            *pList = pNew;
        } else {
            pLast = (*pList)->prev;
            pNew->next = *pList;
            pNew->prev = pLast;
            pLast->next = pNew;
            (*pList)->prev = pNew;
        }
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================
// Menghapus data di awal
void hapusAwal(node **pList)
{
    if (*pList == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    node *pCur = *pList;
    if (pCur->next == pCur) {
        free(pCur);
        *pList = NULL;
        printf("\nData berhasil dihapus");
        getch();
        return;
    }

    node *pLast = pCur->prev;
    pLast->next = pCur->next;
    pCur->next->prev = pLast;
    *pList = pCur->next;
    free(pCur);

    printf("\nData berhasil dihapus");
    getch();
}

//========================================================
// Menghapus data di tengah
void hapusData(node **pList)
{
    int bil;
    node *pCur;

    system("cls");
    tranverse(*pList);
    printf("\nBilangan:  ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*pList == NULL) {
        printf("\nList kosong.");
        getch();
        return;
    }

    pCur = *pList;

    do {
        if (pCur->data == bil) {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *pList);

    if (pCur->data != bil) {
        printf("\nData tidak ditemukan");
        getch();
        return;
    }

    if (pCur->next == pCur) {
        free(pCur);
        *pList = NULL;
    } else {
        pCur->prev->next = pCur->next;
        pCur->next->prev = pCur->prev;
        if (pCur == *pList) {
            *pList = pCur->next;
        }
        free(pCur);
    }

    printf("\nData berhasil dihapus");
    getch();
}

//========================================================
// Menghapus data di akhir
void hapusAkhir(node **pList)
{
    if (*pList == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    node *pCur = *pList;
    if (pCur->next == pCur) {
        free(pCur);
        *pList = NULL;
        printf("\nData berhasil dihapus");
        getch();
        return;
    }

    node *pLast = (*pList)->prev;
    pLast->prev->next = *pList;
    (*pList)->prev = pLast->prev;
    free(pLast);

    printf("\nData berhasil dihapus");
    getch();
}

//========================================================
// Mencari data
void cariData(node **pList)
{
    int target, index = 0;
    node *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan angka yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

    if (*pList == NULL) {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *pList;

    do {
        if (pCur->data == target) {
            printf("\nData %d ditemukan pada index : %d ", target, index);
            getch();
            return;
        }

        pCur = pCur->next;
        index++;
    } while (pCur != *pList);

    printf("\nData tidak ditemukan");
    getch();
}

//========================================================
// Jumlah data
void jumlahData(node **pList)
{
    int count = 0;
    node *pCur;
    if (*pList == NULL) {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *pList;

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != *pList);

    printf("Jumlah data dalam list adalah %d\n", count);
    getch();
}

//========================================================
// Total semua data
void totalData(node **pList)
{
    int total = 0;
    node *pCur;
    if (*pList == NULL) {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *pList;

    do {
        total += pCur->data;
        pCur = pCur->next;
    } while (pCur != *pList);

    printf("Total nilai data dalam list adalah %d\n", total);
    getch();
}

