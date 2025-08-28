#include <bits/stdc++.h>    //CSES - Empty String
#define ll long long
using namespace std;

int v[510];

// Quantidade de formas de zerar no intervalo [i, j)
ll dp[510][510];

const ll mod = 1e9 + 7;
const ll MOD = 1e9 + 7;

ll comb[510][510];

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

void precompute(){
    // computa o inverso modular de 1..MAX-1 modulo um primo
    ll inv[510];

    inv[1] = 1;
    for (int i = 2; i < 502; i++) inv[i] = MOD - MOD/i*inv[MOD%i]%MOD;

    for(int s = 0; s<=500; s++){
        comb[s][0] = 1;
        for(int i = 1; i <= s; i++){
            comb[s][i] = (comb[s][i-1] * inv[i]) %mod;
            comb[s][i] *= (s + 1 - i);
            comb[s][i] %= mod;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a; cin>>a;
    int n = a.length();

    for(int i =0; i<n-1; i++){
        if(a[i] == a[i+1]) dp[i][i+1] = 1;
    }

    precompute();

    for (int i = 0; i + 1 <= n; ++i) dp[i + 1][i] = 1;

    for(int s = 4; s<=n; s+=2){
        for(int i =0; i<n; i++){
            int j = i+s-1;
            if(j>=n) break;
            for(int mid = i+1; mid<=j; mid+=2){
                if(a[i] != a[mid]) continue; 

                ll temp = (dp[mid+1][j] * dp[i+1][mid-1]) % mod;
                ll c = comb[s/2][(mid-i+1)/2];
                temp = (c * temp) % mod;
                dp[i][j] = (dp[i][j] + temp) % mod;
            }
        }
    }

    cout<<dp[0][n-1]<<"\n";
}
