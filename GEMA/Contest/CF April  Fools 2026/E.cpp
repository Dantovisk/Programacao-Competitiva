#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int MAX = 1e5+7;
const int inf = 1e9+7;

// u, w
vector<pii> adj[200];
int dist[200];

void solve(){
    int n, m; 
    cin>>n>>m;

    rep(i,0, m){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    priority_queue <pii, vector<pii>, greater<pii>> pq;
    rep(i, 2, n+1) dist[i] =inf;

    pq.push({0, 1});

    while(!pq.empty()){
        auto [w1, u] = pq.top();
        pq.pop();
        if(w1 > dist[u]) continue;

        for(auto[v, w2] : adj[u]){
            if(dist[v] > dist[u] + w2){
                dist[v] = dist[u] + w2;
                pq.push({dist[v], v});
            }
        }
    }

    rep(i, 2, n+1) cout<<(dist[i] == inf? -1: dist[i])<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}