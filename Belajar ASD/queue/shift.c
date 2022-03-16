#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 20

typedef int itemtype;
typedef struct{
    itemtype item[MAX];
    int rear;
    int front;
    int count;
} queue;

queue q;

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
        printf("Data Penuh");
    }
    else{
        q->item[q->rear]=data;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

itemtype dequeue(queue *q){
    itemtype keluar;
    if(kosong(q)){
        printf("Data Kosong"); return ' ';
    }
    else{
        keluar = q->item[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return keluar;
    }
}

void enqueueBiner(int data){
    init(&q);
    int hasil, sisa;
    while(data!=0){
        sisa = data % 2;
        data = data/2;
        enqueue(&q, sisa);
    }
}

void display(queue *q)
{
	int i = q->front;
	while(i != q->rear)
	{
		printf("%d ", q->item[i]);
		i = (i+1)%MAX;//seperti menghitung jumlah isi array
	}
}

int main(){
    char lagi = 'y';
    while(lagi=='y'||lagi=='Y'){
    int data,shift,temp,pangkat=0,hasil = 0;
    
        init(&q);
        printf("\nMasukkan Data: ");
        scanf("%i", &data);
        printf("Masukkan Jumlah Shift: ");
        scanf("%i", &shift);
        enqueueBiner(data);
        printf("Biner: ");
        display(&q);
        printf("\nBiner shift: ");
        for (int i = 0; i < shift; i++){
            temp = dequeue(&q);
            enqueue(&q, temp);
        }
        display(&q);
        while(q.count!=0){
            hasil = hasil + dequeue(&q) * pow(2,pangkat);
            pangkat++;
        }
        printf("\nHasil Akhir: %i", hasil);
        printf("\n");
        printf("lagi? (y/t): ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}