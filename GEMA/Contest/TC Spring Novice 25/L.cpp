#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int m, n;
    cin>>m>>n;

    vi v(m), a(m);
    rep(i, 0, m){
        cin>>v[i];
        a[i] = n/v[i];
    }
    reverse(all(a));

    ll res = 0;
    int curr = 0;

    rep(i, 0, m){
        if(a[i]>curr) curr++;

        int base = ((i+1)*(i+2))/2;
        int aux = i+1 - curr;
        base -= (aux*(aux+1))/2;

        res += base;
    }

    cout<<res<<"\n";

}