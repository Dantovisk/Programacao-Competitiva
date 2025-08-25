#include <bits/stdc++.h> //Exponenciation II - CSES
#define ll long long
using namespace std;
const int MOD = 1e9+7;

ll mexp(ll b, ll e, ll mod){
    if(e==0) return 1;
    if(e==1) return b;

    ll k = mexp(b, e/2, mod);
    k = (k*k)%mod;
    if(e%2) return (k*b)%mod;
    return k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin>>q;

    while(q--){
        ll a, b, c;
        cin>>a>>b>>c;

        ll u = mexp(b, c, MOD-1);
        ll resp = mexp(a, u, MOD);
        cout<<resp<<"\n";
    }


    return 0;
}