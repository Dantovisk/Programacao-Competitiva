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
    int sla = 20260401;
    vi v(3);

    rep(i,0, 3) cin>>v[i];
    sort(all(v));
    int x = 0;
    // x -= v[1];

    // x ^= (v[0]&sla);
    // x ^= (v[2]&sla);


    x ^= (v[0]);
    x ^= (v[2]);
    cout<<x<<" -> ";

    cout<<(x-v[1])<<"\n";
    

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--){
        cout<<"\nCaso "<<t<<"\n";
        solve();
    }
}