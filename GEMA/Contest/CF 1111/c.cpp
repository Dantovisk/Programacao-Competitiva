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

    vi a(n), b(n);

    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];

    //
    if(a == b){
        cout<<"0\n";
        return;
    }
    if(*max_element(all(a)) == 0){
        cout<<"-1\n";
        return;
    }
    if(*min_element(all(b)) == 1){
        cout<<"-1\n";
        return;
    }

    int zeros = 0, uns = 0;

    rep(i, 0, n){
        if(a[i] != b[i]){
            if(a[i] == 0) zeros++;
            else uns++;
        }
    }

    if(uns%2){
        cout<<"1\n";
        return;
    }

    cout<<"2\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}