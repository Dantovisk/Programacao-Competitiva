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
    ll n, k;
    cin>>n>>k;

    map<pii, int> ct;
    map<pii, int> ct2;

    map<int, ll> vals; 
    vals[1] = 1;
    vals[2] = 1;
    vals[3] = 0;

    ct[{1, 2}] = 1;

    rep(i, 0, k){
        for(auto [pr, qt] : ct){
            auto [x, y] = pr;
            vals[(x^y)] += qt;
            ct2[{x, (x^y)}] += qt;
            ct2[{(x^y), y}] += qt;
        }
        ct = ct2;
        ct2.clear();
    };

    ll cx=0, cy=0, cxy=0;
    string a, b;
    cin>>a>>b;

    rep(i, 0, n) if(a[i] == '1') cx++;
    rep(i, 0, n) if(b[i] == '1') cy++;
    rep(i, 0, n) if(a[i] != b[i]) cxy++;

    ll res = 0;
    res += vals[1] * (cx) * (n-cx);
    res += vals[2] * (cy) * (n-cy);
    res += vals[3] * (cxy) * (n-cxy);

    // cout<<vals[1]<<" "<<vals[2]<<" "<<vals[3]<<"\n";
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}