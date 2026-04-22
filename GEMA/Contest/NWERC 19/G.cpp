#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ld long double

const int inf = 1e9+7;
const double eps = 1e-7;

ld chose[510][510];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    rep(i, 0, 505) chose[i][0] = chose[i][i] = 1;

    rep(i, 2, 505){
        rep(j, 1, i){
            chose[i][j] = chose[i-1][j-1] + chose[i-1][j];
        }
    }

    cout<<fixed<<setprecision(15);

    int n, k;
    cin>>n>>k;

    vector<ld> v(2*n);
    vector<ld> res(2*n, 0);
    rep(i, 0, n) cin>>v[i];
    rep(i, 0, n) v[i+n] = v[i];

    ld tot = chose[n][k];
    rep(i, n, 2*n){
        rep(j, 0, n-k+1){
            res[i] += (v[i-j] * chose[n-1-j][k-1])/tot;
        }
    }

    rep(i, 0, n){
        cout<<res[i] + res[i+n]<<' ';
    }
    cout<<"\n";

}