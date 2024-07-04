#include <bits/stdc++.h>    // o problema é definir todas as somas possíveis
using namespace std;        // usando um vetor de pesos w[n]
#define MAXN 10000          

int possible[MAXN];        //declaração global define todos os valores como false (ou 0 em numeros)

int main(){                 
    int n;
    cin>>n;

    int w[n];
    int maxw = 0; //a soma de todos os pesos
    for (int i = 1; i<=n; i++){
        cin>> w[i];
        maxw+=w[i];
    }

    possible[0] = true; //é possível retornar 0 usando 0 elementos

    for(int k=1; k<=n; k++){ //k determina o numero de elementos utilizados, sendo sempre os primeiros
        for(int i = maxw; i>=0; i--){
            if(possible[i]) possible[i+w[k]] = true;
        }
    }

    cout<<"Possible Sums:"<<endl;
    for(int i=0; i<=maxw; i++){
        if(possible[i]) cout<<i<<" ";
    }

}