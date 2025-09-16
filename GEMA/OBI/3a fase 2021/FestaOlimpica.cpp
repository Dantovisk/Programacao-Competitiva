#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxn = 10000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int m;
    cin>>n>>m;

    vector<ll> v (1e4+2);
    vector<ll> f (m);
    for(int i =1; i<= maxn; i++){
        v[i] = i;
    }

    for(int i =0; i<m; i++) cin>>f[i];

    for(int i =m-1; i>=0; i--){
        int fac = f[i];

        for(int j =1; j<=maxn; j++){
            if(v[j] > n) break;
            v[j] += (v[j]-1LL)/(fac-1LL);
        }
    }

    for(int i = 1; i<=maxn; i++){
        if(v[i] <= n) cout<< v[i]<<"\n";
        else break;
    }


}