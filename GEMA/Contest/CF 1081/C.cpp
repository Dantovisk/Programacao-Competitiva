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

/**
 * Author: Johan Sannemo, pajenegod
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Range Minimum Queries on an array. Returns
 * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
 * Usage:
 *  RMQ rmq(values);
 *  rmq.query(inclusive, exclusive);
 * Time: $O(|V| \log |V| + Q)$
 * Status: stress-tested
 */

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


void solve(){
    ll n, h, k;
    cin>>n>>h>>k;

    vi v(n), pref(n+1, 0);
    ll sum = 0;
    rep(i, 0, n){
        cin>>v[i];
        sum += v[i];
        pref[i+1] = pref[i] + v[i];
    }

    ll res = 0;
    ll qt = h/sum, resto = h%sum;

    res = qt*(n) + k * (qt - (resto == 0? 1: 0));

    if(resto == 0){
        cout<<res<<"\n";
        return;
    }
    if(resto <= v[0]){
        cout<<res+1<<"\n";
        return;
    }

    int best = n;

    rep(i, 0, n){
        if(pref[i+1] >= resto) {
            best = i+1;
            break;
        }
    }

    RMQ rmq(v);

    for(int i = 1; i<n; i++){
        int l = 0, r = i;
        while(l < r){
            int mid = (l+r)/2;

            ll curr =  pref[mid+1] + v[i] - rmq.query(0, mid+1);

            if(curr >= resto){
                best = min(best, mid+1);
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
    }

    cout<<res + best<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}