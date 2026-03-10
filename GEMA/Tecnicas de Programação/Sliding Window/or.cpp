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
    int n, k;
    cin>>n>>k;
    int x, a, b, c;
    cin>>x>>a>>b>>c;
    int sum = 0;

    vi v(n), res(n);
    v[0] = x;
    rep(i, 1, n){
        v[i] = (v[i-1]*a + b)%c;
    }

    rep(i, 0, k-1){
        sum ^= v[i];
    }

    int xors = 0;

    rep(i, 0, n-k+1){
        sum ^= v[i+k-1];
        xors ^= sum;
        sum ^= v[i];
    }

    cout<<xors<<"\n";


}