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
    int n; 
    cin>>n;

    int l = 1, r = n+1;
    int best = n+1;
    vi res;
    
    while(l < r){
        int ch = n;
        int m = (l+r)/2;
        vi aux;
        int tot = 0;

        for(int i = m; i > 0; i--){
            int foi = 0;

            while(foi + i <= m and tot + i <= n){
                tot += i;
                foi += i;
                rep(k, 0, i) {
                    aux.pb(ch);
                }
                ch--;
            }
        }

        if(tot == n){
            best = m;
            res = aux;
            r = m;
        }
        else{
            l = m+1;
        }
    }

    cout<<best<<"\n";
    for(auto x: res){
        cout<<x<<" ";
    }
    cout<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}