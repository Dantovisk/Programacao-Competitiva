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
    int n, m; 
    cin>>n>>m;
    vi a(n), b(m);

    rep(i, 0, n) cin>>a[i];
    rep(i, 0, m) cin>>b[i];

    sort(all(a));
    sort(all(b));

    int l =0, r = 0;
    rep(i, 0, m){
        while(l < n and a[l] == -1){
            l ++;
            r = max(r, l);
        }
        if(l >= n){
            cout<<"NO\n";
            return;
        }

        if(a[l] == b[i]){
            l++;
            continue;
        }

        if(a[l] > b[i]){
            cout<<"NO\n";
            return;
        }
        else{
            //a[l] < b[i]

            while((a[r] < b[i] or a[r] == -1) and r < n){
                r++;
            }

            if(r >= n){
                cout<<"NO\n";
                return;
            }
            a[r] = a[l] = -1;
            l++;
            r++;
        }
        
        
    }

    cout<<"YES\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}