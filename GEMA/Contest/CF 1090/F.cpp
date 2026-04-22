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
    int x, y;
    cin>>x>>y;

    if(x > y){
        cout<<"NO\n";
        return;
    }

    if(x == 0 and (y%2) == 0){
        cout<<"NO\n";
        return;
    }

    int curr = 1;

    cout<<"YES\n";
    rep(i, 0, 2*x + ((y-x)%2) - 1){
        cout<<curr<<" "<<(++curr)<<"\n";
    }

    rep(i, 0, y-x - (y-x)%2){
        cout<<curr<<" "<<curr+i+1<<"\n";
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}