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
    int n, q;
    cin>>n>>q;

    vi v(n+1), a(n+1, 0), b(n+1, 0), um(n+1, 0);
    vi cta(n+1, 0), ctb(n+1, 0);
    rep(i, 1, n+1){
        cin>>v[i];
        
        a[i] = a[i-1];
        b[i] = b[i-1];
        cta[i] = cta[i-1];
        ctb[i] = ctb[i-1];
        um[i] = um[i-1];

        if(v[i] == 1) um[i]++;
        else if(v[i] % 2){
            ctb[i]++;
            b[i] += v[i];
        }else if(__builtin_popcount(v[i]) == 1){
            cta[i]++;
            a[i] += v[i];
        }
    }

    rep(i, 0, q){
        int l, r;
        cin>>l>>r;

        int va = 0, vb = 0;
        va = a[r] - a[l-1];
        vb = b[r] - b[l-1];

        int q1 = cta[r] - cta[l-1];
        int q2 = ctb[r] - ctb[l-1];

        int sobra = um[r] - um[l-1];
        
        va += sobra/2;
        vb += sobra/2;
        va += sobra%2;
        
        if(va > vb) cout<<"A\n";
        else if(va == vb) cout<<"E\n";
        else cout<<"B\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}