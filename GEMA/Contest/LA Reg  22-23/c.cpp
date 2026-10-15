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
    ll p, h; 
    cin>>n>>p>>h;
    p--;
    h--;

    vi aux;
    for(int i = n-1; i >= 0; i--){
        aux.push_back(((1LL<<i) & h) > 0);
        if((1LL<<i) & h){
            h ^= ((1LL<<(i+1))-1);
        }
    }

    string r;
    for(int i = n-1; i >= 0; i--){
        ll m = (1LL << i);
        if(aux[i]){
            if(m & p){
                r.pb('R');
                p ^= ((m<<1)-1);
            }
            else{
                r.pb('L');
                p ^= (m-1);
            }
        }
        else{
            if(m & p){
                r.pb('L');
                p ^= (m);
            }
            else{
                r.pb('R');
            }
        }
    }

    cout<<r<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}