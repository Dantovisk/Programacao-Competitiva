#include <bits/stdc++.h>
using namespace std;
const long long inf= 1e9+7;

void solve(){
    int n, m;
    cin>>n >> m;

    vector<vector<long long>> grid (n, vector<long long>(m, 0));
    // Inicializa a DP com um valor muito baixo (-inf) para representar estados não alcançados
    vector<vector<long long>> dp (n, vector<long long>(m,-inf));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    // Caso base: define o valor inicial se a célula de partida não for um obstáculo (-1)
    dp[0][0] = (grid[0][0] != -1 ? grid[0][0]: -1000000000);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // Transição para baixo: atualiza a célula inferior com o valor máximo acumulado até agora
            if(i <n-1 and grid[i+1][j] != -1) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + grid[i+1][j]); 
            
            // Transição para a direita: atualiza a célula adjacente com o valor máximo acumulado
            if(j <m-1 and grid[i][j+1] != -1) dp[i][j+1] = max(dp[i][j+1], dp[i][j] + grid[i][j+1]); 
        }
    }
    // Verifica se o destino final foi alcançado com um valor válido; caso contrário, retorna -1
    cout<<(dp[n-1][m-1] > 0? dp[n-1][m-1] : -1)<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 

    for(int i =0; i<t; i++){
        solve();
    }

}