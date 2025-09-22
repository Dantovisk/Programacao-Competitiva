#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 3e5+69;

vector<pii> adj[MAX];
int dist[MAX];
int n;
const int inf = 1e9+69;

void dijkstra(int st = 1){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});

    fill(dist, dist+n, inf);

    while(!pq.empty()){
        auto[w, u] = pq.top();
        pq.pop();

        if(dist[u] < w) continue;

        for(auto [w2, v]: adj[u]){
            
            if(dist[v] <= dist[u] + w2) continue;
            dist[v] = dist[u] + w2;

        }

    }   
}

int dist2[MAX];
void dijkstra2(int st = n){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});

    fill(dist2, dist2+n, inf);

    while(!pq.empty()){
        auto[w, u] = pq.top();
        pq.pop();

        if(dist2[u] < w) continue;

        for(auto [w2, v]: adj[u]){
            
            if(dist2[v] <= dist2[u] + w2) continue;
            dist2[v] = dist[u] + w2;

        }

    }   
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    int n,m,k; cin>> n >>m >>k;


    for(int i = 0; i< m; i++){
        int u,v, w; cin >> u >> v >> w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }

    vector<pii>postos(k);
    for(int i = 0; i < k; i++) cin>>postos[i].first >> postos[i].second;
    

    int f = 0;

    vector<pii> d;

    for(auto [i,p]: posts)
}


