#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//mencetak angka dari n ke 0
void rekursi(int n){
    if(n==0){
        printf("%i", n);
    }
    else{
        printf("%i ", n);
        rekursi(n-1);
    }
}


//mencetak angka dari 0 ke n
void rekursi2(int n, int a){
    if(n == 0){
        printf("%i ", a);
    }
    else{
        printf("%i ", a);
        rekursi2(n-1, a+1);
    }
}

//mengecek bilangan dalam array
void rekursi2(int n){
    if(n == )
}

int main(){
    // rekursi(10);
    rekursi2(5,0);
}