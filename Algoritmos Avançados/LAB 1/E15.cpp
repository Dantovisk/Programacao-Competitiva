#include <bits/stdc++.h>
using namespace std;
const long long inf= 1e9+7;

void solve(){
    int n, m;
    cin>>n >> m;

    vector<string> grid (n);

    int mny = n, mnx = m, mxx = 0;
    for(int i = 0; i < n; i++){
        cin>>grid[i];  
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'B'){
                // Identifica a linha mais alta (menor índice i) com um respingo
                mny = min(mny, i);

                // Identifica os limites horizontais (coluna mais à esquerda e mais à direita)
                mnx = min(mnx, j);
                mxx = max(mxx, j);
            }
        }
    }
    
    // Caso nenhum 'B' tenha sido encontrado, a área de repintura é zero
    if(mnx > mxx) {
        cout<<"0 0\n";
        return;
    }
    // A altura (ry) é a distância da linha mais alta até o chão (n - mny)
    int ry = n- mny;
    // A largura (rx) é a distância entre a coluna mais à esquerda e a mais à direita
    int rx = mxx - mnx + 1;

    cout<<ry<<" "<<rx<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}