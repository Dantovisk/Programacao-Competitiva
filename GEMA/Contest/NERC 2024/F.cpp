#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second

int chose(int a, int b, vi& g){
    if(g[a] < g[b]) return a;
    return b;
}

const int inf = 1e6+7;

void solve(){
    int n, m;
    cin>>n>>m;

    vi g1(n+1), g2(n+1);

    rep(i, 0, n){
        int a; cin>>a;
        g1[a] = i;
    }
    rep(i, 0, n){
        int a; cin>>a;
        g2[a] = i;
    }

    vi v(m+1);
    //dp[i][mask1][mask2] -> não trocou o cara;
    vector<vector<vi>> dp(m+1, vector<vi>(4, vi(0, inf)));

    rep(i, 1, m+1){
        cin>>v[i];
    }

    v[0] = v[1];

    for(int i = 2; i<=m; i+= 2){
        //fecha um dia

        //os caras trocados do dia atual
        rep(mask1, 0, 4){
            //os caras que eu troquei do dia anterior com o atual
            rep(mask2, 0, 4){
                if(__builtin_popcount(mask1) != __builtin_popcount(mask2)) continue;

                rep(mask3, 0, 4){
                    rep(mask4, 0, 4){
            
                    }
                }
            }
        }
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;
    rep(i, 0, t){
        solve();
    }
}