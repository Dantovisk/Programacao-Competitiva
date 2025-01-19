#include <bits/stdc++.h>    //cses

using namespace std;

int v[21];
int dp[(1<<20)];    //o minimo de viagens
int sum[(1<<20)];  //o quanto de peso foi já utilizado para dp[i]

const int inf = 1e9 + 11;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    cin>>n>>w;

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    for(int i=1; i<(1<<n); i++){
        dp[i] = inf;
    }

    dp[0] = 0;
    sum[0] = 0;

    for(int bm=0; bm < (1<<n); bm++){
        for(int i=0; i<n; i++){
            if((bm>>i)&1 ) continue;

            int mask = (bm |(1<<i));
            

            //peso permitido
            int newdp = dp[bm] + (sum[bm] + v[i] <= w ? 0 : 1);
            int newsum = sum[bm] + v[i] <= w ? sum[bm] + v[i] : v[i];

            if(dp[mask]> newdp){
                dp[mask] = newdp;
                sum[mask] = newsum;
            } 
            else if(dp[mask] == newdp){
                sum[mask] = min(sum[mask], sum[bm] + v[i]);
            }

            /*
            if(sum[bm] + v[i] <= w){
                if(dp[mask]> dp[bm]){

                } else if(dp[mask] == dp[bm]){
                    sum[mask] = min(sum[mask], sum[bm] + v[i]);
                }
            }
            //nova viagem necessária
            else{

            }*/
        }


    }
    
    cout<<dp[(1<<n)-1] + (sum[(1<<n)-1] == 0? 0: 1);
    
}