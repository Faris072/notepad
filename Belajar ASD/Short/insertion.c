#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define MAX 20

void insertionShort(int data[]){
    int i = 1, j,key,k;
    while(i < MAX ){
        key = data[i];
        j = i-1;
        while(j >= 0 && data[j] > key){
            data[j+1] = data[j];
            j=j-1;
        }
        data[j+1] = key;
        i=i+1;
    }
    for(k = 0; k < MAX; k++){
        printf("%d ", data[k]);
    }
}

int main(){
    int i,a[]={3,5,7,9,7,2,10,12,15,30,26,2,8,6,4,16,18,13,14};
    insertionShort(a);
}