#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+7;

int v[MAX];

int a[1050000];
int dp[1050000][21];
int sos[1050000];

int dp2[1050000][21];
int sos2[1050000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    int k = 20;

    for(int i =0; i<n; i++){
        cin>>v[i];
        a[v[i]]++;

    }

    // Parte 1 - Subsets
    for(int mask = 0; mask < (1<<k); mask++){
        dp[mask][0] = a[mask];
        for(int i =0; i<k; i++){
            if((1<<i) & mask){
                dp[mask][i+1] += dp[mask][i] + dp[mask ^ (1<<i)][i];
            }
            else dp[mask][i+1] += dp[mask][i];
        }
        sos[mask] = dp[mask][k];
    }

    // Parte 2 - Supersets
    for(int mask = (1<<k)-1; mask >= 0; mask--){
        dp2[mask][0] = a[mask];
        for(int i =0; i<k; i++){
            if(((1<<i) & mask) == 0){
                dp2[mask][i+1] += dp2[mask][i] + dp2[mask ^ (1<<i)][i];
            }
            else dp2[mask][i+1] += dp2[mask][i];
        }
        sos2[mask] = dp2[mask][k];
    }

    // x | y = x
    int tudo = ((1<<k)-1);
    for(int i =0; i<n; i++){

        int comp = (tudo^v[i]);

        cout<<sos[v[i]]<<" "<<sos2[v[i]]<<" "<<(n-sos[comp])<<"\n";
    }


}