// CSES - Labirynth
// Exercicio para encontrar o caminho em um labirinto
// Solução pode ser feita utilizando DFS

#include <bits/stdc++.h>  
using namespace std;

vector <string> lab(1010);
int n, m;
queue <pair<int, int>> q;
char parDir[1010][1010];
pair <int,int> par[1010][1010];
int vis[1010][1010];
int stx, sty, endx, endy;

bool bfs(){
    q.push({stx, sty});
    parDir[stx][sty] = 'X';
    par[stx][sty] = {-1,-1};
    vis[stx][sty] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==endx && y==endy) { //Achou!!!
            return true;
        }

        int dir[4][2] ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto nd: dir){
            int nx = x + nd[0], ny= y + nd[1];
            if(nx>=0 && ny>=0 && nx< n && ny < m){
                if(!vis[nx][ny] && lab[nx][ny] != '#'){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;

                    par[nx][ny] = {x, y};

                    if(x - nx == -1) parDir [nx][ny] = 'D';
                    if(x - nx == 1) parDir [nx][ny] = 'U';
                    if(y - ny == -1) parDir [nx][ny] = 'R';
                    if(y - ny == 1) parDir [nx][ny] = 'L';
                }
            }
        }
    }
    return false;
}

int main() {

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>lab[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(lab[i][j]=='A'){
                stx = i;
                sty = j;
            }else if(lab[i][j]=='B'){
                endx = i;
                endy = j;
            }
        }
    }


    if(bfs())
    {
        cout<<"YES\n"; //falta construir o caminho até a resposta
        string resp = "";
        int g = endx, h = endy;
        while (parDir[g][h] != 'X'){
            resp += parDir[g][h];
            int t1 = par[g][h].first, t2 = par[g][h].second;
            g = t1; h = t2;
        }
        reverse(resp.begin(), resp.end());
        cout<<resp.size()<<endl<<resp<<endl;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}