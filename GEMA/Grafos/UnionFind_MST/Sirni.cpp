#include <bits/stdc++.h>    //Sirni - COCI17
using namespace std;

#define int long long int
#define tiii tuple<int,int,int>

priority_queue <tiii, vector<tiii>, greater<tiii>> pq;
set <int> v;
int ind[10000010];

map <int, int> indmap;

int par[100010];
int sz[100010];

int find(int a){
    if(a==par[a]) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(sz[b] > sz[a]) swap(a,b);

    sz[a] += sz[b];
    par[b] = a;
}

int32_t main(){
    int n, m = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        int a; cin>>a;
        v.insert(a);
        m = max(a, m);
    }

    //precomputaremos para todo valor i qual é o próximo
    //numero maior que i que aparece na entrada.

    int k = 0;
    for(auto x: v){
        while(k <= x){
            ind[k] = x;
            k++;
        }
    }

    int z = 0;
    //gerando os pares "bons"
    for(auto x: v){
        indmap[x] = z;
        z++;
        for(int i=1; (i*x) < m; i++){
            pq.push({ind[i*x] % x, x, ind[i*x]});
            //cout<<ind[i*x]<<" % "<<x<<" = "<<ind[i*x] % x<<"\n";
        }
    }

    for(int i=0; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }

    int resp = 0;


    while(!pq.empty()){
        auto [a,b,c] = pq.top();
        pq.pop();
        b = indmap[b];
        c = indmap[c];

        b = find(b);
        c = find(c);

        if(b == c) continue;
        resp+=a;
        merge(b, c);
    }

    cout<<resp;
    

    return 0;
}