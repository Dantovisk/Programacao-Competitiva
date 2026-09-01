#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
#define ff first
#define ss second
#define pb push_back

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
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

const int maxn = 2e5+4;
const ll inf = 1e15+3;
const int sqr = 600;

int sig(ll a){
    if(a > 0) return 1;
    if(a < 0) return -1;
    return 0;
}

ll divceil(ll base, ll m){
    ll num = base/m;
    ll resto = base%m;
    if(resto != 0 and base > 0)
        num++;
    return num;
}

vector<RMQ<ll>> rmq;
vector<vector<vi>> psum;
vector<vector<vi>> intmx;

ll isum(int l, int r, int x, int y){
    if(l > r) return 0;
    if(x > y) return 0;

    ll res = psum[l][r][y];
    if(x) res -= psum[l][r][x-1];

    return res;
}

void solve(){
    ll n, m; 
    cin>>n>>m;
    vi v(n-m+1);

    rep(i, 0, n-m+1) cin>>v[i];
    int q; cin>>q;

    if(m < sqr){
        rep(i, 0, m){
            // cout<<"rmq("<<i<<"): \n";
            vector<ll> aux = {0};
            ll acum = 0;
            for(int j = i; j < n-m; j+= m){
                acum += v[j+1]-v[j];
                aux.push_back(acum);
                // cout<<acum<<" ";
            }
            rmq.emplace_back(aux);
            // cout<<"\n";
        }
    }
    else{
        // mx[l][r][j] o maximo no intervalo [l, r] dos caras i%m=j 
        // intmx.resize(n/m+1, vector<vi>(n/m+1, vi(m+1, -inf)));
        psum.resize(n/m+1, vector<vi>(n/m+1, vi(m+1, -inf)));
    
        rep(i, 0, m){
            vector<ll> aux = {0};
            ll acum = 0;
            for(int j = i; j < n-m; j+= m){
                acum += v[j+1]-v[j];
                aux.push_back(acum);
            }
        
            rep(l, 0, sz(aux)){
                ll mx = -inf;
                rep(r, l, sz(aux)){
                    mx = max(mx, aux[r]);
                    psum[l][r][i] = mx;
                }
            }
        }

        rep(l, 0, n/m+1){
            rep(r, l, n/m+1){
                rep(i, 1, m){
                    psum[l][r][i] += psum[l][r][i-1];
                }
            }
        }
    }

    rep(xd, 0, q){
        int l, r;
        cin>>l>>r;
        l--;
        r--;

        if(r - l + 1 < m){
            cout<<"unbounded\n";
            continue;
        }
        
        if(m < sqr){
            ll base = v[0];

            //qual mod eh
            rep(i, 0, m){
                int l1 = (l+m-1-i)/m;
                int r1 = (r-i)/m;
                // cout<<"query "<<xd<<": ["<<l1<<", "<<r1<<"] = ";
                if(r1  < l1) {
                    continue;
                }
                base += rmq[i].query(l1, r1+1);
            }
            // faz o ceil para negativo também
            cout<<divceil(base, m)<<"\n";
        }
        else{
            ll base = v[0];
            int x = l % m;
            int y = r % m;


            int l1 = l/m, r1 = r/m;

            if(x <= y){
                base += isum(l1+1, r1, 0, x-1);
                base += isum(l1, r1, x, y);
                base += isum(l1, r1-1, y+1, m-1);
            }else{
                base += isum(l1+1, r1, 0, y);
                base += isum(l1+1, r1-1, y+1, x-1);
                base += isum(l1, r1-1, x, m-1);
            }
            cout<<divceil(base, m)<<"\n";
        }
    }
    

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    solve();
}