#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

vector <int> adj[MAXN];
int inicio[MAXN];

int lazy[8*MAXN];
int v[2*MAXN];
int tree[8*MAXN];
int tin[MAXN], tout[MAXN];
int tempo =0;

void dfs(int u, int p){
    tin[u] = ++tempo;
    v[tin[u]] = inicio[u];
    for(int x: adj[u]){
        if(x!=p) dfs(x, u);
    }
    tout[u] = ++tempo;
    v[tout[u]] = -inicio[u];
}

void unlazy(int l, int r){
    
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

int main(){
    int n; cin>>n;

    for(int i=2; i<=n; i++){
        int a; cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    for(int i=1; i<=n; i++) cin>>inicio[i];

    dfs(1, 0);


    return 0;
}