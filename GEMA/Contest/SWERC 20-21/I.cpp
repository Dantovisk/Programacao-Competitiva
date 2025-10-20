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

#include <cstdint>
#include <cassert>

// returns random int in [0, hi), like Python's random.randrange
int randRange(int hi) {
	return rand() % hi;
}

int n, m;
const int MAX = 1e5+3;

vector<int> adj[MAX];


// vector<pair<int, int>> dp(MAX, make_pair(0, 0));
// vector<pair<int, int>> dp2(MAX, make_pair(0, 0));

// int cont = 0;
// int vis1[MAX], vis2[MAX];

// void dfs1(int u){
//     cont++;
//     dp[u] = {1, u};
//     vis1[u] = 1;

//     for(int v : adj[u]){
//         if(vis1[v]) continue;
//         dfs1(v);

//         dp[u] = max(dp[u], {dp[v].first + 1, dp[v].second});
//     }
// }  

// void dfs2(int u){
//     dp2[u] = {1, u};
//     vis2[u] = 1;

//     for(int v : adj[u]){
//         if(vis2[v]) continue;
//         dfs2(v);

//         dp2[u] = max(dp2[u], {dp2[v].first + 1, dp2[v].second});
//     }
// }

int cont = 0;
int dist1[MAX], dist2[MAX];

pair<int,int> best = {0, 0};
pair<int,int> best2 = {0, 0};

void bfs1(int st){
    best ={0,0};
    queue<int> q;

    memset(dist1, 0, sizeof(dist1));

    dist1[st] = 1;
    q.push(st);

    
    
    while(!q.empty()){
        auto u = q.front();
        q.pop();

        // cout<<"u: "<<u<<"\n";

        cont++;

        best = max(best, {dist1[u], u});

        for (int v : adj[u]){
            if(dist1[v]) continue;

            q.push(v);
            dist1[v] = dist1[u] + 1;
        }
    }
}

void bfs2(int st){
    queue<int> q;
    memset(dist2, 0, sizeof(dist2));
    dist2[st] = 1;

    q.push(st);
    best2 = {0, 0};
    
    while(!q.empty()){
        auto u = q.front();
        q.pop();

        best2 = max(best2, {dist2[u], u});

        for (int v : adj[u]){
            if(dist2[v]) continue;

            q.push(v);
            dist2[v] = dist2[u] + 1;
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin>>n>>m;
    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int bestDist = 0;

    for(int i =0; i< 40; i++){
        bfs1(randRange(n) + 1);

        if(cont < n){
            cout<<"-1\n";
            return 0;
        }
        bfs2(best.second);

        // cout<<"Dist entre "<<dp[1].second<<" "<<dp2[dp[1].second].second<<": ";
        // cout<<dp2[dp[1].second].first - 1<<"\n";

        int dist = best2.first -1;
        bestDist = max(dist, bestDist);
    }
        

    // cout<<dist<<"\n";

    int res = 0; 


    for(; (1 << res) < bestDist; res++);
    cout << res << "\n";
}