#include <bits/stdc++.h>
#define MAXN 100010
#define int long long int
#define pii pair<int,int>

const int M1 = 1e9 + 9;
const int M2 = 1e9 + 7;
const int B = 9973;

using namespace std;

string st;
string maxstr = "-1";
int hash1[MAXN], hash2[MAXN];
int pot1[MAXN], pot2[MAXN];

void hashing(string a, int hash[], int mod){
    int n = a.length();
    hash[0] = a[0];

    for(int i = 1; i<n; i++){
        hash[i] = (hash[i-1]*B + (int)a[i]) % mod;
    }
}

int gethash(int hash[], int l, int r, int pot[], int mod){
    if(l==0) return hash[r];
    return ((hash[r] - hash[l-1] * pot[r-l+1])%mod + mod)%mod;
}

bool solve(int m){
    int n = st.length();

    unordered_set <int> vis;
    string b = "";
    //cout<<"m = "<<m<<"\n";

    for(int i = 0; i<= n-m; i++){
        int j = i + m - 1;
        int k1 = gethash(hash1, i, j, pot1, M1);
        int k2 = gethash(hash2, i, j, pot2, M2);
        int kf = (k1<<31)+k2;

        if(vis.find(kf) != vis.end()){
            maxstr = st.substr(i, m);
            //cout<<maxstr<<" encontrado\n";
            return true;
        }

        vis.insert(kf);
    }

    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>st;
    int n = st.length();

    pot1[0] = pot2[0] = 1;
    for(int i =1; i<=n; i++){
        pot1[i] = (pot1[i-1] * B) % M1;
        pot2[i] = (pot2[i-1] * B) % M2;
    }

    hashing(st, hash1, M1);
    hashing(st, hash2, M2);

    int l = 1, r = n; 
    
    while(l < r){
        int mid = (l+r)/2;
        
        if(solve(mid)){
            l = mid + 1; 
        } else {
            r = mid;
        }
    }

    cout<<maxstr;

    return 0;
}