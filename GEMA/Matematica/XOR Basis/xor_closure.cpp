#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> base;

void add(ll x){
    for(auto k: base){
        x = min(x, (x^k));
    }

    if(x) base.push_back(x);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin>>n;

    rep(i, 0, n){
        ll a;
        cin>>a;
        add(a);
    }
    ll res (1LL<<sz(base));
    res -= n;

    cout<<res<<"\n";
}