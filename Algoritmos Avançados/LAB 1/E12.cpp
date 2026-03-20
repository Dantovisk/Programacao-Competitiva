#include <bits/stdc++.h>
using namespace std;
const int mod= 1e9+7; // Define o módulo para evitar overflow em números muito grandes

void solve(){
    int n;
    cin>>n;

    vector<string> grid(n);
    vector<vector<int>> dp (n, vector<int>(n, 0)); // Tabela DP para armazenar o número de caminhos até cada célula

    for(int i = 0; i < n; i++){
        cin>>grid[i];
    }

    // Inicialização do caso base: se o início for um obstáculo, não há caminhos (0), caso contrário, há 1
    dp[0][0] = (grid[0][0] == '.'? 1: 0);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // Transição: Se a célula abaixo é válida, soma o número de caminhos atuais a ela
            if(i <n-1 and grid[i+1][j] == '.') dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod; 
            
            // Transição: Se a célula à direita é válida, soma o número de caminhos atuais a ela
            if(j <n-1 and grid[i][j+1] == '.') dp[i][j+1] = (dp[i][j+1] + dp[i][j])%mod; 
        }
    }
    // O resultado final na última célula representa o total de caminhos distintos possíveis
    cout<<dp[n-1][n-1]<<"\n";
}

int main() {
    // Otimização de I/O para entradas grandes
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 

    for(int i =0; i<t; i++){
        solve();
    }

}