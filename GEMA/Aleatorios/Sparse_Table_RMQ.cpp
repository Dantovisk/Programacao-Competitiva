// Exercicio sobre Range Minimum Query
// Pode ser resolvido com sparse table
#include <bits/stdc++.h>
using namespace std;

int stab[100005][17]; //sparse table que guardará os minimos

int v[100010];

int n, q;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i];
        stab[i][0]= v[i];
    }

    //preprocessamento
    for(int k=1; k<17; k++){ //iteraçao pelas potencias de 2
        for(int i=0; i + (1<<k) - 1 < n; i++){ //pega o minimo com base nas potencias menores
            stab[i][k]= min(stab[i][k-1], stab[i+(1<<(k-1))][k-1]);
        }
    }

    cin>>q;
    
    for(int i=0; i<q; i++){
        int s, e;
        cin>>s>>e;

        int k=0;
        while(1<<(k+1) < e-s) k++;
        cout<< min(stab[s][k], stab[e - (1<<k) +1][k]) <<"\n";
    }

    return 0;
}