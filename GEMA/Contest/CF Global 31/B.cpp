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

void solve(){
    int n;
    cin>>n;

    string res = "";
    deque<string> resp;
    vector<string> v(n);
    rep(i, 0, n) cin>>v[i];
    
    for(auto s: v){
        if(res + s > s + res){
            res = s + res;
        }
        else res = res+s;
    }
    // for(auto r: resp)cout<<r;
    // cout<<"\n";
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}