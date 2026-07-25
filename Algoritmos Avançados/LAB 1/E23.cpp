#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e3+7;

map<int, pair<long long, vector<int>>> resp; //guarda as respostas que já apareceram

//direções das rainhas
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                 {1, 1}, {-1, 1}, {1, -1}, {-1,-1}};

// verifica se x e y está na matriz
bool bounds(int x, int y, int n){
    if(x < 0 or x > n-1 or y < 0 or y > n-1) return false;
    return true;
}

//vetor lexicograficamente minimo para resposta atual
vector<int> minres;

// recursao para encontrar os tabuleiros validos
long long busca(vector<int> &v, int n, vector<vector<int>>& vis){
    if(v.size() == n) {
        if(minres.empty()) minres = v;
        return 1;
    }
    
    int uai = 0;

    //verifica quais colunas estão válidas para usar
    vector<int> pode(n+1, 1);
    for(int i = 0; i< v.size(); i++) {
        pode[v[i]] = 0;
    }

    long long currSum = 0;
    
    for(int j = 0; j<n; j++){
        if(!pode[j]) continue;

        int da = 1;
        int i = v.size();
        
        if(vis[i][j] >= 1){
            continue;
        }

        queue<pair<int, int>> q; //para reverter mudanças
        vis[i][j] = 1; //rainha está em (i, j)
        q.push({i, j});
        
        for(auto &d: dir){
            int x = i, y = j;
            x += d[0];
            y += d[1];
            while(bounds(x, y, n)){
                if(vis[x][y] == 1){
                    da = 0; 
                    break;
                }
                else if (vis[x][y] == 0){
                    vis[x][y] = 2; //rainha alcança a posição (x, y)
                    q.push({x, y});
                }
                x += d[0];
                y += d[1];
            }
            if(!da) break;
        }

        // A coluna atual é valida
        if(da){
            v.push_back(j);
            currSum += busca(v, n, vis);
            v.pop_back();
        }

        //Reverte as mudanças no tabuleiro
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            vis[x][y] = 0;
        }
    }
    return currSum;
}

void solve(int n){
    // se já computou a resposta, imprime ela
    if(resp.find(n) != resp.end()){
        auto [b, vec] = resp[n];        
        cout<<"["<<n<<","<<b<<"]\n";
        if(vec.size() == 0) cout<<"sem solucao\n";
        else {
            for(auto x: minres) cout<<x+1<<" ";
            cout<<"\n";
        }
    }

    minres.clear();
    int cont = 0;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<int> aux = {};
    long long currResp = busca(aux, n, vis);
        
    resp[n] = {currResp, minres};

    //imprime a resposta
    cout<<"["<<n<<","<<currResp<<"]\n";
    if(minres.size() == 0) cout<<"sem solucao\n";
    else {
        for(auto x: minres) cout<<x+1<<" ";
        cout<<"\n";
    }
}

vector<int> perm;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;

    while(t != 0){
        solve(t);
        cin>>t;
    }
}