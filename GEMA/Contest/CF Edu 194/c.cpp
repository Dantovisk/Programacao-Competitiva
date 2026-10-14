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
    int cost = 0;
    int x, y;
    cin>>x>>y;

    int res = x+y;

    for(int i = 29; i>= 0; i--){
        if(((1<<i)&res) and !((1<<i)&(y|x))){
            int aux = (1<<i)-1;
            int vai = aux+1 - (aux&y);

            cost += vai;
            y += vai;
            x -= vai;
        }
    }
    

    cout<<(y^x)<<" "<<cost<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}