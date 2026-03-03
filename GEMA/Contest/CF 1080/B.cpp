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

    vector<pii> a;

    vi v(n+1), v2;
    rep(i, 1, n+1) {
        cin>>v[i];
        a.push_back({v[i], i});
    }

    sort(all(a));

    rep(i, 0, n){
        int id = i+1;

        int curr = a[i].ss;
        if(id > curr) swap(id, curr);

        while(curr >= 2*id && curr % 2 == 0) curr/=2;

        if(id != curr){
            cout<<"NO\n";
            return;
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