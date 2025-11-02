#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    vi a(n), b(n);

    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];


    ll l = 0, r =1e9+7, mid;
    ll best = 0;
    while(l < r){
        ll mid = (l+r)/2LL;

        ll falta = 0;

        for(int i = n-1; i>= 0; i--){
            if(b[i] > mid*a[i]){
                falta = max(0LL, falta - b[i] + (ll)a[i]*mid);
            } else if(b[i] < mid*a[i]){
                falta += mid*a[i] - b[i];
            }
        }

        if(falta == 0){
            best = max(best, mid);
            l = mid+1;
        }else r = mid;
    }

    cout<<best<<"\n";
}