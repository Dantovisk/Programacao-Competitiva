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

bool pal(ll n){
    vi digs;
    while(n){
        digs.pb(n%10);
        n/=10;
    }

    int k = digs.size();
    rep(i, 0, k/2){
        if(digs[i] != digs[k-1-i]) return false;
    }
    return true;
}

void solve(){
    ll n; cin>>n;

    ll curr = n % 12;
    ll resto = n-curr;

    while(resto >= 0){
        if(pal(curr)){
            cout<<curr<<" "<<resto<<"\n";
            return;
        }
        resto -= 12;
        curr+= 12;
    }
    cout<<"-1\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}