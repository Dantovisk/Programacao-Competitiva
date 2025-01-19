//Atcoder - Count Descendants
#include <bits/stdc++.h>
#define MAXN 200010
#define int long long int

using namespace std;

vector<int> adj[MAXN];
int vis[MAXN];

vector<int> levels[MAXN];
int tin[MAXN];
int tout[MAXN];

int tempo = 0;

void dfs(int u, int p, int l){
    vis[u] = 1;
    tin[u] = ++tempo;
    levels[l].push_back(tin[u]);
    
    for(int x: adj[u]){
        if (x==p) continue;
        if(!vis[x]) dfs(x, u, l+1);
    }

    tout[u]= tempo;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin>>n;

    for(int i=2; i<=n; i++){
        int a;
        cin>>a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, 0, 0);

    cin>>q;

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        auto ptr1 = lower_bound(levels[b].begin(), levels[b].end(), tin[a]);
        auto ptr2 = upper_bound(levels[b].begin(), levels[b].end(), tout[a]);
        cout<<ptr2-ptr1<<endl;
    }

    return 0;
}