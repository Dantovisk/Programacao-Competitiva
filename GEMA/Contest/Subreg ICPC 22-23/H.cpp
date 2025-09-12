#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e4 + 69;
// Kosaraju
//
// O(n + m)

int n, m;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido

int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) scc(u, u);
	}
}

int vis2[MAX];
vector<int> dag;
vector<int> g2[MAX]; // grafo invertido
vector<int> g2i[MAX]; // grafo invertido
int grau[MAX];

void dfs2(int u){
    vis2[u] = 1;
    dag.push_back(u);

    for(auto v: g2[u]){
        if(vis2[v]) continue;
        dfs2(v);
    }

    for(auto v: g2i[u]){
        if(vis2[v]) continue;
        dfs2(v);
    }
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    cin>>n>>m;
    n++;

    for(int i =0; i<m; i++){
        int a, b;
        cin>>a>>b;

        g[a].push_back(b);
        gi[b].push_back(a);
    }

    kosaraju();

    int n2 = 1;

    set<int> fds;

     for(int i =1; i<n; i++){
        fds.insert(comp[i]);
    }

    map <int, int> id;
    int fdsss = 1; 
    for(auto x: fds) id[x] = fdsss++;
    
    for(int i =1; i<n; i++){
        // cout<<"comp "<<i<<" "<<id[comp[i]]<<"\n";
        for(auto x: g[i]){
            if(id[comp[i]] == id[comp[x]]) continue;
            g2[id[comp[i]]].push_back(id[comp[x]]);
            g2i[id[comp[x]]].push_back(id[comp[i]]);
        }
        fds.insert(comp[i]);
    }

    n2 = fds.size();
    // cout<<"n2: "<<n2<<"\n";

    if(n2 == 1){
        cout<<"0\n";
        return 0;
    }

    int resp = 0;

    int dags = 0;

    int folhas = 0, raizes = 0;
    for(int i =1; i<= n2; i++){
        if(vis2[i]) continue;
        dfs2(i);
        dags++;
        if(dag.size() == 1){
            folhas++;
            raizes++;
            dag.clear();
            continue;
        }

        for(auto u: dag){
            for(auto v: g2[u]){
                grau[v]++;
            }
            if(g2[u].size() == 0) folhas++;
        }
        for(auto u: dag) if (grau[u] == 0) raizes++;

        resp += max(folhas, raizes);

        dag.clear();
    }
    //cout<<"resp, dags: "<<resp<<" "<<dags<<"\n";
    int u =  max(folhas, raizes);
    cout<<u<<"\n";



}