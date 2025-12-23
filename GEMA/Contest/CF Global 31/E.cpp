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
// #define pb push_back

const int inf = 1e9+7;

void solve(){
    ll l, r;
    cin>>l>>r;

    ll res = 1;
    ll add = 0;
    for(int i = 50; i>= 0; i--) cout<<(((1LL<<i)&r)?"1":"0");
    cout<<"\n";
    for(int i = 50; i>= 0; i--) cout<<(((1LL<<i)&l)?"1":"0");
    cout<<"\n";

    bool moggou = false;

    ll diff = r-l;
    if(diff == 0LL) {
        cout<<"0\n";
        return;
    }
    int mx = 0;


    for(int i = 1; i<= 53; i++){
        ll aux = (1LL<<i)-1LL;
        ll aux2 = (1LL<<(i-1));

        if((aux&l) == 0LL && (aux&r) == aux){
            // cout<<i<<" foi\n";
            res *= 2;
        }
        else if((l&aux) < (r&aux) && ((l^r)&aux) == aux) {
            res*=2;
            // cout<<"apelei\n";
            // break;
        } else if ((aux2&l) == (aux2&r)){
            moggou = true;
            break;
        }
    }
    cout<<res-1LL+add<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}