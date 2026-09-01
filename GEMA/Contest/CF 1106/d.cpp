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

const int maxn = 2e5+4;
const int inf = 1e9+3;

vector<int> factor(int k){
    vi res;
    for(int i = 2; i*i <= k; i++){
        while(k % i == 0){
            res.pb(i);
            k/= i;
        } 
    }
    if(k > 1) res.pb(k);
    return res;
}

void solve(){
    int n; cin>>n;
    vi fac = factor(n);
    int res = fac.size();
    set<int> vis;
    for(auto x: fac) vis.insert(x);
    res += vis.size() - 1;
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}