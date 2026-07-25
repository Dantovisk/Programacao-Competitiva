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

int grid[1010][1010];
int dist[1010][1010];
vector<pii> freq[1000010];
int visfreq[1000010];

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m; 
    cin>>n>>m;

    memset(dist, -1, sizeof(dist));

    rep(i, 0, n){
        rep(j, 0, m){
            cin>>grid[i][j];
            freq[grid[i][j]].push_back({i, j});
        }
    }
    
    queue<pii> q;

    visfreq[grid[0][0]] = 1;

    for(auto[u, v] : freq[grid[0][0]]){
        q.push({u, v});
        dist[u][v] = 0;
    }

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(auto d: dir){
            int nx = x+d[0];
            int ny = y+d[1];
            if(nx >= n or ny >= m or nx < 0 or ny < 0) continue;

            if(visfreq[grid[nx][ny]] == 0){
                visfreq[grid[nx][ny]] = 1;
                for(auto [u, v]: freq[grid[nx][ny]]){
                    if(dist[u][v] != -1) continue;
                    dist[u][v] = dist[x][y]+1;
                    q.push({u, v});
                }
            }
            
            else if(dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx, ny});
            }
        }

    }

    cout<<dist[n-1][m-1]<<"\n";

}