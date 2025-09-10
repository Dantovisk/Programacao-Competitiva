#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;



const int MAX = 2e5+7;

vi adj[MAX];

ll w[MAX], v[MAX], cont[MAX];

void dfs(int u, int p){
    for(auto x: adj[u]){
        if(x == p) continue;
        dfs(x, u);
        v[u] += v[x];
    }
    cont[u] = w[u] / v[u];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i =1; i<=n; i++){
        cin>>w[i];
    }
    for(int i =1; i<=n; i++){
        cin>>v[i];
    }

    for(int i =1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    sort(cont+1, cont+n+1);

    for(int i = 1; i<=n; i++) cout<<cont[i] * v[1]<<"\n";    
}