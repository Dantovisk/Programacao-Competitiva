#include <bits/stdc++.h> //TA ERRADO!
#define MAXN 300010
#define int long long

using namespace std;

int v[MAXN];
const int mod = 998244353;

int mexp(int b, int e){
    if(e==1) return b;
    if(e==0) return 1;

    int k = mexp(b, e/2);
    if(e%2) return (((k*k)%mod)*b)%mod;
    return (k*k)%mod;
}

int inv(int k){
    return mexp(k, mod-2);
}

int mul(int a, int b){ 
    return ((a*b)%mod);
}

int32_t main(){
    int n, k;
    cin>>n>>k;
    vector<int> pref(2*n+1);
    pref[0] = 0;

    for(int i =1; i<=n; i++){
        cin>>v[i];
        pref[i] = pref[i-1] + v[i];
    }
    for(int i =1; i<=n; i++){
        pref[i+n] = pref[i+n-1] + v[i];
    }

    int circ = pref[n];

    int ovos = mexp(k, n);

    if(n <= 2 || (circ % 2)){
        cout<<ovos<<"\n";
        return 0;
    }
    
    int half = circ/2;
    int cont = 0;
    for(int i =1; i<=n; i++){
        auto ptr = lower_bound(pref.begin(), pref.end(), half+pref[i-1]);
        if(ptr == pref.end() || half+pref[i-1] != *ptr) continue;
        cont++;
    }
    //cout<<cont<<"\n";
    int x = cont/2;
    int y = n - cont;

    int resp= 0;
    int comb = 1;
    int arranj = 1;

    for(int i =0; i <= min(k, x); i++){
        int atual = mul(k-i, k-i-1);
        atual = mexp(atual, x-i);
        atual = mul(atual, mexp(k-i, y));

        atual = mul(atual, mul(comb, arranj));

        cout<<"i = "<<i<<": "<<atual<<"\n";
        resp += atual;
        resp %= mod;


        int u = i+1;
        comb = mul(comb, mul(x-u, inv(u)));

        arranj = mul(comb, inv(k-u));

        cout<<arranj<<" "<<comb<<"\n";
        
    }

    
    cout<<resp<<"\n";
}