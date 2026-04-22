#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int MAX = 1e5+7;
const int inf = 1e9+7;
int lims = 1e8+67;

const int MAX_PR = 100'000'100;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

vi primes;

void solve(){
    int n; 
    cin>>n;

    vi v(n+2, 1), b(n+2, 1), vai(n+2), a(n+2);
    rep(i,1, n+1) cin>>v[i];

    // int gcd = v[0];
    // rep(i, 0, n-1) gcd = __gcd(v[i], v[i+1]);

    vector<vi> dp(n+2, vi(2, 0));


    rep(i, 1, n+1) cin>>b[i];

    a = v;

    

    int ct = 0;
    rep(i, 1, n+1){
        // if(b[i] % gcd == 0 && b[i] / gcd > 1){
        //     ct++;
        // }
        int l = v[i] / (__gcd(v[i-1], v[i]));
        int r = v[i] / (__gcd(v[i+1], v[i]));
        // cout<<i<<" -: ";
        // cout<<l<<" "<<r<<"\n";
        if(__gcd(l, r) > 1 && b[i] >= (v[i]/__gcd(l, r))) {
            ct++;
            a[i] = (v[i]/__gcd(l, r));
        }
        else{
            vai[i] = 1;
        }
    }

    // cout<<"ct deu: "<<ct<<"\n";

    rep(i, 1, n+1){
        if(!vai[i]) continue;
        if(b[i]/a[i] <= 1) continue;

        // cout<<"vamo tentar no "<<i<<"\n";
        auto ptr = upper_bound(all(primes), b[i]/a[i]);
        ptr--;
        int deu = 1;

        while(__gcd(*ptr, (a[i-1]/__gcd(a[i-1], a[i]))) != 1 or __gcd(*ptr, a[i+1]/__gcd(a[i+1], a[i])) != 1 ){
            if(ptr == primes.begin()){
                deu = 0; break;
            }
            ptr--;
        }

        if(deu){
            a[i] *= *ptr;
            ct++;
            // cout<<"deu\n";

        }
    }

    cout<<ct<<"\n";


}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    primes  = eratosthenesSieve(lims);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}