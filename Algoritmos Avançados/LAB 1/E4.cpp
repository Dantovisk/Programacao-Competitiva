#include <bits/stdc++.h>
using namespace std;

void solve(){
    int h; cin>>h;

    // lê os meses
    vector<int> v(12);
    for(int i =0; i<12; i++){
        cin>>v[i];
    }

    //ordena os crescimentos dos meses decrescente
    sort(v.rbegin(), v.rend());
    int i = 0;
    //pega os meses melhores até chegar na meta
    for(; i<12 && h> 0; i++){
        h -= v[i];
    }

    // nao foi o bastante
    if(h > 0) cout<<"nao cresce\n";
    else cout<<i<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    // cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}