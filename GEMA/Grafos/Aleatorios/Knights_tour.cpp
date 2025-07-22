#include <bits/stdc++.h> // CSES - Knight's Tour
#define pii pair<int,int> //Usando a regra de Warnsdorf
using namespace std;

int dir[8][2] = {{1, 2},{1, -2},{2, 1},{2, -1},{-1, 2},{-1, -2},{-2, 1},{-2, -1}};

int cont(vector<vector<int>>& vis, int x, int y){
    int res = 0;
    for(auto d: dir){
        int nx = x + d[0], ny = y + d[1];

        if(nx < 0 || ny <  0 || nx >7 || ny > 7) continue;
        if(vis[nx][ny]) continue;
        res++;
    } 
    return res;
}

bool dfs(vector<vector<int>>& vis, int x, int y, int temp){
    vis[x][y] = temp;

    if(temp == 64){
        for(auto i: vis){
            for(auto j: i) cout<<j<<" ";
            cout<<"\n";
        }
        return true;
    }
    priority_queue <pii, vector<pii>, greater<pii>> pq; //quant moves, id (0-63)
    for(auto d: dir){
        int nx = x + d[0], ny = y + d[1];
        if(nx < 0 || ny <  0 || nx >7 || ny > 7) continue;
        if(vis[nx][ny]) continue;

        int u = cont (vis, nx, ny);
        pq.push({u, nx*8 + ny});
    } 

    while(!pq.empty()){
        auto [w, id] = pq.top();
        pq.pop();
        if(dfs(vis, id/8, id%8, temp+1)) return true;
    }

    vis[x][y] = 0;
    return false;
}

int main() {
    int x, y;
    cin>>x>>y;
    vector<vector<int>> v(8, vector<int>(8, 0));
    dfs(v, y-1, x-1, 1);

    return 0;
}

