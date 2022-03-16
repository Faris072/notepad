#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5

typedef int itemtype;
typedef struct tumpukan{
    itemtype item[MAX];
    int index;
} Stack; 

int inisialisasi(Stack *s);
int penuh(Stack *s);
int kosong(Stack *s);
void push(Stack *s, itemtype data);
itemtype pop(Stack *s);
itemtype kalkulator(itemtype data[]);
int derajat(char x);

int main(){
    Stack tumpukan;
    inisialisasi(&tumpukan);
    for(int i = 0; i < MAX; i++){
        push(&tumpukan,i);
    }
    while(tumpukan.index!=0){
        printf("%i ",pop(&tumpukan));
    }
    
}


int inisialisasi(Stack *s){
    return s->index=0;
}

int penuh(Stack *s){
    return (s->index==MAX);
}

int kosong(Stack *s){
    return (s->index==0);
}

void push(Stack *s, itemtype data){
    if(penuh(s)){
        printf("Stack overflow");
    }
    else{
        s->item[s->index]=data;
        s->index++;
    }
}

itemtype pop(Stack *s){
    itemtype keluar;
    if(kosong(s)){
        printf("Stack kosong");
    }
    else{
        s->index--;
        keluar = s->item[s->index];
    }
}

int derajat(char x){
    if(x == ')'){
        return 0;
    }
    else if(x == '-' || x == '+'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '^'){
        return 3;
    }
    else if(x == ')'){
        return 4;
    }
    else{
        return -1;
    }
}

void kalkulator(itemtype data[]){
    int length, bil1, bil2, bil3;
    length = strlen(data);
    for(int i = 0; i < length-1; i++){
        if(data[i]>=0 && data[i]<=9){
            if(data[i]=='1'){
                
            }
        }
    }
}