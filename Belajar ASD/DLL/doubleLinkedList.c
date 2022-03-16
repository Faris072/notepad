#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int itemtype;
typedef struct simpul node;
struct simpul{
    itemtype data;
    node *next;
    node *prev;
};

node *head = NULL; 
node *tail = NULL;
node *baru;

void alokasi(itemtype x){
    baru = (node *)malloc(sizeof(node));
    if(!baru){
        printf("Alokasi Gagal!");
    }
    else{
        baru->data = x;
        baru->next = NULL;
        baru->prev = NULL;
    }
}

void sisipAwal(){
    baru->next = head;
    head->prev = baru;
    baru->prev = NULL;
    head = baru;
}

void sisipAkhir(){
    baru->prev = tail;
    tail->next = baru;
    baru->next = NULL;
    tail = baru;
}

void sisipSebelum(itemtype x){
    node *p = head;
    if(p->data == x){
        sisipAwal();
    }
    else{
        while(p->data != x){
            p = p->next;
        }
        baru->prev = p->prev;
        baru->next = p;
        p->prev->next = baru;
        p->prev = baru;
    }
}

void sisipSesudah(itemtype x){
    node *p = head;
    while(p->data != x){
        p = p->next;
    }
    baru->prev = p;
    baru->next = p->next;
    p->next->prev = baru; 
    p->next = baru;
}

void hapusAwal(){
    node *hapus = head;
    head = hapus->next;
    head->prev = NULL;
    free(hapus);
}

void hapusAkhir(){
    node *hapus = tail;
    tail = hapus->prev;
    tail->next = NULL; 
    free(hapus);
}

void hapusTertentu(itemtype x){
    node *hapus = head; 
    while(hapus->data != x){
        hapus = hapus->next;
    }
    hapus->prev->next = hapus->next;
    hapus->next->prev = hapus->prev;
    free(hapus);
}

void cetakHead(){
    node *p = head;
    while(p != NULL){//kalau p != NULL (pengkondisian jika NULL) maka tidak menggunakan p->data tapi cukup p saja
        printf("%i ", p->data);
        p = p->next;
    }
}

void cetakTail(){
    node *p = tail;
    while(p != NULL){
        printf("%i ", p->data);
        p = p->prev;
    }
}

void sisipUrut(){
    node *p = head;
    if(baru->data < p->data){
        sisipAwal();
    }
    else{
        while(p != NULL && baru->data > p->data){
            p = p->next;
        }
        if(p == NULL){
            sisipAkhir();
        }
        else if(baru->data == p->data){
            printf("Data Sudah ada\n");
        }
        else{
            sisipSebelum(p->data);
        }
    }
}

int main() {
    alokasi(0);
    head = tail = baru;
    int pilihan;
    char lagi = 'y';
    itemtype data, data2;
    while(lagi == 'y' || lagi == 'Y'){
    printf("\nMasukkan Pilihan:\n1. Sisip Awal\n2. Sisip Akhir\n3. Sisip Sebelum\n4. Sisip Sesudah\n5. Sisip Urut\n6. Hapus Awal\n7. Hapus Akhir\n8. Hapus Tertentu\n9. Cetak Ascending\n10. Cetak Descending");
    printf("\nPilihan: ");
    scanf("%i", &pilihan);
        switch(pilihan){
            case 1:
                printf("Masukkan Data: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                sisipAwal();
                break;
            case 2:
                printf("Masukkan Data: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                sisipAkhir();
                break; 
            case 3:
                printf("Masukkan Data: ");
                fflush(stdin);
                scanf("%i", &data);
                printf("Sisipkan sebelum? ");
                fflush(stdin);
                scanf("%i", &data2);
                alokasi(data);
                sisipSebelum(data2);
                break;
            case 4:
                printf("Masukkan Data: ");
                fflush(stdin);
                scanf("%i", &data);
                printf("Sisipkan Sesudah? ");
                fflush(stdin);
                scanf("%i", &data2);
                alokasi(data);
                sisipSesudah(data2);
                break; 
            case 5:
                printf("Masukkan Data: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                sisipUrut();
                break;
            case 6:
                hapusAwal();
                break; 
            case 7:
                hapusAkhir();
                break;
            case 8:
                printf("Masukkan Data yang akan dihapus: ");
                fflush(stdin);
                scanf("%i", &data);
                hapusTertentu(data);
                break;
            case 9:
                cetakHead();
                break;
            case 10:
                cetakTail();
                break; 
            default:
                printf("Perintah Tidak Sesuai!");
                break;
        }
        printf("Lagi? ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}