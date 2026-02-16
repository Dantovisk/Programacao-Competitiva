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
    int n; cin>>n;
    vi p(n), a(n);

    rep(i, 0, n) cin>>p[i];
    rep(i, 0, n) cin>>a[i];


    int id = 0;
    rep(i, 0, n){
        while(p[id] != a[i]){
            id++;
            if(id >= n){
                cout<<"NO\n";
                return;
            }
        }
    }

    cout<<"YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}