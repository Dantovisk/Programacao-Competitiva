#include <bits/stdc++.h>    // o problema é definir qual a soma máxima de um caminho numa grade N x N
using namespace std;        // em que o caminho começa no canto sup. esq e termina no canto. inf dir
#define MAXN 10000          //apenas podendo se mover para baixo ou para a direita

int sum[MAXN][MAXN];        //seja sum[i][j] a soma maxima do caminho que termina nos indices i e j

int main(){                 //então a resposta será sum[n][n]
    int n;

    cin>>n;

    int value[n+1][n+1];
    sum[0][0]=0;

    for (int y = 1; y <= n; y++) {          //leitura da matriz
        for (int x = 1; x <= n; x++) {
            cin >> value[y][x];
        }
    }

    for (int y = 1; y <= n; y++) {          //a resposta se baseia no fato de que sum[i][j]
        for (int x = 1; x <= n; x++) {      //é igual ao value[i][j] + o maior entre sum[i-1][j]
            sum[y][x] = max(sum[y][x-1], sum[y-1][x]) + value[y][x]; // e sum[i][j-1]
        }
    }

    cout<<"Max Sum: "<<sum[n][n];
}

/*
INPUT DE TESTE:
3
1 2 5
9 4 3
8 1 1

OUTPUT:
Max sum: 20
*/