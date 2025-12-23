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

void solve(){
    int n, k; cin>>n>>k;

    string a; cin>>a;

    int ct = k, res = 0;
    rep(i, 0, n){
        if(a[i] == '0'){
            ct++;
            if(ct > k) res++;
        }
        else ct = 0;
    }
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}