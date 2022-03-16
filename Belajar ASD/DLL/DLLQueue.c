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
        printf("Alokasi gagal");
    }
    else{
        baru->data = x;
        baru->next = NULL;
        baru->prev = NULL;
    }
}

void sisipAkhir(){
    baru->prev = tail;
    baru->next = NULL;
    tail->next = baru;
    tail = baru;
}

void hapusAwal(){
    dnode *p = head;
    p->next->prev = NULL;
    head = p->next;
    free(p);
}

void cetak(){
    dnode *p = head;
    while(p != NULL){
        printf("%i ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    alokasi(0);
    head = tail = baru;
    char lagi = 'y';
    int pilihan;
    itemtype data;
    while(lagi == 'y' || lagi == 'Y'){
        printf("Masukkan pilihan: \n1. Enqueue\n2. Dequeue\n3. Cetak\n");
        printf("Pilihan: ");
        fflush(stdin);
        scanf("%i", &pilihan);
        
        switch(pilihan){
            case 1:
                printf("Masukkan data: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                sisipAkhir();
                break;
            case 2:
                hapusAwal();
                break;
            case 3:
                cetak();
                break;
            default:
                printf("Pilihan tidak sesuai! ");
                break;
        }

        printf("Lagi? ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}