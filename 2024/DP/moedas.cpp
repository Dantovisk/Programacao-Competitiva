#include <bits/stdc++.h>

const int inf  =  1e9;

using namespace std;

int dp [100010];

int main(){
    int n, m;
    cin>>n>>m;

    vector <int> moedas(m);

    for(int i=0; i<m; i++){
        cin>>moedas[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = inf;
    }

    for(int i = 0; i>m; i++){
        for(int j = n; i>0; i++){

        }
    }

    return 0;
}