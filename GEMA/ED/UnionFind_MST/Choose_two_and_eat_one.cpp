#include <bits/stdc++.h>    //atcoder
using namespace std;

#define int long long int
#define tiii tuple<int,int,int>

priority_queue <tiii> pq;
int v[510];

int par[510];
int sz[510];

int modexp(int base, int exp, int mod){
    if(exp == 1) return base % mod;
    if(exp == 0) return 1;
    if(exp%2) return (base * modexp(base, exp-1, mod))%mod;
    int k = modexp(base, exp/2, mod);
    return (k*k) % mod;
}

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
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int k = (modexp(v[i], v[j], m) + modexp(v[j], v[i], m))%m;
            pq.push({k, i, j});
        }
    }

    for(int i=0; i<n; i++){
        par[i] = i;
        sz[i] = 1;
    }

    int resp = 0;

    while(!pq.empty()){
        auto [a,b,c] = pq.top();
        pq.pop();

        b = find(b);
        c = find(c);

        if(b == c) continue;

        resp+=a;
        merge(b, c);
    }

    cout<<resp<<"\n";

    return 0;
}