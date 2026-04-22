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
#define pb push_back

const int MAX = 1e5+7;
const int inf = 1e9+7;

ll mod = 998244353;

void solve(){
    ll n, x;
    cin >> n >> x;

    ll res = 0;

    ll st1 = x - (x%4LL);
    ll ed1 = st1 + 4;

    ll esq1 = (st1 / 4LL) + 1;
    ll dir1 = ((n+1LL) - st1)/4LL;

    if(ed1 <= n + 1){
        res = ((esq1%mod) * (dir1%mod)) % mod;
    }

    ll st2, ed2;
    if(x % 4 < 2){
        st2 = st1 - 2;
        ed2 = ed1 - 2;
    }
    else{
        st2 = st1 + 2;
        ed2 = ed1 + 2;
    }

    // cout<<st2<<" <-> "<<ed2<<"\n";
    

    if(st2 < 0 or ed2 > n + 1) {
        cout<<res<<"\n";
        return;
    }

    ll esq2 = (st2 / 4LL) + 1;
    ll dir2 = ((n+1LL) - st2)/4LL;

    res += ((esq2%mod) * (dir2%mod)) % mod;
    res %= mod;

    // cout<<esq2<<" - "<<dir2<<"\n";
    
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}