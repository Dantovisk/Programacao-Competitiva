#include <bits/stdc++.h>  
using namespace std;

vector<pair<int,int>> v;

int main(){
    int n;
    cin>>n;
    int a, b;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(), v.end());
    
    int fim = 0, resposta =0;
    for(int i=0; i<n; i++){
        if(v[i].second >=fim){
            resposta++;
            fim = v[i].first;
        }
    }
    
    cout<<resposta;
    return 0;
}