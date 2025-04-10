#include <bits/stdc++.h> // Subtrees and Paths - Hackerrrank
#define MAXN 100010      

using namespace std;
const int inf = 1e9+7;

int n, q;
vector<int> adj[MAXN];

//para o hld
int heavy[MAXN], depth[MAXN], par[MAXN], sz[MAXN], head[MAXN];

int id[MAXN], atual = 1;
int maxid[MAXN]; //retorna o maior id da subarvore de um no
//tree de max
int tree[4*MAXN], lazy[4*MAXN];

void dfs(int u, int p){
    heavy[u] = -1;
    par[u] = p;
    sz[u] = 1;

    int mx = 0;
    for(auto v: adj[u]){
        if(p == v) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];

        if(sz[v] > mx){
            mx = sz[v];
            heavy[u] = v;
        }
    }
}

void hld(int u, int h){
    head[u] = h;
    id[u] = atual++;
    maxid[u] = id[u];

    if(heavy[u] != -1){
        hld(heavy[u], h);
        maxid[u] = maxid[heavy[u]];
    }

    for(auto v: adj[u]){
        if(heavy[u] == v || par[u] == v) continue;

        hld(v, v);
        maxid[u] = maxid[v];
    }
}

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    tree[no] += lazy[no];

    if(l<r){
        lazy[2*no] += lazy[no];
        lazy[2*no+1] += lazy[no];
    }
    lazy[no] = 0;
}

void update(int no, int i, int j, int l, int r, int val){
    unlazy(no, i, j);
    if(i>r || j<l) return;
    if(i >= l && j<= r){
        lazy[no] += val;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(no*2, i, mid, l, r, val);
    update(no*2 + 1, mid+1, j, l, r, val);

    tree[no] = max(tree[2*no], tree[2*no+1]);
}


int query(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    if(i>r || j<l) return -inf;
    if(i >= l && j<= r)
        return tree[no];

    int mid = (i+j)/2;

    return max (query(no*2, i, mid, l, r), 
        query(no*2 + 1, mid+1, j, l, r));
    
}

int path(int a, int b){
    int res = -inf;

    while(head[a] != head[b]){
        if(depth[head[a]] < depth[head[b]]) swap(a,b);

        res = max(res, query(1, 1, n, id[head[a]], id[a]));
        a = par[head[a]];
    }

    if(depth[a] < depth[b]){
        swap(a, b);
    }
    res = max(res, query(1, 1, n, id[b], id[a]));

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    for(int i =1; i<n; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    hld(1, 1);

    cin>>q;

    for(int i =0; i<q; i++){
        string op; cin>>op;
        int a, b; cin>>a>>b;
        if(op == "add"){
            update(1, 1, n, id[a], maxid[a], b);
        } else{
            cout<<path(a, b)<<"\n";
        }
    }
   
    return 0;
}