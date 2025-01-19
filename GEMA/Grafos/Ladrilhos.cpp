// Maratona de Programação da SBC 2016 - Ladrilhos

#include <bits/stdc++.h>  
using namespace std;

int n , m, minArea = 5000000;
int ladrilhos[210][210];
int vis[210][210];

int dfs(int x, int y){

    int cont = 1;

    int dir[4][2] ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(auto nd: dir){
        int nx = x + nd[0], ny= y + nd[1];
        if(nx>=0 && ny>=0 && nx< n && ny < m){
            if(!vis[nx][ny] && ladrilhos[x][y]==ladrilhos[nx][ny]){
                vis[nx][ny] = 1;
                cont += dfs(nx, ny);
            }
        }
    }
    return cont;

}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0 ; j<m; j++){
            cin>>ladrilhos[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0 ; j<m; j++){
            if(!vis[i][j]){
                vis[i][j] = 1;
                minArea = min(minArea, dfs(i, j));
            }
        }
    }
    
    cout<<minArea;
    return 0;
}