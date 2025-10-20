#include <bits/stdc++.h> // Spoj - Square-free integers    
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const int MAX = 1e7+1;
// const ll mod = 1e9+7;
const ll mod = 1000000007, LIM = 5100; ///include-line

int cont [26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    cin>>a;
    int n = a.size();

    for (auto c : a) cont[c-'a'] ++;

    sort(cont, cont +26);
    reverse(cont, cont + 26);

    ll* inv = new ll[LIM] - 1; inv[1] = 1;
    rep(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;

    ll* fac = new ll[LIM] - 1; fac[1] = 1;
    rep(i,2,LIM) fac[i] = (fac[i-1] * (ll)i) % mod;

    ll res = 0;

    int sinal = -1;
    for(int i =1; i<=n; i++){
        sinal*= -1;

        ll num = 1, den = 1;

        ll sominha;
        for(int j = 0; j < 26; j++){
            if(cont[j]>= i){
                sominha += j-i;
                if(cont[j] > i) den *= inv[cont[j-i]];

                
            }
        }
    }

}