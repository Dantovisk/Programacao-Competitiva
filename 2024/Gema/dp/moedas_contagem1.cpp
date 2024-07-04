#include <bits/stdc++.h>

using namespace std;

int valor [1000010];
int maior [1000010];

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> moedas(n);
    valor [0] = 1;
    for(int i=0; i<n; i++){
        cin >> moedas[i];
    }
    
    for(int i=1; i<=m; i++){
        for(auto m: moedas){
            if(i-m>=0){
                valor[i] += valor[i-m];
                valor[i]%=1000000007;
            }
        }
    }
    cout<<valor[m];
    return 0;   
}