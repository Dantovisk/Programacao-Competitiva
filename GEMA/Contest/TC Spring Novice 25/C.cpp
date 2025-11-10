#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m; 

void dfs(int u, int v, vector<vi> &vis, vector<vi>& g){
    vis[u][v] = 1;

    for(auto d: dir){
        int x = u + d[0];
        int y = v + d[1];

        if(!(x < n && x>= 0 && y < m && y >= 0)) continue;
        if(vis[x][y]) continue;
        if(g[x][y] > g[u][v]) continue;

        dfs(x, y, vis, g);
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m;

    vector<vi> v (n, vi(m));
    vector<vi> vis (n, vi(m, 0));

    vector<tuple<int,int,int>> p;

    rep(i, 0, n){
        rep(j, 0, m){
            cin>>v[i][j];
            p.push_back({v[i][j], i, j});
        }
    }
    sort(all(p)); reverse(all(p));

    int res = 0;
    for(auto [val, x, y] : p){
        if(!vis[x][y]){
            dfs(x, y, vis, v);

            res++;
        }
    }
    cout<<res<<"\n";
}