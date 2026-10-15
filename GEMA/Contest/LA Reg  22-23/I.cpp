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

const int maxn = 2e5+4;
const int inf = 1e9+3;

int g[110][110];
int vis[110][110];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int invx[10010], invy[10010];

void solve(){
    int n, m; 
    cin>>n>>m;
    
    rep(i, 0, n){
        rep(j, 0, m){
            cin>>g[i][j];
            invx[g[i][j]] = i;
            invy[g[i][j]] = j;
        }
    }

    int r = 1;
    rep(i, 0, n){
        rep(j, 0, m){
            memset(vis, 0, sizeof(vis));
            // cout<<"to no "<<i<<", "<<j<<"\n";

            int k = 1;
            int st = g[i][j];
            priority_queue<int, vi, greater<int>> q;
            q.push(g[i][j]);
            vis[i][j] = 1;

            while(!q.empty()){
                int u = q.top();
                q.pop();
                int x = invx[u];
                int y = invy[u];
                if(g[x][y] > st){
                    st = g[x][y];
                    k ++;
                }

                for(auto d: dir){
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx < 0 or nx >= n or ny < 0 or ny >= m){
                        continue;
                    }
                    if(vis[nx][ny]) continue;
                    if(g[nx][ny] < st) continue;

                    vis[nx][ny] = 1;
                    q.push(g[nx][ny]);
                }
            }
            // cout<<"k = "<<k<<"\n";
            r = max(r, k);
        }
    }

    cout<<r<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}