#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second

int n, m, l, r;

const int MAX = 1e5+7;

priority_queue<pii, vector<pii>, greater<pii>> pq;

vector<pii> adj[MAX];
ll dist[MAX];
ll inf = 1e11 + 69;

set<pair<int, int>> vis;

int dijkstra(){
    int cont = 0;

    dist[0] = 0;
    for(int i =1; i<n; i++) dist[i] = inf;

    pq.push({0,  0});

    while(!pq.empty()){
        auto [fds, u] = pq.top();
        pq.pop();

        for(auto[w, v]: adj[u]){
            if(dist[u]* 2 < r) {
                int a = u, b = v;
                if(a > b) swap(a, b);
                if(vis.find({a, b}) != vis.end()) continue;
                vis.insert({a, b});
                cont ++;
                // cout<<u<<" "<<v<<"\n";
            }
            if(dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
    return cont;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m>>l>>r;

    rep(i, 0, m){
        int a, b;
        ll w;
        cin>>a>>b>>w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    cout<<dijkstra()<<"\n";
}