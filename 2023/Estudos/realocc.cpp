#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(){
    int *p1;
    int i;
    p1 = (int*)malloc(sizeof(int)*2);
    std::cout<<"\nLocal incial: "<< p1;

    p1 = (int*)realloc(p1, sizeof(int)*20);
    std::cout<<"\nLocal meio: "<< p1;

    for(i=0; i<20;i++){
        p1[i]=i;
    } 
    
    p1 = (int*)realloc(p1, sizeof(int)*2);
    std::cout<<"\nLocal final: "<< p1;

    //realloc aumentou o tamanho das memórias utilizadas de p1
    //portanto, mudou o endereço das memórias para achar um local com espaço
}