#include <bits/stdc++.h>
#define int long long

const int mod = 998244353;

using namespace std;

int n, m;

int sum(int a, int b){return (a+b)%mod;}
int sub(int a, int b){return ((a-b)+mod)%mod;}
int mul(int a, int b){return (a*b)%mod;}

int32_t main(){
    cin>>n>>m;

    int u = (((n*(n+1LL))/2LL)%mod)*(((m*(m+1LL))/2LL)%mod);
    u %= mod;
    //cout<<u<<"\n";

    int k = min(n, m);
    int v = mul(k, mul(n, m));
    //int v = ((k*n)%mod)*(m);
    //v %= mod;

    //v -= ((((((n + m) * (k))%mod)*(k-1LL))%mod)*499122177LL)%mod;
    //v = ((v%mod)+mod)%mod; 

    v = sub(v, mul(499122177LL, mul(sub(k, 1), mul(sum(n, m), k))));

    k--;

    v = sum(v, mul(166374059LL, mul(k+1LL, mul(k, 2LL*k+1LL))));
    //v+= ((((((k*(2LL*k+1LL))%mod)*(k+1LL)))%mod)*166374059LL)%mod;
    //v %= mod;

    //cout<<v<<"\n";
    
    //int r = ((u-v)%mod + mod)%mod;
    int r = sub(u, v);
    cout<<r<<"\n";
}