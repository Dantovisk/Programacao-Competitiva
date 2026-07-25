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
const ll mod = 998244353;


void solve(){
    int n;
    cin>>n;

    vi a(n), b(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    rep(i, 0, n){
        cin>>b[i];
    }

    int best = 0;
    int l = 1, r = maxn;
    while(l <r){
        int m = (l+r)/2;

        //testa
        int da = 0;
        int tot = 0;
        int uns = 2;
        rep(i, 0, n){
            if(a[i] >= m and b[i] >= m){
                // 1 1
                tot++;
                uns = 2;
            }
            else if(a[i] >= m or b[i] >= m){
                // 1 0
            } 
            else{
                // 0 0
                if(uns == 2) {
                    uns = 0;
                    tot--;
                }
            }
        }
        if(tot > 0) da = 1;

        if(da){
            best = m;
            l = m+1;
        }
        else{
            r = m;
        }
    }

    cout<<best<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}