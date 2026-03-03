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

    string a; cin>>a;

    a += a;

    int res = 0;
    rep(i, 0, n){
        int cont = 1;
        
        rep(j, 1, n){
            if(a[i+j] != a[i+j-1]) cont++;
        }
        res = max(res, cont);
    }
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}