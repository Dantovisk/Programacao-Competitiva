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

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n = 100000;
    cout<<"1\n"<<n<<"\n";

    int k = 0;
    while(k < n){
        for(int j = 0; j<32 and k<n; j++){
            cout<<(1u<<j)<<" ";
            k++;
        }
    }
    cout<<"\n";

    // int t = 1;
    // cin>>t;

    // while(t--) solve();
}