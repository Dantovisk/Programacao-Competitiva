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
    ll n;
    cin>>n;

    ll uns = 0;
    ll todo = 0;
    ll ajuda = 0;
    vi v(n);
    rep(i, 0, n){
        cin>>v[i];
        if(v[i] == 1) uns++;
        else {
            todo += v[i];

            if(v[i] > 3) ajuda += (v[i] - 2)/2;
        }
    }

    if(todo < 2LL or (todo + uns) < 3LL) {
        cout<<"0\n";
        return;
    } 

    if(uns == n-1){
        cout<<todo + min(todo/2, uns)<<"\n";
    }
    else{
        cout<<todo + min(ajuda, uns)<<'\n';
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}