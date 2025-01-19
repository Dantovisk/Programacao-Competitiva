#include <bits/stdc++.h> 

using namespace std;

int v[1010];

int main(){
    long long soma = 0;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>v[i];
        soma+=v[i];
    }
    int media = soma/n;
    
    for(int i=0; i<n; i++){
        cout<<media-v[i]<<endl;
    }
}