//Path Queries - CSES
#include <bits/stdc++.h>
#define MAXN 200010
#define int long long int

using namespace std;

//para esse exercicio, usaremos uma segtree de soma
int tree[8*MAXN];
vector<int> adj[MAXN];
int peso[MAXN];
int vis[MAXN];

//arvore planificada pelo euler tour
int v[MAXN * 2];
int tin[MAXN];
int tout[MAXN];


int tempo = 0;

void dfs(int u, int p){
    vis[u] = 1;
    tin[u] = ++tempo;
    v[tin[u]] = peso[u];
    
    for(int x: adj[u]){
        if (x==p) continue;
        if(!vis[x]) dfs(x, u);
    }

    tout[u]= ++tempo;
    v[tout[u]] = peso[u];
}

void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;
    build(no*2, l, mid);
    build(no*2+1, mid+1, r);

    tree[no] = tree[no*2] + tree[no*2 + 1];
}

void update(int no, int i, int j, int ind, int val){
    if(i>ind || j<ind) return;
    if(i==j){
        tree[no] = val;
        return;
    }

    int mid = (i+j)/2;
    update(no*2, i, mid, ind, val);
    update(no*2+1, mid+1, j, ind, val);

    tree[no] = tree[no*2] + tree[no*2 + 1];
}

int query(int no, int i, int j, int l, int r){
    if(i>r || j<l) return 0;
    if(i>=l && j<=r){
        return tree[no];
    }

    int mid = (i+j)/2;
    return query(no*2, i, mid, l, r) +query(no*2+1, mid+1, j, l, r);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin>>n>>q;

    for(int i=1; i<=n; i++) cin>>peso[i];

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    build(1, 1, 2*n);

    for(int i=0; i<q; i++){
        int a, b, c;
        cin>>a>>b;
        if(a==1){
            cin>>c;
            update(1, 1, 2*n, tin[b], c);
            update(1, 1, 2*n, tout[b], c);

        }else if(a==2){
            cout<<query(1, 1, 2*n, tin[b], tout[b])/2<<"\n";
        }
    }

    return 0;
}