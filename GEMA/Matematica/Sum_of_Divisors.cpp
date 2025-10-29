#include <bits/stdc++.h> // CSES - Sum of Divisors
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_PR = 1'000'100;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim = 1e6+2) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

const int MAX = 1e6+5;

ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;

    vi primos = eratosthenesSieve();

    ll resp = 0;
    ll i;
    for(i =1; i*i <=n; i++){ 
        resp += (n/i)*(i);
        resp %= mod;
        // ll inv = n/i;
        // resp += (ll)(n/inv)*(inv);
        // resp %= mod;
    }
    //vai de i+1, até n;
    if(i < n) {
        __int128_t aux = (i + n);
        aux *= (n-i+1);
        aux /= 2LL;
        aux %= (__int128_t)mod;

        resp += aux;
        resp %=mod;
    }

    cout<<resp<<"\n";

}