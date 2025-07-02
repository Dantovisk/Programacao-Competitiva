#include <bits/stdc++.h>
const int inf = 1e7;

using namespace std;

int k;
string grid[1010];
set <int> linha[1010];
set <int> col[1010];
int dist[1010][1010];
int dir[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};

bool bfs(int x, int y){
    
    for(auto [dx, dy]: dir){
        for(int i = 1; i<=k; i++){
            if(grid[x+ i*dx][y + i*dy] == '#') break;
            if(dist[x+ i*dx][y + i*dy] < dist[x][y]) continue;
        
        }
    }
    
    return true;
}

int main(){
    int n, m;
    cin>>n>>m>>k;

    for(int i =1; i<=n; i++){
        cin>>grid[i];
        grid[i] = " " + grid[i];
        for(int j =1; j<=n; j++){
            dist[i][j] = inf;
        }
    }
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    dist[a][b] = 0;
    bfs(a, b);
}