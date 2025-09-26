#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define pb push_back
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int MAX = 3e5+69;

vector<pii> adj[MAX];
ll dist[MAX];
int n;
const ll inf = 1e12+69;

void dijkstra(int st = 1){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});

    fill(dist, dist+n+1, inf);
    dist[st] = 0;

    while(!pq.empty()){
        auto[w, u] = pq.top();
        pq.pop();

        if(dist[u] < w) continue;

        for(auto [w2, v]: adj[u]){
            if(dist[v] <= dist[u] + w2) continue;
            dist[v] = dist[u] + w2;
            pq.push({dist[v], v});
        }

    }   
}

ll dist2[MAX];
void dijkstra2(int st = n){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});

    fill(dist2, dist2+n+1, inf);
    dist2[st] = 0;

    while(!pq.empty()){
        auto[w, u] = pq.top();
        pq.pop();

        if(dist2[u] < w) continue;

        for(auto [w2, v]: adj[u]){
            
            if(dist2[v] <= dist2[u] + w2) continue;
            dist2[v] = dist2[u] + w2;
            pq.push({dist2[v], v});
        }

    }   
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int m,k; cin>> n >> m >> k;

    for(int i = 0; i< m; i++){
        int u,v, w; cin >> u >> v >> w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }

    dijkstra();
    dijkstra2();

    // id, value
    vector<pair<int,double>> postos;
    bool foi = false;
    for(int i = 0; i < k; i++) {
        int id; double val;
        cin>>id>>val;
        postos.push_back({id, val});
        if(val > 1.0 - 1e-9) foi = true;
    }

    if(!foi){
        cout<<"impossible\n";
        return 0;
    }
    
    vector<tuple<ll, double>> v;
    double chance = 1;
    for(auto [id, w]: postos){
        v.push_back({dist[id] + dist2[id], w});
    }
    sort(all(v));

    double total = 0;
    for(auto[w, c]: v){
        total += chance * w * c;
        chance *= (1.0 - c);

    }
    cout<<fixed<<setprecision(9);
    cout<<total<<"\n";
}


