#include <bits/stdc++.h>    
using namespace std;      

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define tii tuple<int, int, int>

const int MAX = 1e3+ 15;
const ll mod  = 1e9+7;

const int MAX_PR = 33'000'005;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim=33'000'002) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

set <ll> factors;
ll a[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, d;
    cin>>m>>n>>d;

    vi primo = eratosthenesSieve();

    for(int i =0; i<n; i++){
        cin>>a[i];
        ll u = a[i];
        for(auto p: primo){
            if(u%p == 0) factors.insert(p);
            while(u%p == 0){
                u/= p;
            }   

            if(u == 1) break;
        }
        if(u > 1) factors.insert(u);
    }

    for(int i =0; i<d; i++){
        int a, b, c;
        cin>>a>>b>>c;
    }

    for(auto f: factors) cout<<f<<" ";
    return 0;
}