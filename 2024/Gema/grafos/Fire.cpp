#include <bits/stdc++.h> //Fire - Kattis
#define MAXN 10000000

using namespace std;
 
int tempo [1010][1010]; //representa em quanto tempo o recinto pegara fogo
int resp [1010][1010];
vector <string> entradas (1010);
queue <pair<int,int>> fogo;
queue <pair<int,int>> q;
bool vis[1010][1010];
int n, m;
 
void bfs() {
    while (!fogo.empty()) {
        int x = fogo.front().first;
        int y = fogo.front().second;
        fogo.pop();

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!vis[nx][ny] && ny >= 0 && ny < n && nx >= 0 && nx < m) {
                vis[nx][ny] = true;
                tempo[nx][ny] = tempo[x][y] + 1;
                fogo.push({nx, ny});
            }
        }
    }
}

int findMin() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (y == 0 || y == n - 1 || x == 0 || x == m - 1) {
            return resp[x][y];
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!vis[nx][ny] && ny >= 0 && ny < n && nx >= 0 && nx < m && tempo[nx][ny] > resp[x][y] + 1 && entradas[nx][ny]!='#') {
                vis[nx][ny] = true;
                resp[nx][ny] = resp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}
 
int main(){
    int t;
    cin >> t;
 
    while(t--){
        cin>>n>>m;
 
        while(!fogo.empty()) fogo.pop();
        while(!q.empty()) q.pop();
        memset(vis, 0, sizeof(vis));
        memset(resp, 0, sizeof(resp));
 
        for(int i=0; i<m; i++){
            cin >> entradas[i];

            for(int k=0; k<n; k++){
                vis[i][k] = false;
                if(entradas[i][k] == '*'){
                    fogo.push(make_pair(i,k));
                    vis[i][k] = true;
                    tempo[i][k]=0;
                }
                else if(entradas[i][k] == '#'){
                    vis[i][k] = true;
                    tempo[i][k]=0;
                }
                else {
                    tempo[i][k]= MAXN;
                    if(entradas[i][k] == '@'){
                        q.push(make_pair(i,k));
                    }
                }
            }
        }
 
        bfs();
        memset(vis, 0, sizeof(vis));

        int min = findMin();
        if(min != -1) cout<<min+1<<"\n";
        else cout<<"IMPOSSIBLE\n";
 
    }
    
    return 0;
} 