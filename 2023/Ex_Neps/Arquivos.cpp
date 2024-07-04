#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b, resposta =0;
    cin>>n>>b;
    vector <int> coisas(n);
    for(int i =0; i<n; i++){
        cin>>coisas[i];
    }
    sort(coisas.begin(),coisas.end());
    int l =0, r =(n-1);
    while(l<=r){
        if(coisas[l]+coisas[r]<=b){
            resposta++;
            l++;
            r--;
        }else{
            resposta++;
            r--;
        }
    }
    cout<<resposta;
    return 0;
}