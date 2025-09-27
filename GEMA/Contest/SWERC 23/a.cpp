#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define int long long
#define pb push_back
#define ff first
#define ss second 
#define all(a) (a).begin(), (a).end()
#define smin(a,b) a = min(a,b)
#define smax(a,b) a = max(a,b)
#define vi vector<int>
#define sz(a) (a).size()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.ff << ", " << p.ss << ")"; }

#ifdef LOCAL
void dbg_out() { cerr << endl; }
template<typename H, typename... T> void dbg_out(H h, T... t) { cerr << " " << h; dbg_out(t...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const ll maxn = 1e5 + 10;
const ll inf = LLONG_MAX;
pii res = {0,1};
vi h(maxn);

pii red(int a, int b){
	int k = __gcd(a, b);
    return {a/k, b/k};
}
pii calc(pii a, pii b) {
	
	ll h1 = min(a.ff, b.ff);
    ll h2 = max(a.ff, b.ff);

    ll htrue;
    if(a.ff>b.ff){
        htrue = a.ff - h[a.ss+1];
    }else{
        htrue = b.ff - h[b.ss-1];
    }

    ll k = b.ss-a.ss;



    ll den = htrue, num = k*h2 - (h2 - h1);
    cout<<(h2-h1)<<"/"<<h2<<"\n";

    return red(num*1000LL, den*1000LL);
}

void solve() {

	int n; cin >> n;

	for(int i = 0; i < n; i++) cin >> h[i];

	set <pii> esq; //esq.insert({h[0],0});


	
	for(int i = 1; i < n; i++){
		if(h[i] > h[i-1]){
			if(sz(esq) == 0) continue; 
			auto it = esq.upper_bound({h[i], 0}); // quando tem uma montanha maior na lista
			if(it == esq.end()) it--; // tenta pegar a a maior de todas
			
			pii xd = calc(*it,{h[i],i});
            if(res.ff*xd.ss < xd.ff*res.ss) res = xd;
            cout<<i<<": "<<xd.ff<<"/"<<xd.ss<<"\n";
            cout<<(*it).ff<<" "<<(*it).ss<<"\n";

		}else{
			auto it = esq.begin();
			while(it != esq.end() && (*it).ff < h[i-1]){
				esq.erase(it);
				it = esq.begin();
			}

			esq.insert({h[i-1],i-1});
		}
	}

    cout<<res.ff;
    if(res.ss>1){
        cout << "/" << res.ss;
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    int t = 1;
   

    while(t--) solve();
}