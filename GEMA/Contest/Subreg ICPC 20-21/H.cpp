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
#define tii tuple<int, int, int>

const int MAX = 1e5+ 15;

ll v[60]; //N escolhe
ll n, k;

//n!/n! * (n-i + 1)/i

map<pair<ll,ll>, ll> mp;

ll choose(ll n, ll k){
    __int128_t res = 1;
    if(mp.find({n, k}) != mp.end()) return mp[{n, k}];

    ll u = k;
    for(ll i = 1; i<= k; i++) {
        res*= (n-i+1);
        while(u > 1 && res % u == 0) {
            res/=u;
            u--;
        }
    }

    mp[{n, k}] = (ll)res;
    // cout<<n<<" escolhe "<<k<<" = "<<res<<"\n";
    return (ll)res;
}

ll solve(ll r){
    // cout<<"SOLVE: "<<r<<"\n";
    ll res = 0;
    ll curr = r;

    ll u = k;
    for(int i = 1; i<=n+1; i++){
        // cout<<curr<<" - ("<<n-i<<" "<<u<<")\n";
        
        if(u == 0) {
            res++;
            break;
        }
        if(v[i] > curr) continue;

        //nao escolheu
        if(u <= n-i) res += choose(n-i, u);

        //escolheu
        u--;
        curr-=v[i];
    }
    return res;
}
//10 3 1
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>k;

    for(int i = 1; i<= n; i++){
        cin>>v[i];
    }
    sort(v+1, v+n+1);
    reverse(v+1, v+n+1);

    ll l, r;
    cin>>l>>r;

    cout<<(solve(r) - solve(l-1))<<"\n";

    return 0;
}