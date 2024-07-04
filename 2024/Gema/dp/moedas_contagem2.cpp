#include <bits/stdc++.h>
//algo similar com knapsack
//podemos representar valor[i] como a soma de todas as formas de contar
//com peso i

using namespace std;

int valor [1000010];

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> moedas(n);
    valor [0] = 1;
    for(int i=0; i<n; i++){
        cin >> moedas[i];
    }

    for(int i=0; i<n; i++){
        for(int w=1; w<=m; w++){
            if(w-moedas[i]>=0){
                valor[w] += valor[w-moedas[i]];
                valor[w]%=1000000007;
            }
        }
    }
    cout<<valor[m];
    return 0;   
}