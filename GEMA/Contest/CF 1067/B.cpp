#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    vi cont(2*n+3, 0);

    rep(i,0,2*n) {
        int a; cin>>a;
        cont[a]++;
    }

    int res =0;
    int quatros = 0;
    int diff = 0;
    rep(i,1,2*n+1) {
        if(cont[i] == 0) continue;
        diff++;
        if(cont[i]%4 == 0) quatros+=2;
        else if(cont[i] %2) res++;
        else res+=2;
    }
    cout<<res + (diff>1? quatros : 0)<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}