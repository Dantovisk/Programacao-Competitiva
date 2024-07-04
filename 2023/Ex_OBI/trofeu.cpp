#include <bits/stdc++.h>

int leitura[5];
int maior = -2;
int segmaior = -1;
int trofeu, placa;

 main(){
    for(int i = 0; i <5; i++){
        scanf("%d",&leitura[i]);
        if(leitura[i]>=maior){
            trofeu++;
            maior=leitura[i];
            leitura[i]=-5;        
        }
    }
    for(int j = 0; j <5; j++){
        if(leitura[j]>=segmaior){
            placa++;
            segmaior=leitura[j];
            leitura[j]=-1;
            
        }
    }

    printf("%d %d",trofeu,placa);


 }