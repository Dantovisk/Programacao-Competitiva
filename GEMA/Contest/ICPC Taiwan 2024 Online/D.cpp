#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9+7;
#define MAX 110

ll add(ll a, ll b, ll mod = MOD){return (a+b)%mod;}
ll mul(ll a, ll b, ll mod = MOD){return (a*b)%mod;}

ll mexp(ll a, ll b, ll mod =MOD){
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll mod=MOD){
    return mexp(a, mod-2, mod);
}

int prob[MAX][MAX], cost[MAX][MAX];
char grid[MAX][MAX];

int adj(int i, int j){
    ll res = 0;
    res = add(res, mul(add(add(1, -res), MOD), prob[i+1][j]));
    res = add(res, mul(add(add(1, -res), MOD), prob[i-1][j]));
    res = add(res, mul(add(add(1, -res), MOD), prob[i][j+1]));
    res = add(res, mul(add(add(1, -res), MOD), prob[i][j-1]));

    return res;
}

int diag(int i, int j){
    ll res = 0;
    res = add(res, mul(add(add(1, -res), MOD), prob[i+1][j+1]));
    res = add(res, mul(add(add(1, -res), MOD), prob[i-1][j-1]));
    res = add(res, mul(add(add(1, -res), MOD), prob[i-1][j+1]));
    res = add(res, mul(add(add(1, -res), MOD), prob[i+1][j-1]));

    return res;
}

int main(){
    ll n, m, d1, d2, d3;
    cin>>n>>m>>d1>>d2>>d3;

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>grid[i+1][j+1];
            if(grid[i+1][j+1] == '?') prob[i+1][j+1] = inv(2);
            if(grid[i+1][j+1] == 'V') prob[i+1][j+1] = 1;
        }
    }

    ll res = 0;

    for(int i =1; i<=n; i++){
        for(int j =1; j<=m; j++){
            ll aux = 0;

            ll a = prob[i][j];
            ll sobra = add(add(1, -prob[i][j]), MOD);
            
            ll b = mul(sobra, adj(i, j));
            sobra = mul(sobra, add(add(1, -adj(i, j)), MOD));

            ll c = mul(sobra, diag(i, j));

            aux = add(aux, mul(a, d1));
            aux = add(aux, mul(b, d2));
            aux = add(aux, mul(c, d3));

            res = add(res, aux);
        }
    }

    cout<<res<<"\n";

    return 0;
}