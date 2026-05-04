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
    
    int n ; cin >> n ; 
    
    int pto = 0 ;
    int prev2 = 0, prev1 = 0 ;

    for(int i = 1  ;i <= n ; i++){
        int a ; cin >> a ; 
        if(a == 1){
            pto++ ;
        }
        else pto-- ;
        if(a == 1 && a == prev2 && a == prev1) pto++ ; 
        prev2 = prev1 ;
        prev1 = a ;
    }

    cout << pto << "\n" ;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}