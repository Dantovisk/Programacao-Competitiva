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
    int n, k, m; 
    cin>>n>>k>>m;

    if(m < k){
        cout<<"NO\n";
        return;
    }
    else{
        cout<<"YES\n";
    }

    int i =0;
    while(i < n){
        rep(j, 0, k){
            if(j == 0){
                cout<<m-k+1<<" ";
            }
            else cout<<"1 ";
            i++;
            if(i >= n) break;
        }
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