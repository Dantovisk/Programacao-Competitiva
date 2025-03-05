#include <bits/stdc++.h>
#define MAXN 1000010
#define int long long int

const int M1 = 1e9 + 9;
const int M2 = 1e9 + 7;
const int B = 9973;

using namespace std;

int hasha[MAXN], hasha2[MAXN];
int pot1[MAXN], pot2[MAXN]; //precomputaremos as potencias

void hashing(string a, int hash[], int mod){
    hash[0] = a[0];
    int n = a.length();

    for(int i = 1; i<n; i++){
        hash[i] = (hash[i-1]*B + (int)a[i]) % mod;
    }
}

int gethash(int hash[], int l, int r, int mod, int pot[]){
    if(l==0) return hash[r];
    return ((hash[r] - hash[l-1] * pot[r-l+1]) % mod + mod) % mod;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a; cin>>a;

    int n = a.length();

    hashing(a, hasha, M1);
    hashing(a, hasha2, M2);

    pot1[0] = pot2[0] = 1;
    for(int i=1; i<=n; i++){
        pot1[i] = (pot1[i-1] * B) % M1;
        pot2[i] = (pot2[i-1] * B) % M2;
    }

    for(int i = 1; i<n; i++){
        if(hasha[i-1] == gethash(hasha, n-i, n-1, M1, pot1) &&
        hasha2[i-1] == gethash(hasha2, n-i, n-1, M2, pot2)){
            cout<<i<<" ";
        }
    }

    return 0;
}