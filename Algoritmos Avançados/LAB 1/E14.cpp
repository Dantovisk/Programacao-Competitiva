#include <bits/stdc++.h>
using namespace std;
const long long inf= 1e9+7;

void solve(){
    int n, m;
    cin>>n >> m;

    vector<vector<long long>> grid (n, vector<long long>(m, 0));

    // DP 3D: dp[i][j][k] onde k representa a direção de entrada na célula
    // k=0: veio de cima | k=1: veio da esquerda | k=2: veio da direita
    vector<vector<vector<long long>>> dp (n, vector<vector<long long>>(m, vector<long long>(3,-inf)));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j]; 
        }
    }

    // Estado inicial: começando na célula superior esquerda vindo "de cima" (ou do nada)
    dp[0][0][0] = (grid[0][0] != -1 ? grid[0][0]: -1000000000);
    
    auto process = [&](int i, int j, int k){
        // Movimento para baixo: transiciona qualquer estado atual para o estado '0' da linha seguinte
        if(i <n-1 and grid[i+1][j] != -1){
            dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k] + grid[i+1][j]); 
        } 
        // Movimento para a direita: só é permitido se não acabamos de vir da direita (evita ciclo)
        if(j <m-1 and grid[i][j+1] != -1) {
            if(k <2)
                dp[i][j+1][1] = max(dp[i][j+1][1], dp[i][j][k] + grid[i][j+1]); 
        }
        // Movimento para a esquerda: só é permitido se não acabamos de vir da esquerda (evita ciclo)
        if(j > 0 and grid[i][j-1] != -1) {
            if(k != 1)
                dp[i][j-1][2] = max(dp[i][j-1][2], dp[i][j][k] + grid[i][j-1]);
        }
    };

    for(int i = 0; i < n; i++){
        for(int k = 0; k < 3; k++){
            // Passada da esquerda para a direita para propagar movimentos laterais
            for(int j = 0; j < m; j++){
                process(i, j, k);
            }
            // Passada da direita para a esquerda para garantir que movimentos vindos da direita sejam processados
            for(int j = m-1; j >= 0; j--){
                process(i, j, k);
            }
        }
    }
    
    // O resultado final é o máximo entre os três estados possíveis de chegada na última célula
    long long res = max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    cout<<(res > 0? res : -1)<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 

    for(int i =0; i<t; i++){
        solve();
    }

}