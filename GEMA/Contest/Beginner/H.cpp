#include <bits/stdc++.h> //Ainda ta errado
#define ll long long

using namespace std;

int v[200010], rec[200010];
map <int, int> consec;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set <int> vis;

    int n; cin>>n;

    int cont = 0;
    int atual = -1;

    for(int i=0; i<n; i++){
        cin>>v[i];
        vis.insert(v[i]);
    }

    for(int i=0; i<n; i++){
        if(v[i] == atual) cont++;
        else {
            cont = 1;
            consec[v[i]] = 1;
            atual = v[i];
        }
        consec[v[i]] = max(consec[v[i]], cont);
    }

    memset(rec, -1, sizeof(rec));

    for(auto [num, qt] : consec){
        if(rec[qt] == -1) rec[qt] = num;
        else{
            rec[qt] = min(rec[qt], num);
        }
    }

    int mex = 0;
    while(vis.find(mex) != vis.end()) mex++;

    for(int i =0 ; i<n; i++){
        if(rec[i] != -1) mex = min(mex, rec[i]);
        
        cout<<mex<<" ";
    }
    
}