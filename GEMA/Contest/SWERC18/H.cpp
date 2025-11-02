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

const int MAX = 1e5+7;

vector<pii> adj[MAX];
int dist[MAX][3];
const int inf = 1e9+7;
int n, m;

void dijkstra(int st){
    for(int i =0; i<=n; i++) dist[i][st] = inf;
    dist[st][st] = 0;

    priority_queue <pii, vector<pii>, greater<pii>> pq;

    pq.push({0, st});

    while(!pq.empty()){
        auto [c, u] = pq.top();
        pq.pop();

        if(dist[u][st] < c) continue;

        for(auto [w, v] : adj[u]){
            if(dist[u][st] + w >= dist[v][st]) continue;

            dist[v][st] = dist[u][st] + w;
            pq.push({dist[v][st], v});
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

        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    rep(i, 0, 3) dijkstra(i);


    int resp = n;

    vector<tuple<int,int,int>> pts;
    pts.push_back({0, 0, 0});

    rep(i, 0, n){
        pts.push_back({dist[i][0], dist[i][1], dist[i][2]});
    }
    sort(all(pts));

    set <pair<int, int>> s;

    s.insert({inf, -1});
    s.insert({-1, inf});

    vi mog(n+1);

    // cout<<"TESTE\n";
    rep(i, 1, n+1){
        //lida com duplicatas
        if(pts[i] == pts[i-1]){
            mog[i] = mog[i-1];
            resp += mog[i];
            continue;
        }

        auto [x, y, z] = pts[i];
        // cout<<x<<" "<<y<<" "<<z<<"\n";

        auto r = s.lower_bound({y, inf});
        auto l = r; l--;

        auto [ry, rz] = *r;
        auto [ly, lz] = *l;

        if(z >= lz){
            resp--;
            // cout<<"MOGGADO\n";
            mog[i] = -1;
            continue;
        }
        
        mog[i] = 0;

        auto ptr = s.lower_bound({y, z});

        //meu atual tem y igual mas z menor
        if(ptr->first == y){
            ptr = s.erase(ptr);
        }
        //remove os caras com y e maiores que o meu atual
        while(ptr->second >= z){
            ptr = s.erase(ptr);
        }
        
        s.insert({y, z});
    }

    cout<<resp<<"\n";

}