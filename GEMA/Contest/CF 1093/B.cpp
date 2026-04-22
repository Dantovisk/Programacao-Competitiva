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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n, m; 
    cin>>n>>m;

    vi v(n);
    rep(i,0, n) cin>>v[i];

    int acum = 0;
    int curr = 1;
    int mx = 1;
    rep(i, 0, n-1){
        if(v[i] == v[i+1]) {
            curr++;
            mx = max(mx, curr);
        }
        else{
            curr = 1;
        }
    }

    if(mx >= m) cout<<"NO\n";
    else cout<<"YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}