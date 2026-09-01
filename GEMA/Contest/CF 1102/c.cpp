#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;
#define ff first
#define ss second
#define pb push_back

const int maxn = 2e5+4;
const int inf = 1e9+3;

void solve(){
    int n; cin>>n;
    vi v(2*n);

    rep(i, 0, n) {
        cin>> v[i];
        v[i+n] = v[i];
    }

    // vi resp(n);

    rep(i, 0, n){
        //i eh o inicio;

        vi mx (n, 0);
        vi mx2 (n, 0);
        rep(j, i, n+i-1){
            mx[(j+1)%n] = max(mx[j%n], v[j]);

        }

        for(int j = i + n - 1; j > i; j--){
            mx2[j%n] = max(mx2[(j+1)%n], v[(j)%n]);
        }


        ll res = 0;
        rep(j, 0, n){
            if(j != i) res += min(mx[j], mx2[j]);
        }
        cout<<res<<" ";
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}