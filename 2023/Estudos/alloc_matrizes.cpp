#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(){
    int **p; //criação de um ponteiro para ponteiros
    int i, j, k;
    int n = 4, m = 3; //tamanho da matriz

    p = (int**)malloc(sizeof(int*)* n); // ao invés de size of int, size of int*,
    //pois estamos trabalhando com um ponteiro de ponteiros, multiplicado por n

    for(i=0; i<n; i++){
        p[i]= (int*)malloc(sizeof(int)* m); //cria n ponteiros para int de tamanho m
    } 

    k=1;

    for(i=0; i<n;i++){
        for(j=0; j<m;j++){
            p[i][j]=k;
            k++;
            std::cout<< p[i][j] << " ";
        }
        std::cout<<"\n";

    }
    

}