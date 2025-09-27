#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef vector<int> vi;
const int MAXN = 2e5+7;
const int inf = 1e9+7;
const ll mod = 998244353;


int dp[4'500'000];
int n;

ll add(ll a, ll b){return (a+b)%mod;}
ll mul(ll a, ll b){return (a*b)%mod;}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n;
    string a; cin>>a;
    dp[0] = 1;

    for(int i = 0; i< (1<<(n)); i++){
        char ant = '.';

        for(int j = 0; j< n; j++){
            if((1<<j) & i) continue;
            if(a[j] == ant) continue;
            ant=a[j];

            int nm = (1<<j) | i;
            dp[nm] = add(dp[nm], dp[i]);
        }

    }
    ll res = dp[(1<<n)-1];

    // for(auto q: xd){
    //     res = modfat(res, q);
    // }

    cout<<res<<"\n";

    // for(auto s: g)cout<<s<<"\n";
    

}