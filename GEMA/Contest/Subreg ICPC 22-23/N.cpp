#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
//#define LOCAL 
#define int ll
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

const ll maxn = 2e5 + 10;
const ll inf = LLONG_MAX;



void solve() {

	int n; cin >> n;
	multiset<int> m,bag;

	vi frente(n), verso(n);
	for(int i = 0; i < n; i++){
		cin >> frente[i];	}
	for(int i = 0; i < n; i++){
		cin >> verso[i];
	}

	int k,l; cin >> k >> l;
	ll sum = 0;

	for(int i = 0; i < k; i++){
		// adiciona da frente
		sum += frente[i];

		// bota na fila 
		
		int vs = verso[i];

		sum += vs;
		m.insert(vs);

		// controla a fila
		if(i >= l ){
			auto it = m.begin();
			sum -= *it;


			m.erase(it);
			bag.insert(*it);
		}

	
	}
	ll mx = sum;

	for(int j = 1; j <= k; j++){
		int ad = n-j;
		int del = k-j;
		
		sum += frente[ad];
		sum -= frente[del];
		
		dbg(ad,del);
		// tira o del da l, se ele tiver

		int vd = verso[del];
		auto itd = m.find(vd);
		if(itd != m.end()){
			sum -= vd;
			m.erase(itd);
		}else{
			auto itd = bag.find(vd);
			bag.erase(itd);
		}

		int va = verso[ad];

		if(m.size() == 0){
			m.insert(va);
			sum += va;
		}else if(va > (*(m.begin()))){
            m.insert(va);
			sum += va;
        }
        else{
			bag.insert(va);
		}

		if(m.size () > l){
			auto it = m.begin();
			sum -= *it;
			m.erase(it);
			bag.insert(*it);
		}else if(m.size() < l){
			auto it = bag.end();
			it--;
			sum += *it;
			
			bag.erase(it);
			m.insert(*it);
		}

		
		// limpa a fila, se 

		smax(mx,sum);
	}

	cout << mx << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    int t = 1;
   

    while(t--) solve();
}