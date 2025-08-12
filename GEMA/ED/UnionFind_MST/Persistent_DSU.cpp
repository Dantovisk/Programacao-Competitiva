#include <bits/stdc++.h> // Library Checker
using namespace std;
#define MAXN 200010

stack <pair<int,int>> hist;
int par[MAXN];
int sz[MAXN];
int components = 0;


vector<tuple<int,int, int>> adj[MAXN]; //Gdst, u, v

//indice do grafo, u, v
vector <tuple<int,int,int>> query;
vector <pair<int,int>> quest[MAXN];
map <tuple<int,int,int>, int> resp;

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

void dfs(int u){
    for(auto c : quest[u]){
        auto [x, y] = c;

        resp[{u, x, y}] = (find(x) == find(y))? 1 : 0;
    }

    for(auto x : adj[u]){
        auto[v, a, b] = x;
        bool k = merge(a, b);

        dfs(v);

        if(k) rollback();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    components = n;

    for(int i =0; i<n; i++){
        par[i] = i;
        sz[i] = 1;
    }

    for(int i=0;i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        if(a==0){
            adj[b+1].push_back({i+1, c, d});
        }
        else{
            query.push_back({b+1, c, d});
            quest[b+1].push_back({c, d});
        }

    }

    dfs(0);

    for(auto x: query){
        cout<<resp[x]<<"\n";
    }

    return 0;
}