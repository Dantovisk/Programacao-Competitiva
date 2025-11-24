#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, int> pii;
typedef vector<int> vi;

const int maxn = 5e5 + 5;

int n, m, k, id;

//dist, local
vector <pii> adj[2*maxn];
vector <pii> adjT[2*maxn];

int qtdInf[2*maxn];

ll dist[2*maxn];
const ll inf = 2e15+7;

void dijkstra(){
    rep(i, 0, id) dist[i] = inf;

    dist[n-1] = 0;

    priority_queue <pii, vector<pii>, greater<pii>> pq;

    pq.push({0, n-1});
    while(!pq.empty()){
        auto[wu, u] = pq.top();
        pq.pop();

        if(u < n && dist[u] > wu) continue;

        ll mx = 0;
        if(u >= n){
            for(auto[w, v]: adj[u])
                mx = max(mx, dist[v] + w);
            dist[u] = mx;
        }

        for(auto [w, v] : adjT[u]){
            if(u < n){
                // É vértice de min.
                qtdInf[v]--;

                if(qtdInf[v] <= 0){
                    pq.push({0, v});
                }
            }
            else{
                // É vértice de MAX
                if(dist[u] >= dist[v]) continue;
                dist[v] = dist[u];
                pq.push({dist[v], v});
            }
        }


    }



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m>>k;

    id = n;
    map <pair<int,int>, vector<pair<int,int>>> mp;

    for(int i =0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        a--; b--;

        int t; cin>>t;
        
        // src, cor
        for(int j = 0; j<t; j++){
            int c; cin>>c;

            mp[{a, c}].push_back({w, b});
        }
    } 

    for(auto [par, ls] : mp){
        auto [a, c] = par;

        adj[a].push_back({0, id});
        adjT[id].push_back({0, a});

        qtdInf[id] = ls.size();
        for(auto [w, v]: ls){
            adj[id].push_back({w, v});
            adjT[v].push_back({w, id});
        }
        id++;
    }

    dijkstra();

    
    ll resp = dist[0];

    if(resp == inf) cout<<"impossible\n";
    else cout<<resp<<"\n";
}