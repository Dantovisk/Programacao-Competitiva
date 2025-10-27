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

int n, m, k;
vector<pii> slab;

int xa, ya, xb, yb;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ongrid(int x, int y){
    return (x >= xa && x <= xb && y >= ya && y <= yb);
}

int dfs(int x, int y, vector<vector<int>>& grid){
    // cout<<"visitando: "<<x<<" "<<y<<"\n";
    int res = 0;
    
    if(grid[x][y] == 1 && ongrid(x, y)) {
        res--;
    }

    if(grid[x][y] == 0 && !ongrid(x, y)) res++;
    grid[x][y] = 3;
    
    for(auto d: dir){
        int nx = d[0] + x, ny = d[1] + y;
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(grid[nx][ny] >= 2) continue;
        
        res += dfs(nx, ny, grid);
    }
    // cout<<"res["<<x<<"]["<<y<<"] = "<<res<<"\n";
    return res;
}

bool solve(int v){
    // cout<<"V = "<<v<<"\n";
    vector<vector<int>> grid(n, vi(m, 0));

    for(int i = 1; i<=v; i++){
        grid[slab[i].ff][slab[i].ss] = 1;
    }

    for(int i = v+1; i<=k; i++){
        grid[slab[i].ff][slab[i].ss] = 2;
    }

    for(int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            if(grid[i][j] == 1){
                if(dfs(i, j, grid) < 0) {
                    return false;
                    // cout<<"Ai sim\n";
                }
            }
            else if(grid[i][j] == 2 && ongrid(i, j)) {
                return false;
                // cout<<"Ai nao\n";
            }
        }
    }
    return true;
}

const int inf = 1e8+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m>>k;
    slab.resize(k+1);

    for(int i = 1; i<=k; i++){
        int a, b;
        cin>>a>>b;
        slab[i] = {a-1,b-1};
    }

    cin>>xa>>ya>>xb>>yb;
    xa--; ya--; xb--; yb--;
    int l = 0, r =k+1;
    int mid;
    int mindone = inf;
    while(l<r){
        mid = (l+r)/2;

        if(solve(mid)) {
            r = mid;
            mindone = min(mindone, mid);
        }
        else l = mid+1;
    }
    cout<<(mindone == inf? -1 : mindone)<<"\n";
}