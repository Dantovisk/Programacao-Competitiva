//Team Building - Codeforces
#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long int

using namespace std;

pair <int,int> ind[MAXN];
int val[MAXN][7];
ll dp[MAXN][130];//maior valor usando as pessoas de indice até N 
                    //e jogadores no time correspondente à bitmask 

int main(){
    int n, p, k;
    cin>>n>>p>>k;

    for(int i=1; i<=n; i++){
        int a; cin>>a;
        ind[i] = {a, i};
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<p; j++){
            cin>>val[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    sort(ind+1, ind+n+1);
    reverse(ind+1, ind+n+1);

    dp[0][0] = 0;

    //iterando pelas pessoas
    for(int i=1; i<=n; i++){
        //iterando pelos bitmasks
        for(int bm=0; bm<(1<<p); bm++){
            //pulando testes inválidos
            if(dp[i-1][bm] == -1) continue;

            //vendo o numero de 1 na bitmask
            int cont = __builtin_popcount(bm);

            //verificando se é necessario adicionar a pessoa
            //na comissão ou não
            int x = (i-1)-cont;
            if(x<k){
                dp[i][bm] = max(dp[i][bm], dp[i-1][bm] + ind[i].first);
            }
            else{
                dp[i][bm] = max(dp[i-1][bm], dp[i][bm]);
            }

            //testando a validade da adição ao time
            for(int j = 0; j < p; j++){
                if((bm & (1<<j)) == 0){
                    int mask = bm | (1<<j);

                    dp[i][mask] = max(dp[i][mask],
                    dp[i-1][bm] + val[ind[i].second][j]);
                }
            }
        }
    }

    cout<<dp[n][(1<<p)-1]<<"\n";

    return 0;
}