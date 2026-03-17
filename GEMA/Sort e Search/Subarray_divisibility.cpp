#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX  = 2e5+3;
ll v[MAX];

map<ll, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    rep(i, 0, n) cin>>v[i];

    ll diff = 0;
    ll res = 0;

    rep(i, 0, n){
        mp[((diff % n) + n)%n]++;
        diff = (((diff + v[i])%n)+n)%n;
        res += mp[((diff - n) + n) % n];
    }
    
    cout<<res<<"\n";

    return 0;
}
