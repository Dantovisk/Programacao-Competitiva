#include <bits/stdc++.h>

using namespace std;

int prefixSum[10][100010];
int total[10];

int main(){
    int n, m; //numero de algarismos do cofre, numero de operações
    cin>>n>>m;
    int lido;
    for(int i=1; i<=n;i++){
        cin>>lido;
        prefixSum[lido][i]++;
        for(int j=0; j<=9; j++){
            prefixSum[j][i]+=prefixSum[j][i-1];
        }
    }
    int anter = 0, atual;

    for(int i=0; i<m; i++){
        cin>> atual;

        for(int j=0; j<=9; j++){
            if(atual>anter){
                total[j]+= prefixSum[j][atual]-prefixSum[j][anter];
            }else{
                total[j]+= prefixSum[j][anter-1]-prefixSum[j][atual-1];
            }
        }
        anter=atual;
    }
    for(int j=0; j<=9; j++){
        cout<<total[j]<<" ";
    }

    return 0;
}

/*
para cada número lido, adicione na soma de prefixo

soma[numero escolhido] [i] ++;
onde i é o indice do numero

então some os prefixos da ordem i, somando pelo anterior:
se o número escolhido for 6, ficará algo tipo 

soma[0 a 10][i] = 0000011111;

entao crie uma int para a posicao anterior e a atual

para cada nova posicao atual:

	para todos os digitos:
	faça a diferença dos prefixos, e some no total[] dos digitos
	ultima posicao=posicao atual

dps printa e já era */