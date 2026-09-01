#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> base;
void add(ll a){
    for(auto x: base){
        a = min(a, (x^a));
    }
    if(a) base.push_back(a);
}
ll mod = 1e9+7;

vi pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

ll proc(ll a){
    ll rr = 0;
    rep(i, 0, sz(pr)){
        while(a % pr[i] == 0){
            a/= pr[i];
            rr ^= (1LL<<i);
        }
    }
    return rr;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin>>n;

    rep(i, 0, n){
        int a; cin>>a;
        add(proc(a));
    }
    
    ll res = 1;
    rep(i, 0, n-sz(base)){
        res <<= 1;
        res %= mod;
    }

    res = (res - 1 + mod) % mod;
    cout<<res<<"\n";
}