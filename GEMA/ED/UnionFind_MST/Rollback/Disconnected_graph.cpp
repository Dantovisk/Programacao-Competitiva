#include <bits/stdc++.h> // Codeforces - Connect and Disconnect
using namespace std;     // Conectividade dinâmica
#define MAXN 10010       // Basicamente usa seg para manter as arestas 
#define pii pair<int,int>// ativas em um intervalo de tempo e responde offline
#define MAXM 100010

stack <pii> hist; 
int par[MAXN];
int sz[MAXN];
int components = 0;

int find(int a){
    while(par[a] != a) a = par[a];
    return a;
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a==b) return false;

    if(sz[a] < sz[b]) swap(a, b);

    hist.push({b, par[b]});
    hist.push({a, sz[a]});
    hist.push({-1, components});

    par[b] = a;
    sz[a] += sz[b];
    components--;

    return true;
}

void rollback() {
    if(hist.empty()) return;

    components = hist.top().second;
    hist.pop();
    
    auto [a, sz_a] = hist.top(); hist.pop();
    auto [b, par_b] = hist.top(); hist.pop();

    sz[a] = sz_a;
    par[b] = par_b;
}

vector<int> tree[4*MAXM]; //indice dos edges em cada nó da arvore
map<pii, int> edgeId;
vector<pii> edge;
vector<int> rest [MAXM]; // em quais segundos o edge está fora

void update(int no, int i, int j, int l, int r, int edg){
    if(i > r || j < l) return;
    if(i >= l && j <= r) {
        tree[no].push_back(edg);
        return ;
    }

    int mid = (i+j)/2;
    update(2*no, i, mid, l, r, edg);
    update(2*no+1, mid+1, j, l, r, edg);
}

void solve(int no, int l, int r){
    int cont = 0;
    for(auto id: tree[no]){
        if(merge(edge[id].first, edge[id].second)){
            cont++;
        }
    }

    if(l == r){
        cout<<(components > 1 ? "Disconnected\n" : "Connected\n");
    }
    else{
        int mid = (l+r)/2;
        solve(2*no, l, mid);
        solve(2*no+1, mid+1, r);
    }
    while(cont--) rollback();
}

int main(){
    freopen("disconnected.in", "r", stdin);
    freopen("disconnected.out", "w", stdout);
    int n, m; cin>>n>>m;
    components = n;

    edge.resize(m+1);
    for(int i =1; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i<=m; i++){
        int a, b;   // a < b
        cin>>a>>b;
        if(a > b) swap(a, b);

        edge[i]= {a, b};
        edgeId[{a, b}] = i;
    }

    int q; cin>>q;
    for(int i =1; i<=q; i++){
        int k; cin>>k;

        while(k--){
            int a; cin>>a;
            rest[a].push_back(i);
        }
    }

    for(int i = 1; i<=m; i++){
        int l =1;
        for(auto r : rest[i]){
            if(r-1 >= l){
                update(1, 1, q, l, r-1, i);
            }
            l = r+1;
        }
        if(l <= q){
            update(1, 1, q, l, q, i);
        }
    }

    solve(1, 1, q);
    return 0;
}