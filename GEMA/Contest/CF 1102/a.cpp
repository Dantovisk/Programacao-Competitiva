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

void solve(){
    int n; cin>>n;
    vi v(n);

    rep(i, 0, n) cin>> v[i];

    sort(all(v));
    reverse(all(v));


    vi eu(n, 0);

    eu[0] = v[0];
    eu[1] = v[1];

    int da = 1;
    rep(k, 2, n){
        eu[k] = (eu[k-2] % eu[k-1]);
        if(eu[k] == 0){
            da = 0;
            break;
        }
        if(eu[k] != v[k]){
            da = 0;
            break;
        }
    }

    if(da){
        cout<<v[0]<<" "<<v[1]<<"\n";
        return;
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