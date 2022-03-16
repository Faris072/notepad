#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef int itemtype;
typedef struct stack s;
struct stack{
    itemtype data;
    s *next;
};

s *baru;
s *head;
s *next = NULL;
s *tail = NULL;

void alokasi(itemtype x){
    baru = (s *)malloc(sizeof(s));
    if(!baru){
        printf("Alokasi gagal");
    }
    else{
        baru->data = x;
        baru->next = NULL;
    }
}

void push(){
    baru->next = head;
    head = baru;
}

void pop(){
    s *p = head;
    if(p == tail){
        printf("Stack kosong");//supaya 0 di awal alokasi tidak terbaca
    }
    else{
        printf("%i ", p->data);
        head = head->next;
        free(p);
    }
}

void cetakStack(){
    s *p = head;
    while(p->next != NULL){
        printf("%i ", p->data);
        p = p->next;
    }
    printf("\n");
}

void main(){
    alokasi(0);
    head = tail = baru;
    int pilihan;
    char lagi = 'y';
    itemtype data;
    while(lagi == 'y' || lagi == 'Y'){
        printf("Pilih Menu: \n1. Push\n2. Pop\n3. Pop semua\n4. Cetak data di stack\n");
        printf("Pilihan: ");
        fflush(stdin);
        scanf("%i", &pilihan);
        switch(pilihan){
            case 1:
                printf("Masukkan data: ");
                fflush(stdin);
                scanf("%i", &data);
                alokasi(data);
                push();
                break;
            case 2:
                printf("POP: ");
                pop();
                printf("\n");
                break;
            case 3:
                printf("POP: ");
                while(head->next != NULL){//supaya 0 di awal alokasi disembunyikan
                    pop();
                }
                printf("\n");
                break;
            case 4:
                cetakStack();
                break;
            default:
                printf("Perintah tidak sesuai");
                break;
        }
        printf("Lagi? ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}