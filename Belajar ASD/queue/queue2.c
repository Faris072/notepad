#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 10

typedef int itemtype;
typedef struct{
    itemtype item[MAX];
    int count;
    int rear;
    int front;
} queue;

void inisialisasi(queue *q){
    q->count = 0;
    q->rear = 0;
    q->front = 0;
}

int penuh(queue *q){
    return (q->count==MAX);
}

int kosong(queue *q){
    return (q->count==0);
}

void enqueue(queue *q, itemtype data){
    if(penuh(q)){
        printf("Data Penuh");
    }
    else{
        q->item[q->rear]=data;
        q->rear = (q->rear+1)%MAX;
        q->count++;
    }
}

itemtype dequeue(queue *q){
    itemtype temp;
    if(kosong(q)){
        printf("Data Kosong");
        return ' ';
    }
    else{
        temp = q->item[q->front];
        q->front = (q->front+1)%MAX;
        q->count--;
        return temp;
    }
}

int main(){
    itemtype data;
    queue q;
    int aksi;
    char lagi='y';
    inisialisasi(&q);
    while(lagi!='q' || lagi=='Q'){
        printf("Pilih aksi: \n1. Enqueue\n2. Dequeue\n");
        printf("Pilihan:");
        scanf("%i", &aksi);
        switch(aksi){
            case 1: 
                printf("Masukkan Data: ");
                scanf("%i", &data);
                enqueue(&q,data);
                break;
            case 2:
                printf("%i \n", dequeue(&q));
                break;
            default:
                printf("Pilihan tidak sesuai");
                break;
        }
        printf("Ketik 'q' atau 'Q' untuk keluar dan ketik sembarang untuk melanjutkan: ");
        fflush(stdin);
        scanf("%c", &lagi);
        printf("\n");
    }
}