#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(){
    int *p1, *p2;
    p1 = (int*) malloc(sizeof(int)*2);
    p2 = (int*) calloc(2, sizeof(int)); // calloc pede o n de elementos e o tamanho de cada

    std::cout<<"\np1: "<< p1[0] <<" " << p1[1];
    std::cout<<"\np2: "<< p2[0] <<" " << p2[1];

    //a diferença é que calloc coloca os valores em 0
}