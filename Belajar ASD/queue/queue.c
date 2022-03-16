#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 5

typedef int itemtype;
typedef struct{
    itemtype item[MAX];
    int front;//front untuk menunjuk antrian terdepan
    int rear;//rear untuk menunjuk antrian terbelakang
    int count;//count untuk menghitung jumlah data
} queue;

void init(queue *q){
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

int penuh(queue *q){
    return (q->count==MAX);
}

int kosong(queue *q){
    return (q->count==0);
}

void enqueue(queue *q, itemtype data){
    if(penuh(q)){
        printf("Data penuh");
    }
    else{
        q->item[q->rear]=data;//data akan dimasukkan ke urutan terbelakang
        q->rear = (q->rear+1)%MAX;//untuk menunjuk posisi rear sekarang
        q->count++;//data ditambah 1
    }
}

itemtype dequeue(queue *q){
    itemtype temp;
    if(kosong(q)){ 
        printf("Data Kosong");
    }
    else{
        temp=q->item[q->front];//untuk mengambil data yang paling depan
        q->front=(q->front+1)%MAX;//untuk menunjuk data yang paling depan sekarang
        q->count--;//jumlah data dikurangi 1
        return temp;
    }
}

int main(){
    itemtype data;
    queue q;
    init(&q);
    enqueue(&q,5);
    enqueue(&q,6);
    printf("%i ",dequeue(&q));
    printf("%i ",dequeue(&q));
    enqueue(&q,4);
    printf("%i ",dequeue(&q));
}