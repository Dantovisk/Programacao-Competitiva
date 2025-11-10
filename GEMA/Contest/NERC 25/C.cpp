#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
#define ff first
#define ss second


int dp[6010][6010];
int inf = 1e6+5;

int n;
string a; 

// 0 -> monocarp -> quer fechar sequencia
// 1 -> polycarp -> ta torcendo contra
int vez(int k){
    if((k%2) == (n%2)) return 0;
    else return 1;
}

int game(int l, int r){
    int v = vez(r-l+1);

    if(l == r) {
        if(v == 0) return (a[l] == '('? -1 : 1);
        return 0;
    }

    if(l == 0 && r== n-1){
        if(a[l] == ')' && a[r] == ')') return 0;
        if(game(l+1, r) >= 1 && a[l] == '(') return 1;
        if(game(l, r -1) >= 1 && a[r] == '(') return 1;
        return 0;
    }

    if(dp[l][r] != -inf) return dp[l][r];

    if(v==0){
        int k = max({game(l+1, r) + (a[l] == '('? -1 : 1),
                game(l, r-1) + (a[r] == '('? -1 : 1), 0,
                (a[l] == '('? -1 : 1), (a[r] == '('? -1 : 1)});
        return dp[l][r] = k;
    }
    else{
        int k = min(game(l+1, r), game(l, r-1));
        return dp[l][r] = k;
    }
}

void solve(){
    cin>>n;
    cin>>a;

    rep(i, 0, n+1){
        rep(j, 0, n+1){
            dp[i][j] = -inf;
        }
    }
    if(game(0, n-1)) cout<<"Monocarp\n";
    else cout<<"Polycarp\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}