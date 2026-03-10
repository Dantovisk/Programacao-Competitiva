#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x; 
    cin>>n>>x;

    vector<int> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    //dois ponteiros
    int l  = 0, r = n-1;

    int cont = 0;
    while(l <= r){
        //se há apenas uma criança sobrando
        //ou não cabem as 2 crianças, pega a mais pesada
        if(l == r || v[l] + v[r] > x){
            r--;
        }
        else{
            l++; r--;
        }
    
        cont++;

    }
    cout<<cont<<"\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}