#include <bits/stdc++.h> // Codeforces - Connect and Disconnect
using namespace std;     // Conectividade dinâmica
#define MAXN 300010      //incompleto

stack <pair<int,int>> hist;
int par[MAXN];
int sz[MAXN];
int components = 0;

map<pair<int,int>, int> edges;
vector<pair<int,int>> edgnum;

int tin [MAXN], tout[MAXN];
int query[MAXN];

vector<int> tree[4*MAXN]; //indice dos edges

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

void updTree(int no, int i, int j, int l, int r, int edg){
    if(i > r || j < l) return;

    //cout<<"no: "<<no<<", i: "<<i<<", j: "<<j<<"\n";

    if(i>=l && j <=r){
        tree[no].push_back(edg);
        return;
    }

    int mid = (i+j)/2;
    updTree(no*2, i, mid, l, r, edg);
    updTree(no*2+1, mid+1, j, l, r, edg);
}

void dfs(int u, int l, int r){
    int cont = 0;

    for(auto id: tree[u]){
        auto [x, y] = edgnum[id];
        if(merge(x, y)) {cont++; cout<<"juntando "<<x<<" e "<<y<<"\n";}
    }

    if(r == l){
        if(query[l]){
            cout<<components<<"\n";
            for(int i =1; i<=5; i++){
                cout<<"Pai de "<<i<<": "<<par[i]<<"\n";
            }
        }
        cout<<"Usaremos "<<cont<<" rollbacks\n";
        while(cont--) rollback();
        return;
    }

    int mid = (l+r)/2;
    dfs(u*2, l, mid);
    dfs(u*2+1, mid+1, r);

    while(cont--) rollback();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    components = n;
    int idedg = 0;
    int timer = 0;

    edgnum.push_back({-1, -1});

    for(int i =0; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }

    for(int i=0;i<m; i++){
        char a; cin>>a;
        int b, c;

        if(a == '?'){
            if(timer == 0){
                cout<<components<<"\n";
                timer++;
            }
            else{
                query[timer] = 1;
                timer++;
            }
            continue;
        }
        cin>>b>>c;
        
        if(a=='+'){
            tin[idedg] = timer;
            edges[{min(b, c), max(b,c)}] = ++idedg;
            edgnum.push_back({min(b, c), max(b,c)});
            timer++;
        }
        else{
            int id = edges[{min(b, c), max(b,c)}];
            tout[id] = timer;
        }

    }

    for(int i =0; i<=idedg; i++){
        if(tout[i] == 0) tout[i] = timer-1;
    }

    for(int i =1; i<= idedg; i++){
        updTree(1, 1, timer, tin[i], tout[i],  i);
        //cout<<"foi "<<i<<"\n";
    }
    

    //cout<<"ate aq foi";
    dfs(1, 1, timer);
    
    return 0;
}