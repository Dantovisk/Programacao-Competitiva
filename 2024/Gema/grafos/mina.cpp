// Mina - OBI 2015 - Segunda Fase
// Exercício que busca o caminho mínimo em uma mina
// Utilizando o conceito de BFS 0-1

#include <bits/stdc++.h>  
using namespace std;

int bitmap[110][110];
int n;
deque <pair<int, int>> d;
int peso[110][110];
int vis[110][110];

int bfs01(){
    d.push_front({0,0});
    peso[0][0]= 0;
    vis[0][0]= 1;

    while(!d.empty()){
        int x = d.front().first;
        int y = d.front().second;
        d.pop_front();
        if(x==n-1 && y==n-1) return peso[x][y];

        int dir[4][2] ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto nd: dir){
            int nx = x + nd[0], ny= y + nd[1];
            if(nx>=0 && ny>=0 && nx< n && ny < n){
                if(!vis[nx][ny]){
                    if(bitmap[nx][ny] > 0){
                        d.push_back({nx,ny});
                    }else{
                        d.push_front({nx,ny});
                    }
                    vis[nx][ny] = 1;
                    peso[nx][ny] = peso[x][y] + bitmap[nx][ny];
                }
            }
        }
    }
    return peso[n-1][n-1];
}

int main() {

    cin>>n;

    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++){
            cin>>bitmap[i][k];
        }
    }

    cout<<bfs01()<<endl;    
    return 0;
}