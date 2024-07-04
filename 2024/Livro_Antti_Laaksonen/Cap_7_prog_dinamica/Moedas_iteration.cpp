#include <bits/stdc++.h>

using namespace std;

int valor [1000010];

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> moedas(n);
    valor [0] = 0;
    for(int i=0; i<n; i++){
        cin >> moedas[i];
    }
    
    for(int i=1; i<=m; i++){
        valor[i]= 10000000;
        for(auto m: moedas){
            if(i-m>=0){
                valor[i] = min(valor[i], valor[i-m]+1);
            }
        }
    }
    if(valor[m]>=10000000) cout<<-1;
    else cout<<valor[m];
    return 0;   
}