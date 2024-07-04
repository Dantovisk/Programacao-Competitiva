#include <bits/stdc++.h>   //programa que, dado uma lista de números, responde a soma de N
using namespace std;  //intervalos dessa lista

int cartas [100010][2], somaprefixos[100010], operacoes[100010];
int main()
{
    int n, t;
    cin>>n>>t;
    for(int i=0; i<n; i++){
        cin>>cartas[i][0];
    }
    for(int i=0; i<n; i++){
        cin>>cartas[i][1];
    }


    int a, b;
    for (int i=0; i<t; i++){
        cin>>a>>b;
        operacoes[a]++;
        operacoes[b+1]--;
    }

    for (int i=1; i<=n; i++){
        somaprefixos[i] = somaprefixos[i-1] + operacoes[i];
    }

    for (int i=1; i<=n; i++){
        if(somaprefixos[i]%2==0){
            cout<<cartas[i-1][0]<<" ";
        }else{
            cout<<cartas[i-1][1]<<" ";
        }
    }

    return 0;
}