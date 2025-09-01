#include <bits/stdc++.h> // Procurar sobre o período de pisano para potencia de 10
#define ll long long     // Não acho que tenho a bagagem para esse problema ainda
using namespace std;

const ll MOD= 10'000'000'000;
const ll PIS= 15'000'000'000;

ll mul(ll a, ll b, ll mod=MOD){
    return (ll)(((__int128_t)a*(__int128_t)b)%((__int128_t)mod));
}

ll mexp(ll a, ll b, ll mod =MOD){
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

using mt = array<array<ll, 2>, 2>;

mt base ={{{0, 1}, {1, 1}}};
mt id ={{{1, 0}, {0, 1}}};

mt mtmul(mt a, mt b, ll mod = MOD){
    mt res ={0};
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            for(int k = 0; k<2; k++){
                res[i][j] += mul(a[i][k], b[k][j]);
                res[i][j] %= mod;
            }
        }
    }
    return res;
}


mt mtexp(mt a, ll exp, ll mod = MOD){
    if(exp == 1) return a;
    if(exp == 0) return id;
    mt k = mtexp(a, exp/2);
    if(exp%2) return mtmul(a, mtmul(k, k));
    return mtmul(k, k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    while(n--){
        ll k; cin>>k;
        ll a, b, c;

        a = mexp(7, k, PIS);
        b = mexp(7, a, PIS);
        c = mexp(7, b, PIS);

        if(c == 0) c = PIS;

        mt fib = mtexp(base, c);
        cout<<fib[0][1]<<"\n";
    }    

    return 0;
}