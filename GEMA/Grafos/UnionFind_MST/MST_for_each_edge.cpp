#include <bits/stdc++.h>
#define int long long
#define tiii tuple<long long,long long,long long>
using namespace std;

vector<pair<int,int>> adj[200010];
vector<tiii> qry;
int ancestral[200010][21]; //indice, peso da aresta
int nivel[200010];
int maxWeight[200010][21];

priority_queue <tiii, vector<tiii>, greater <tiii>> pq; //peso da aresta, a, b
vector<pair<int,int>> mst[200010];
int setSize[200010];
int parent[200010];
int mstsize = 0;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(setSize[b]>setSize[a]) swap(a, b);

    setSize[a]+=setSize[b];
    parent[b] = a;
}


void dfs(int v, int p){
    for(auto x: mst[v]){
        int q = x.first, w = x.second;
        if(q == p) continue;
        nivel[q] = nivel[v] +1;
        maxWeight[q][0] = w;
        ancestral[q][0] = v;
        dfs(q, v);
    }
}

pair<int,int> lca(int a, int b){
    int v=0;
    if(nivel[b]>nivel[a]) swap(a,b);

    for (int i = 20; i>=0; i--){
        if(nivel[a] - (1<<i) >= nivel[b]){
            v = max(maxWeight[a][i], v);
            a = ancestral[a][i]; 
        }
    }

    if(a==b) return {a, v};

    for (int i = 20; i>=0; i--){
        if(ancestral[a][i] != -1 && ancestral[b][i] != -1  && ancestral[a][i] != ancestral[b][i]){
            v = max({v,maxWeight[a][i],maxWeight[b][i]});
            a = ancestral[a][i];
            b = ancestral[b][i];
        }

    }
    v=max({v, maxWeight[a][0], maxWeight[b][0]});

    return {ancestral[a][0], v};
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(ancestral, -1, sizeof(ancestral));
    memset(maxWeight, -1, sizeof(maxWeight));

    int n, m, w = 0; 
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        qry.push_back({a,b,c});

        pq.push({c, a, b});
    }

    //setup do kruskall
    for(int i=0; i<= n; i++){
        setSize[i] = 1;
        parent[i] = i;
    }

    //geração da mst com kruskall
    while(!pq.empty()){
        int a, b, c;
        tie(a, b, c) = pq.top();
        pq.pop();

        if(find(b) != find(c)){
            merge(b, c);
            mst[b].push_back({c, a});
            mst[c].push_back({b, a});
            w+= a;
        }
    }
    //agora temos uma MST, usaremos LCA para responder as queries
    dfs(1, -1);


    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            if(ancestral[j][i-1] == -1) continue;
            ancestral[j][i] = ancestral[ancestral[j][i-1]][i-1]; 
            maxWeight[j][i] = max(maxWeight[j][i-1], maxWeight[ancestral[j][i-1]][i-1]);
        }
    }

    for(auto x: qry){
        int a, b, c;
        tie(a, b, c) = x;

        int l, maxw;
        tie(l, maxw) = lca(a, b);
        cout<<w-maxw+c<<"\n";
    }

    return 0;
}