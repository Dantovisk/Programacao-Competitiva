#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef vector<int> vi;
const int MAXN = 2e5+7;
const int inf = 1e9+7;

int v[MAXN];
ll psum[3*MAXN];
vector<string> g;
int n, m; 

int bfs(){
    queue<tii> q;
    queue<pii> buff;
    vector<vi> vis(n, vi(m, 0));

    int temp = 0;

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(g[i][j] == '#'){
                q.push({i, j, 0});
                vis[i][j] = 1;
            }
        }
    }
    int dir[4][2] ={{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    while(!q.empty()){
        auto [x, y, t] = q.front();
        q.pop();

        if(t>temp){
            temp = t;
            while(!buff.empty()){
                auto [i, j] = buff.front();
                buff.pop();
                vis[i][j]++;
            }
        }

        if(vis[x][y] == 1) g[x][y] = '#';
        if(g[x][y] != '#') continue;

        for(auto d: dir){
            int nx = x+d[0], ny = y+d[1];
            if(nx<0 || ny<0 || nx>=n || ny >=m)continue;
            if(!vis[nx][ny]) {
                q.push({nx, ny, t+1});
                vis[nx][ny] ++;
            }
            else buff.push({nx, ny});
        }
    }

    int cont = 0;

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(g[i][j] == '#'){
                cont++;
            }
        }
    }
    return cont;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m;

    for(int i =0; i<n; i++){
        string a; cin>>a;
        g.push_back(a);
    }
    cout<<bfs()<<"\n";

    // for(auto s: g)cout<<s<<"\n";
    

}