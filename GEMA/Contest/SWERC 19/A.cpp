#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define tii tuple<int,int,int>

const int MAX = 1e4+7;
const int inf = 1e9+7;

int tabela[110][110];
int n; 
int carro, maxdist; 

//custo, distancia, destino
vector<tii> adj[MAX];

int cost[MAX][110];

int dist(pii a, pii b){
    auto [xa, ya] = a;
    auto [xb, yb] = b;

    return tabela[abs(xa-xb)][abs(ya-yb)];
}

int dijkstra(int st = 0){
    // custo acumulado
    priority_queue <tii, vector<tii>, greater<tii>> pq;

    for(int i = 0; i<=n+1; i++){
        rep(j, 0, 102){
            cost[i][j] = inf;
        }
    }

    cost[0][0] = 0;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        auto [ct, dt, u] = pq.top();
        pq.pop();

        if(ct > cost[u][dt]) continue;

        for(auto [c, d, v]: adj[u]){
            int nd = dt + d;
            if(nd > maxdist) continue;
            if(cost[v][nd] <= cost[u][dt] + c) continue;

            cost[v][nd] = cost[u][dt] + c;
            pq.push({cost[v][nd], nd, v});
        }
    }

    int best = inf;
    rep(j, 0, maxdist+1){
        // cout<<j<<": "<<cost[1][j]<<"\n";
        best = min(best, cost[1][j]);
    }
    return (best >= inf? -1 : best);
}



vector<pii> fakeadj[MAX];

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    rep(i, 0, 105){
        rep(j, 0, 105){
            tabela[i][j] = ceil(sqrt(i*i+j*j));
        }
    }


    vector<pii> coords;
    
    //0 inicio, 1 fim
    rep(i, 0, 2){
        int a, b;
        cin>>a>>b;
        coords.push_back({a, b});
    }
    
    cin>>maxdist>>carro;
    
    int t; cin>>t;


    vi transp(t);
    rep(i, 0, t) cin>>transp[i];

    cin>>n;

    for(int i =2; i<=n+1; i++){
        int a, b;
        cin>>a>>b;
        coords.push_back({a, b});

        int k; cin>>k;
        for(int j=0; j<k; j++){
            int u, tran;
            cin>>u>>tran;
            u+=2;

            fakeadj[i].push_back({u, tran-1});
        }
    }

    for(int i =0; i<=n+1; i++){
        auto[a, b] = coords[i];

        for(auto [j, k]: fakeadj[i]){
            int ds = dist(coords[i], coords[j]);
            // cout<<"i, j = "<<i<<" "<<j<<"\n";
            // cout<<"ds = "<<ds<<"\n";

            adj[i].push_back({transp[k]*ds, ds, j});
            adj[j].push_back({transp[k]*ds, ds, i});
        }
    }

    rep(i, 0, 2){
        for(int j=0; j<= n+1; j++){
            if(j==i) continue;
            int ds = dist(coords[i], coords[j]);
            // cout<<"i, j = "<<i<<" "<<j<<"\n";
            // cout<<"ds de carro = "<<ds<<"\n";

            adj[i].push_back({carro*ds, ds, j});
            adj[j].push_back({carro*ds, ds, i});
        }
    }
    cout<<dijkstra()<<"\n";

    return 0;
}