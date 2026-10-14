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
    int n, m, x, y;
    cin>>n>>m>>x>>y;

    vi a(x), b(y);
    rep(i, 0, x){
        cin>>a[i];
    }
    rep(i, 0, y){
        cin>>b[i];
    }

    reverse(all(a));
    reverse(all(b));

    ll res = 0;
    int ct1 = 0;
    int ct2 = 0;
    int ct3 = 0;
    int i1 = 0, i2 = 0;

    while(ct1 <n and ct2 < m and ct1+ct2+ct3 < m+n-1 and i1 < x and i2 < y){
        if(a[i1] > b[i2]){
            res += a[i1];
            i1++;
            ct1++;
        }
        else if(a[i1] < b[i2]){
            res += b[i2];
            i2++;
            ct2++;
        }
        else{
            res += b[i2];
            i2++;
            i1++;
            ct3++;
        }
    }

    while(ct1 <n and ct1+ct2+ct3 < m+n-1 and i1 < x){
        res += a[i1];
        i1++;
        ct1++;
    }

    while(ct2 < m and ct1+ct2+ct3 < m+n-1 and i2 < y){
        res += b[i2];
        i2++;
        ct2++;
    }

    cout<<res<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}