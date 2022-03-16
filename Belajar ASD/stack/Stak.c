#include <stdio.h>

#define MAX 10 

typedef int itemtype;//typedef disini untuk mengaliaskan int sebagai itemtype
typedef struct {//typedef disini untuk mendefinisikan struct sebagai Stack
    itemtype item[MAX];
    int count;
} Stack;

void init(Stack *s){
    s->count = 0;
}

int penuh(Stack *s){
    return (s->count == MAX);
}

int kosong(Stack *s){
    return (s->count==0);
}

void push(Stack *s, itemtype data){
    if(penuh(s)){
        printf("Data penuh");
    }
    else{
        s->item[s->count]=data;
        s->count++;
    }
}

itemtype pop(Stack *s){
    itemtype temp;
    if(kosong(s)){
        printf("Data Kosong");
        return ' ';
    }
    else{
        s->count--;
        temp = s->item[s->count];
        return temp;
    }
}

int kekuatan(x){
    if(x=='(')
		return 0;
	else if((x=='+') || (x=='-'))
		return 1;
	else if((x=='*') || (x=='/'))
		return 2;
	else if(x=='^')
		return 3;
	else
		return -1;
}

//infix ke posifx
int main(){
    char lagi = 'y',bil[255];
    Stack tumpuk;
    init(&tumpuk);
    printf("Masukkan operasi matematika: ");
    
    
}