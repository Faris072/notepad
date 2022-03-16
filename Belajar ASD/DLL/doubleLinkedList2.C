#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int itemtype;
typedef struct simpul dnode;
struct simpul{
    itemtype data;
    dnode *next;
    dnode *prev;
};

dnode *baru;
dnode *head = NULL;
dnode *tail = NULL;

void alokasi(itemtype x){
    baru = (dnode *)malloc(sizeof(dnode));
    if(!baru){
        printf("Alokasi gagal!");
    }
    else{
        baru->data = x;
        baru->next=NULL;
        baru->prev=NULL;
    }
}

void sisipAwal(){
    baru->next = head;
    baru->prev=NULL;
    head->prev=baru;
    head=baru;
}

void sisipAkhir(){
    baru->prev = tail;
    baru->next = NULL;
    tail->next = baru;
    tail = baru;
}

void sisipSebelum(itemtype x){
    dnode *p = head;
    while(p->data != x){
        p = p->next;
    }
    baru->next = p;
    baru->prev = p->prev;
    p->prev->next = baru;
    p->prev = baru;
}

void sisipSesudah(itemtype x){
    dnode *p = head;
    while(p->data != x){
        p = p->next;
    }
    baru->next = p->next;
    baru->prev = p;
    p->next->prev = baru;
    p->next = baru;
}

void hapusAwal(){
    dnode *p = head;
    head = p->next;
    p->next->prev = NULL;
    free(p);
}

void hapusAkhir(){
    dnode *p = tail;
    head = p->prev;
    p->prev->next = NULL;
    free(p);
}

void hapusTertentu(itemtype x){
    dnode *p = head;
    while(p->data != x){
        p = p->next;
    }
    p->next->prev = p->prev;
    p->prev->next = p->next;
    free(p);
}

void cetakHead(){
    dnode *p = head;
    while(p != NULL){
        printf("%i", p->data);
        p = p->next;
    }
    printf("\n");
}

void cetakTail(){
    dnode *p = tail;
    while(p != NULL){
        printf("%i ", p->data);
        p = p->prev;
    }
    printf("\n");
}

void sisipUrut(){
    dnode *p = head;
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
            sisipSesudah(p->data);
        }
        else{
            sisipSebelum(p->data);
        }
    }
}

int main(){
    alokasi(0);
    head = tail = baru;
    itemtype data, data2;
    char lagi = 'y';
    int pilihan;
    while(lagi == 'y' || lagi == 'Y'){
        printf("Masukkan Pilihan:\n1. Sisip awal\n2. Sisip akhir\n3. Sisip sebelum\n4. Sisip sesudah\n5. hapus awal\n6. hapus akhir\n7. Hapus tertentu\n8. Cetak head\n9. Cetak tail\n10. Sisip Urut\n");
        printf("Pilihan: ");
        fflush(stdin);
        scanf("%i", &pilihan);
        switch(pilihan){
            case 1:
                printf("Masukkan Data: ");
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
                printf("Sisipkan data sebelum? ");
                fflush(stdin);
                scanf("%i", &data2);
                alokasi(data);
                sisipSebelum(data2);
                break;
            case 4:
                printf("Masukkan Data: ");
                fflush(stdin);
                scanf("%i", &data);
                printf("Sisipkan data Sesudah? ");
                fflush(stdin);
                scanf("%i", &data2);
                alokasi(data);
                sisipSesudah(data2);
                break;
            case 5:
                hapusAwal();
                break;
            case 6:
                hapusAkhir();
                break;
            case 7:
                printf("Masukkan Data yang akan dihapus: ");
                fflush(stdin);
                scanf("%i", &data);
                hapusTertentu(data);
                break;
            case 8:
                cetakHead();
                break;
            case 9:
                cetakTail();
                break;
            case 10:
                printf("Masukkan Data: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                sisipUrut();
                break;
            default:
                printf("Pilihan tidak sesuai");
        }
        printf("lagi? ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}