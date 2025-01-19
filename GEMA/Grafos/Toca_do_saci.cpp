#include <bits/stdc++.h>

using namespace std;

int readmap[1010][1010];
int dist[1010][1010];

int n, m, edx, edy;

queue <pair<int,int>> q;

int bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x==edx && y==edy) return dist[x][y];

        int dir [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto z: dir){
            int nx = x + z[0];
            int ny = y + z[1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && readmap[nx][ny]!=0){
                readmap[nx][ny] = 0;
                q.push({nx,ny});
                dist[nx][ny] = dist[x][y]+1;
            }
        }

    }
    return dist[edx][edy];
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>readmap[i][j];
            if(readmap[i][j]==2) q.push({i,j});
            else if(readmap[i][j]==3){
                edx = i;
                edy = j;
            }
        }
    }
    cout <<bfs() + 1;

    return 0;
}
