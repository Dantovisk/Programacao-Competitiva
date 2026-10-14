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

    string a, b; cin>>a>>b;
    vi p1(n+1, 0), p2(n+1, 0), ig(n+1, 0);

    rep(i, 1, n+1) {
        p1[i] = p1[i-1] + (a[i-1] == '0' and b[i-1] == '1' ? 1: 0);
        p2[i] = p2[i-1] + (b[i-1] == '0' and a[i-1] == '1' ? 1: 0);
        ig[i] = ig[i-1] + (a[i-1] == b[i-1] ? 1 : 0);
    }

    rep(i, 0, q){
        int l, r;
        cin>>l>>r;

        int s = r - l +1;
        
        int qt1 = p1[r] - p1[l-1];
        int qt2 = p2[r] - p2[l-1];
        int qig = ig[r] - ig[l-1];
        int dif = abs(qt1-qt2);

        if(dif <= qig){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}