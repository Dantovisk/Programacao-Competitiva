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

const int MAX = 1e5+ 15;
const int inf = 1e9+7;

int par[MAX][22], v[MAX];
vi adj[MAX];
vi festa[MAX];
int n, q;

int find(int u, int val){
    for(int i = 19; i>=0; i--){
        if(v[par[u][i]] <= val)  {
            u = par[u][i];
        }
    }
    return u;
}

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int resp[MAX];


void dfs(int u, FT& ft){
    // cout<<"To no "<<u<<"\n";
    for (auto f: festa[u]){
        // cout<<"Add festa "<<f<<"\n";
        ft.update(f, 1);
    }

    resp[u] = ft.query(v[u]+1);

    for(auto k: adj[u]){
        dfs(k, ft);
    }

    for (auto f: festa[u]){
        // cout<<"Remove festa "<<f<<"\n";
        ft.update(f, -1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;

    for(int i =1; i<=n; i++){
        int a, b;
        cin>>a>>b;

        v[i] = a;
        if(i!= 1)adj[b].push_back(i);
        par[i][0] = b;
    }
    par[1][0] = 0;
    v[0] = inf;

    for(int i =1;  i<= 20; i++){
        for(int j = 1; j<=n; j++){
            if(par[j][i-1] == 0) continue;
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    
    for(int i =0; i<q; i++){
        int a, l, r;
        cin>>a>>l>>r;
        a = find(a, r);
        festa[a].push_back(l);
    }
    
    FT ft = FT(MAX);
    dfs(1, ft);

    for(int i =1; i<=n; i++) cout<<resp[i]<<" ";

    return 0;
}