#include <bits/stdc++.h>
#define MAXN 1000010
#define int long long int

const int M1 = 1e9 + 9;
const int M2 = 1e9 + 7;
const int B = 9973;

using namespace std;

int hasha[MAXN], hashb[MAXN];
int hasha2[MAXN], hashb2[MAXN];
int pot1[MAXN], pot2[MAXN]; //precomputaremos as potencias

void hashing(string a, int hash[], int mod){
    int n = a.length();
    hash[0] = a[0];

    for(int i = 1; i<n; i++){
        hash[i] = (hash[i-1] * B + (int)a[i]) % mod;
    }
}

int gethash(int hash[], int l, int r, int pot[], int mod){
    if(l == 0) return hash[r];

    //é necessário tirar módulos negativos
    return ((hash[r] - hash[l-1] * pot [r-l+1]) % mod + mod) % mod;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;

    cin>>a>>b;

    int n = a.length();
    int m = b.length();

    hashing(a, hasha, M1);
    hashing(b, hashb, M1);
    hashing(a, hasha2, M2);
    hashing(b, hashb2, M2);
    
    int resp = 0;

    pot1[0] = pot2[0] = 1;
    for(int i=1; i<=n; i++){
        pot1[i] = (pot1[i-1] * B) % M1;
        pot2[i] = (pot2[i-1] * B) % M2;
    }

    for(int i =0; i<=n-m; i++){
        if(gethash(hasha, i, i+m-1, pot1, M1) == hashb[m-1] &&
        gethash(hasha2, i, i+m-1, pot2, M2) == hashb2[m-1]){
            resp++;
        }
    }

    cout<<resp<<"\n";

    return 0;
}