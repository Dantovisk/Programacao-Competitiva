#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+4;
const int B = 1e3+1;

//R, L U, D
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int adj[MAX][MAX][4];
int vis[MAX][MAX];

int bfs(int st, int st2){
    queue <pair<int, int>> q;
    int resp =  0;

    vis[st][st2] = 1;

    q.push({st, st2});
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop(); 

        resp++;

        for(int i =0; i<4; i++){
            if(adj[x][y][i] == 0) continue;
            int nx = x+dir[i][0], ny = y +dir[i][1];

            if(nx < 0 || ny < 0 || nx >= B || ny >= B) continue;
            if(vis[nx][ny]) continue;
            
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    
    return resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    int x, y;
    cin>>x>>y;

    for(int i =0; i<=B; i++)
        for(int j =0; j<=B; j++)
            for(int k =0; k<=B; k++) adj[i][j][k] = 1;

    for(int i =0; i<n; i++){
        int nx, ny;
        cin>>nx>>ny;

        for(int i = x; i<nx; i++){
            adj[i][y][3] = 0;
            adj[i][y-1][2] = 0;
        }

        for(int i = x; i > nx; i--){
            adj[i-1][y][3] = 0;
            adj[i-1][y-1][2] = 0;
        }

        for(int i = y; i<ny; i++){
            adj[x][i][1] = 0;
            adj[x-1][i][0] = 0;
        }

        for(int i = y; i > ny; i--){
            adj[x][i-1][1] = 0;
            adj[x-1][i-1][0] = 0;
        }

        x = nx;
        y = ny;
    }

    bfs(0, 0);

    int resp = 1;

    for(int i =0; i<B; i++)
        for(int j =0; j<B; j++)
            if(!vis[i][j]) resp = max(resp, bfs(i, j));

    cout<<resp<<"\n";

    return 0;
}