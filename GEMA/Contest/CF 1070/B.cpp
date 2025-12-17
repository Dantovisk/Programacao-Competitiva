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
    string a; cin>>a;

    a += a;

    int res = 0;

    int uns = 0;
    int zeros = 0;
    int mu = 0, mz = 0;
    for(int i = 0; i< 2*n; i++){
        if(a[i] == '1'){
            zeros = 0;
            uns ++;
            mu = max(mu, uns);
        }
        if(a[i] == '0'){
            uns = 0;
            zeros ++;
            mz = max(mz, zeros);
        }
    }


    res = mz;

    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}