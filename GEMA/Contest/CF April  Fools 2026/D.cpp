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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n; 
    cin>>n;

    if(n == 1) cout<<"walk\n";
    if(n == 2) cout<<"no\n";
    if(n == 3) cout<<"no\n";
    if(n == 4) cout<<"no\n";
    if(n == 5) cout<<"yes\n";
    if(n == 6) cout<<"yes\n";
    if(n == 7) cout<<"Backwards\n";
    if(n == 8) cout<<"5\n";

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}