//CSES - Monsters (task 1194)

#include <bits/stdc++.h> 
#define MAXN 10000000

using namespace std;
 
int tempo [1010][1010]; //representa em quanto tempo o recinto pegara monstro
int resp [1010][1010];
vector <string> entradas (1010);
queue <pair<int,int>> monstro;
queue <pair<int,int>> q;
bool vis[1010][1010];
int n, m;
 
void bfs() {
    while (!monstro.empty()) {
        int x = monstro.front().first;
        int y = monstro.front().second;
        monstro.pop();

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!vis[nx][ny] && ny >= 0 && ny < m && nx >= 0 && nx < n) {
                vis[nx][ny] = true;
                tempo[nx][ny] = tempo[x][y] + 1;
                monstro.push({nx, ny});
            }
        }
    }
}

int findMin() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (y == 0 || y == m - 1 || x == 0 || x == n - 1) {
            return resp[x][y];
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!vis[nx][ny] && ny >= 0 && ny < m && nx >= 0 && nx < n && tempo[nx][ny] > resp[x][y] + 1 && entradas[nx][ny]!='#') {
                vis[nx][ny] = true;
                resp[nx][ny] = resp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}
 
int main(){ 
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin >> entradas[i];

        for(int k=0; k<m; k++){
            vis[i][k] = false;
            if(entradas[i][k] == 'M'){
                monstro.push(make_pair(i,k));
                vis[i][k] = true;
                tempo[i][k]=0;
            }
            else if(entradas[i][k] == '#'){
                vis[i][k] = true;
                tempo[i][k]=0;
            }
            else {
                tempo[i][k]= MAXN;
                if(entradas[i][k] == 'A'){
                    q.push(make_pair(i,k));
                }
            }
        }
    }

    bfs();
    memset(vis, 0, sizeof(vis));

    int min = findMin();
    if(min != -1){  //encontrou a resposta, falta construir o caminho
        cout<< min <<"\n";
    }
    else cout<<"NO\n";

    
    return 0;
} 