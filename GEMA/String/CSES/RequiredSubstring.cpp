#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int nxt[101][26];
const ll mod = 1e9+7;

ll dp[1010][110][2];

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    string p;
    cin>>n>>p;

    string aux = "";
    for(int i =0; i<= sz(p); i++){
        for(char c = 'A'; c<= 'Z'; c++){
            aux.push_back(c);
            
            for(int s = min(sz(p), sz(aux)); s >= 0; s--){
                if(aux.substr(sz(aux)- s, s) == p.substr(0, s)){
                    nxt[i][c-'A'] = s;
                    break;
                }
            }

            aux.pop_back();
        }
        if(i < sz(p)) aux.push_back(p[i]);
    }

    // return 0;
    dp[0][0][0] = 1;
    for(int i = 0; i< n; i++){
        for(int j = 0; j<= sz(p); j++){
            for(int c = 0; c<26; c++){
                dp[i+1][nxt[j][c]][1] += dp[i][j][1];
                dp[i+1][nxt[j][c]][1] %= mod;
                dp[i+1][nxt[j][c]][(nxt[j][c] == sz(p))? 1: 0] += dp[i][j][0];
                dp[i+1][nxt[j][c]][(nxt[j][c] == sz(p))? 1: 0] %= mod;
            } 
        }
    }
    ll res = 0;

    rep(i, 0, sz(p)+1){
        res += dp[n][i][1];
        res %= mod;
    }
    cout<<res<<"\n";
}