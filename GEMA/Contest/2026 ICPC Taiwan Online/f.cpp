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

const int maxn = 1e5+4;
const int inf = 1e9+3;
typedef tuple<int, int, int> tii;

// v, t, h
vector<tii> adj[maxn];
int dist[maxn];

void solve(){
    int n, m; 
    cin>>n>>m;

    rep(i, 0, m){
        int u, v, t, h;
        cin>>u>>v>>t>>h;

        adj[u].push_back({v, t, h});
        adj[v].push_back({u, t, h});
    }

    //resto, adj
    priority_queue <pii> pq;
    memset(dist, -1, sizeof(dist));
    dist[1] = inf;

    pq.push({inf, 1});
    while(!pq.empty()){
        auto [w1, u] = pq.top();
        pq.pop();
        // cout<<"to em "<<u<<" com resto = "<<w1<<"\n";
        if(dist[u] > w1){
            continue;
        }

        for(auto [v, t, h] : adj[u]){
            int resto = min(h - t, w1- t);
            if(dist[v] < resto){
                dist[v] = resto;
                pq.push({resto, v});
            }
        }
    }

    rep(i, 1, n+1){
        cout<<(dist[i]>=0);
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}