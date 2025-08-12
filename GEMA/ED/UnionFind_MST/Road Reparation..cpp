#include <bits/stdc++.h>    //CSES Road Reparation
using namespace std;

#define MAXN 100010
#define int long long int
#define tiii tuple<int, int, int>

priority_queue <tiii, vector<tiii>, greater<tiii>> pq;

int par[MAXN];
int sz[MAXN];

int find(int a){
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(sz[b] > sz[a]) swap(a, b);

    sz[a] += sz[b];
    par[b] = a;
}

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        pq.push({c, a, b});
    }

    //init
    for(int i=1; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }
    int resp = 0;
    int cont = 0;

    while(!pq.empty()){
        auto [a, b, c] = pq.top();
        pq.pop();

        b = find(b);
        c = find(c);

        if(b==c) continue;

        resp+= a;
        cont++;
        merge(b, c);
    }

    if(cont==(n-1)) cout<<resp<<"\n";
    else cout<<"IMPOSSIBLE\n";
    return 0;
}