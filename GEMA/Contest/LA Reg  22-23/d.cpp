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
    int n, a, b; 
    cin>>n>>a>>b;

    rep(i, 0, n){
        char x, y;
        cin>>x;
        if(!b or x == 'Y'){
            a--;
            b++;
            cout<<"Y ";
        }
        else cout<<"N ";
        cin>>y;
        if(!a or y == 'Y'){
            b--;
            a++;
            cout<<"Y\n";
        }
        else cout<<"N\n";
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}