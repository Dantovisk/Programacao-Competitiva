#include <bits/stdc++.h>

using namespace std;

int v[110];
int dp[10010];
vector<int> bucket[10010];

int main(){
    int n; cin>>n;
    int soma = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        soma+=v[i];
    }
    if(soma%2 !=0 ){
        cout<<-1;
        return 0;
    }
    soma/=2;

    //isso eh pra fazer o two bucket
    for(int i =0; i<n; i++){
        for(int j = soma; j>0; j--){
            if(j-v[i]>=0 && dp[j-v[i]] + v[i] > dp[j]){
                dp[j] =  dp[j-v[i]] + v[i];
                bucket[j] = bucket[j-v[i]];
                bucket[j].push_back(v[i]);
                
            }
        }
    }
    //cout<<dp[soma]<<endl;
    //for(int x: bucket[soma]) cout<<x<<" ";

    if(dp[soma] != soma){
        cout<<-1;
        return 0;
    }

    //aqui separamos em dois vetores para construir a resposta
    vector<int> alice = bucket[soma], bob;
    int j = 0;
    for(int i = 0; i<n; i++){
        if(v[i] != alice[j]) bob.push_back(v[i]);
        else j++;
    }

    j = 0;
    int saldo = 0;
    
    for(int x: alice){
        cout << x<< " ";
        saldo += x;
        while(saldo > 0 && j < bob.size()){
            cout<<bob[j]<<" ";
            saldo += bob[j];
            j++;
        }
    }

    return 0;
}