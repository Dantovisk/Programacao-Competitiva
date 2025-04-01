#include <bits/stdc++.h> //CSES - Counting Numbers
#define int long long

using namespace std;

vector <int> digits;

// dp[i][j][z][tight] = quantas numeros
// no indice i do digito
// com o digito anterior sendo j
// z == define se tem um zero à esquerda no numero atual
// tight = está limitado ao numero original
int dp[20][11][2][2];

int digitdp(int id, int ant, int zr, int tight){
    //já viu todos os digitos
    if(id >= (int)digits.size()) return 1;

    //já computou esse estado
    if(dp[id][ant][zr][tight] != -1) return dp[id][ant][zr][tight];

    int cont = 0;
    int lim = tight? digits[id] : 9;

    for(int i = 0; i<= lim; i++){
        //nao podemos contar numeros que quebrem a regra
        //exceto se forem zeros à esquerda
        if(i == ant && !zr) continue;
        cont += digitdp(id+1, i,zr && (i == 0), tight && (lim == i));
    }
    return dp[id][ant][zr][tight] = cont;
}

int solve(int a){
    if(a < 0) return 0;
    digits.clear();
    memset(dp, -1, sizeof(dp));
    while(a > 0){
        digits.push_back(a%10);
        a/=10;
    }
    reverse(digits.begin(), digits.end());
    return digitdp(0, 10, 1, 1);
}

int32_t main(){

    int a, b;
    cin>>a>>b;
    int resp = solve(b) - solve(a-1);
    cout<<resp<<"\n";
        
    return 0;
}