#include <bits/stdc++.h>
#define MAXN 200010

int par[MAXN];
int sz[MAXN];
stack <pair<int,int>> hist;
int components = 0;

using namespace std;

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a==b) return;

    if(sz[a] < sz[b]) swap(a, b);

    hist.push({b, par[b]});
    hist.push({a, sz[a]});
    hist.push({-1, components});

    par[b] = a;
    sz[a] += sz[b];
    components--;

}

int find(int a){
    while(par[a] != a) a = par[a];
    return a;
}

void rollback() {
    if(hist.empty()) return;

    components = hist.top().second;
    hist.pop();
    
    auto [a, sz_a] = hist.top(); hist.pop();
    auto [b, par_b] = hist.top(); hist.pop();

    sz[a] = sz[a];
    par[b] = par_b;
}


int main(){
    int n, m;
    cin>>n>>m;
    components = n;

    for(int i =0; i<n; i++){
        par[i] = i;
        sz[i] = 1;
    }




    return 0;
}