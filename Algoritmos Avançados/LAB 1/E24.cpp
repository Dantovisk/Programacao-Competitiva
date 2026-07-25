#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<int>> sud(9, vector<int>(9, 0));

int visto[10];
//verifica se a linha i está correta
bool checkln (int i){
    memset(visto, 0, sizeof(visto));
    for(int j = 0; j< 9; j++){
        if(sud[i][j] == 0) continue; // Ainda não preencheu
        if(visto[sud[i][j]]) return false; //Tem 2 repetidos
        visto[sud[i][j]] = 1;
    }
    return true;
}

//verifica se a coluna j está correta
bool checkcol (int j){
    memset(visto, 0, sizeof(visto));
    for(int i = 0; i< 9; i++){
        if(sud[i][j] == 0) continue; // Ainda não preencheu
        if(visto[sud[i][j]]) return false; //Tem 2 repetidos
        visto[sud[i][j]] = 1;
    }
    return true;
}
//verifica se o bloco 3x3 está correto
bool check3 (int ib, int jb){
    memset(visto, 0, sizeof(visto));
    for(int i = ib*3; i< (ib+1)*3; i++){
        for(int j = jb*3; j< (jb+1)*3; j++){
            if(sud[i][j] == 0) continue; // Ainda não preencheu
            if(visto[sud[i][j]]) return false; //Tem 2 repetidos
            visto[sud[i][j]] = 1;
        }
    }
    return true;
}


ll solve (int i, int j){
    //alcançamos um tabuleiro invalido
    if(!checkln(i) or !checkcol(j) or !check3(i/3, j/3)){
        return 0;
    }
    
    if(i == 8 and j == 8) return 1; //fim do tabuleiro
    
    
    //encontra a proxima coordenada do tabuleiro
    int prox = i*9+j + 1;
    int nx = prox/9, ny = prox%9;
    
    // Proxima posicao estava preenchida originalmente
    if(sud[nx][ny]){
        return solve(nx, ny);
    }

    ll sum = 0;
    // Testa todos os números para a próxima célula
    for(int k = 1; k<= 9; k++){
        // Altera o valor do tabuleiro e depois retorna ao original
        sud[nx][ny] = k;

        sum += solve(nx, ny);
    
        sud[nx][ny] = 0;
    }

    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;

    for(int i = 0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        sud[a-1][b-1] = c;
    }

    cout<<solve(0, 0)<<"\n";
}