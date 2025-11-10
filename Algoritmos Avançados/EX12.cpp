#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tiii;

// IMPLEMENTAÇÃO DO DISJOINT SET UNION (UNION FIND)
struct UF{
    vector<int> sz, pai;
    UF(int n){
        sz.resize(n, 1);
        pai.resize(n);

        for(int i =0; i<n; i++){
            pai[i] = i;
        }
    }

    int find(int a){ //find com compressão de caminho
        while(pai[a] != a) return pai[a] = find(pai[a]);
        return pai[a];
    }

    //merge com compressão de rank
    void merge(int a, int b){
        a = find(a);
        b = find(b);

        if(sz[b] > sz[a]) swap(a, b);

        pai[b] = a;
        sz[a] += sz[b];
    }
};


void solve(){
    int n, m;
    cin>>n>>m;

    long long int total = 0;
    vector<tiii> v;

    UF dsu = UF(n+1);

    set <int> vis;

    bool deuruim = false;

    for(int i = 0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        v.push_back({w, a, b});

        if(vis.find(w) != vis.end()){
            deuruim = true;
        }
        vis.insert(w);
    }

    if(deuruim){
        cout<<"Esse nao e o caminho correto para a Cidade Perdida de Z.\n";
        return;
    }

    sort(v.begin(), v.end());

    vector<pair<int,int>> resp;

    for(auto[w, a, b]: v){
        if(dsu.find(a) == dsu.find(b)) continue;

        dsu.merge(a, b);

        if(a > b) swap(a, b);

        resp.push_back({a, b});
        total += w;
    }

    if(resp.size() < n-1) 
        cout<<"O vale nao pode ser completamente atravessado.\n";
    else{
        cout<<"Custo minimo: "<<total<<"\nPontes reconstruidas:\n";
        for(auto [a, b] : resp){
            cout<<a<<" - "<<b<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--) {
        solve();
        cout<<"\n";
    }


    return 0;
}