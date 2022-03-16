#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int itemtype;
typedef struct simpul node;
struct simpul{
    itemtype data;
    node *next;
};

node *head = NULL;
node *baru;

void alokasi(itemtype x){
    baru = (node *) malloc(sizeof(node));
    if(baru==NULL){
        printf("Alokasi memori gagal!");
    }
    else{
        baru->data = x;
        baru->next = NULL;
    }
}

void sisipAwal(){
    baru->next = head;
    head = baru;
}

void sisipAkhir(){
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = baru;
}

void sisipSebelum(itemtype x){
    node *before = head;
    while(before->next->data != x){
        before = before->next;
    }
    baru->next = before->next;
    before->next = baru;
}

void sisipSetelah(itemtype x){
    node *after = head;
    while(after->data != x){
        after = after->next;
    }
    baru->next = after->next;
    after->next = baru;
}

void free_node(node *p){
    free(p);
    p=NULL;
}

void hapusAwal(){
    node *hapus = head;
    head = hapus->next;
    free_node(hapus);
}

void hapusAkhir(){
    node *hapus = head, *before;
    while(hapus->next != NULL){
        before = hapus;
        hapus = hapus->next;
    }
    before->next = NULL;
    free_node(hapus);
}

void hapusTertentu(itemtype x){
    node *hapus = head, *before = head;
    while(hapus->data != x){
        before = hapus;
        hapus = hapus->next;
    }
    before->next = hapus->next;
    free_node(hapus);
}

void cetak(){
    node *p = head = head;
    while(p != NULL){
        printf("%i ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    char lagi = 'y';
    int pilihan;
    itemtype data, data2;
    printf("SLL:");
    while(lagi == 'y' || lagi == 'Y'){
        printf("\n\nMasukkan Pilihan: \n1. Sisip Awal\n2. Sisip Akhir\n3. Sisip Sebelum\n4. Sisip Sesudah\n5. Hapus Awal\n6. Hapus Akhir\n7. Hapus Tertentu\n8. Cetak\n\n");
        printf("Pilihan: ");
        fflush(stdin);
        scanf("%i", &pilihan);
        switch(pilihan){
            case 1: 
                printf("Masukkan data yang akan disisipkan: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                sisipAwal();
                break;
            case 2: 
                printf("Masukkan data yang akan disisipkan: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                sisipAkhir();
                break;
            case 3: 
                printf("Masukkan data yang akan disisipkan: ");
                fflush(stdin);
                scanf("%i", &data);
                printf("Data akan disisipkan sebelum? ");
                fflush(stdin);
                scanf("%i", &data2);
                alokasi(data);
                sisipSebelum(data2); 
                break;
            case 4: 
                printf("Masukkan data yang akan disisipkan: ");
                fflush(stdin);
                scanf("%i", &data);
                printf("Data akan disisipkan sesudah? ");
                fflush(stdin);
                scanf("%i", &data2);
                alokasi(data);
                sisipSetelah(data2); 
                break;
            case 5: 
                hapusAwal();
                break; 
            case 6:
                hapusAkhir();
                break;
            case 7:
                printf("Masukkan data yang akan dihapus: ");
                fflush(stdin);
                scanf("%i", &data);
                hapusTertentu(data);
                break;
            case 8:
                cetak();
                break;
            default:
                printf("Inputan tidak sesuai!");
                break;
        }

        printf("Lagi? (y/n): ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}