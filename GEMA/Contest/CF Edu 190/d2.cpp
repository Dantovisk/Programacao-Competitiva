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
    int n;
    cin>>n;

    vi a(n), b(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    rep(i, 0, n){
        cin>>b[i];
    }
    
    set<int> falta;
    set<int> faltb;

    rep(i, 1, n+1) falta.insert(i+1);
    rep(i, 1, n+1) faltb.insert(i+1);

    ll res = 0;

    vi ca(n+1, 0), cb(n+1, 0);
    int l = 0;

    rep(i, 0, n){
        ca[a[i]] ++;
        if(ca[a[i]] == 1) {
            falta.erase(a[i]);
        }
        cb[b[i]] ++;
        if(cb[b[i]] == 1) {
            faltb.erase(b[i]);
        }

        if(a[i] != b[i]){
            auto ptr = ca.begin();
            while(l <= i and ptr != ca.end() and (*ptr) == a[i]){
                ca[a[l]]--;
                cb[b[l]]--;

                if(ca[a[l]] == 0) {
                    falta.insert(a[l]);
                }
                if(cb[b[l]] == 0) {
                    faltb.insert(b[l]);
                }

                ptr = ca.begin();
                l++;
            }

            ptr = cb.begin();
            while(l <= i and ptr != cb.end() and (*ptr) == b[i]){
                ca[a[l]]--;
                cb[b[l]]--;

                if(ca[a[l]] == 0) {
                    falta.insert(a[l]);
                }
                if(cb[b[l]] == 0) {
                    faltb.insert(b[l]);
                }

                ptr = cb.begin();
                l++;
            }
        }
        
        res += i-l+1;
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