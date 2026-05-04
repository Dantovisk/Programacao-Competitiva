#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef vector<int> vi;
#define pb push_back

const ll inf = 1e15+2;
const int MAX = 2e3+5;
const double eps = 1e-7;

//dest, peso
vector<pii> adj[MAX];
int n, m;

set<int> foi;

ll dist2[MAX][MAX];

void dijkstra2(){
    rep(i, 0, n+1) 
        rep(j, 0, n+1)
            dist2[i][j] = inf;
    
    dist2[0][1] = 0;

    //qtd arestas, peso do caminho, vertice
    priority_queue <tii, vector<tii>, greater<tii>> pq;
    pq.push({0, 0, 1});
    while(!pq.empty()){
        auto [len, w1, u] = pq.top();
        pq.pop();

        // cout<<"vertice: "<<u<<", len = "<<len<<"\n";
        if(dist2[len][u] < w1) continue;
        if(len >= n) continue;
        // cout<<"FOI!!!!\n";

        for(auto [v, w] : adj[u]){
            if(dist2[len][u] + w >= dist2[len+1][v]) continue;
            dist2[len+1][v] = dist2[len][u] + w;
            pq.push({len+1, dist2[len+1][v], v});
        }
    }
}

int vis2[MAX];
void dfs2(int u, int len){
    foi.insert(u);
    vis2[u] = 1;
    for(auto [v, w]: adj[u]){
        if(vis2[v]) continue;
        if(dist2[len-1][v] == dist2[len][u] - w){
            dfs2(v, len-1);
        }
    }
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m;

    rep(i, 0, m){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    dijkstra2();
    ll last = inf;

    //{a, b} tq f(x) = ax + b
    vector<pair<ll, ll>> lines;

    for(int i = 1; i<= n; i++){
        if(dist2[i][n] >= inf) continue;

        // cout<<"Adicionando:";
        // cout<<dist2[i][n]<<" com tam "<<i<<"\n";

        lines.emplace_back(i, dist2[i][n]);
    }

    rep(i, 0, lines.size()){
        auto [a, b] = lines[i];

        double l = 0, r = inf;

        int da = 1;

        rep(j, 0, lines.size()){
            if(i == j) continue;
            auto [a2, b2] = lines[j];
            
            if(a2 == a){
                if(b > b2){
                    da = 0;
                    break;
                }
            }else{
                double inter = b2-b;
                inter /= (a-a2);
                if(a2 > a){
                    l = max(inter, l);
                }else{
                    r = min(inter, r);
                }
            }
        }


        if(l-r > eps) da = 0;

        if(!da) continue;
        ll dijk = b;
        ll ds = a;
        // cout<<"Bora visitar!\n";
        // cout<<dijk<<" com tam "<<ds<<"\n";
        // cout<<"limites: "<<l<<" "<<r<<"\n";

        rep(j, 0, n+1) vis2[j] = 0;
        dfs2(n, ds);
    }

    // rep(i, 1, n){
    //     cout<<i<<": "<<vis[i]<<", "<<vis2[i]<<"\n";
    //     if(!vis[i] and !vis2[i]) res.pb(i);
    // }
    
    cout<< n - foi.size()<<"\n";
    for(int i = 1; i<= n; i++){
        if(foi.count(i) == 0) cout<<i<<" "; 
    }
    cout<<"\n";
}