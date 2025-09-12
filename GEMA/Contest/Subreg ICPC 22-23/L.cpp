#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5+ 69;

vi adj[MAX];
int par[MAX];

ll sum[MAX]; // A resposta pra cada vértice (numero de caminhos)
ll total[MAX]; // total[i] quantidade de vezes que a cor i aparece no grafo
int c[MAX]; //cor de cada vertice

map <int, int> colors[MAX]; //quais cores apareceram na subarvore
map<pii, int> resp; //mantem a resposta da aresta

void dfs(int u){
    //insere cor[u] no map
    colors[u][c[u]]++;
    sum[u] = (total[c[u]] - 1);

    for(auto v: adj[u]){
        if(v == par[u]) continue;
        par[v] = u;
        dfs(v);

        if(sz(colors[u]) < sz(colors[v])) {
            swap(colors[u], colors[v]);
            swap(sum[u], sum[v]);
        }

        for(auto [cor, quant]: colors[v]){
            ll x = (colors[u].find(cor) != colors[u].end() ? colors[u][cor] : 0);
            
            // remove o valor antigo
            sum[u] -= x * (total[cor] - x);

            // arruma a resposta de acordo com a nova quantidade de cores
            colors[u][cor] += quant;
            x += quant;
            sum[u] += x * (total[cor] - x);
        }
    }
    resp[{u, par[u]}] = sum[u];

    // cout<<"u: "<<u<<" - colors: "<<colors[u].size()<<" - res: "<<sum[u]<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
   
    int n;
    cin>>n;
    
    for(int i = 1; i<=n; i++){
        cin>>c[i];
        total[c[i]]++;
    }
    vector<pii> q;

    for(int i = 1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        q.push_back({a, b});
    }

    dfs(1);

    for(auto [a, b]: q){
        ll r = 0;
        if(resp.find({a, b}) != resp.end()) r = resp[{a, b}];
        else r = resp[{b, a}];

        cout<<r<<" ";
    }
}