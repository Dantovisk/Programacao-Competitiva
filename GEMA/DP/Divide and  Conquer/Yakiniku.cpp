#include <bits/stdc++.h>  //usaco

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 5e3+7;

int n, m;

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

ll v[MAX];

//Custo acumulado até j;
ll sum [MAX];

const ll inf = 1e16 + 67;

vector <RMQ<int>> maxis;
int rot = 0;

//Procura de [st, ed], sabendo que o maxCost pode estar de [l, r]
ll solve(int st, int ed, int l, int r){
    int mid = (st + ed)/2;

    pair<long long, int> best = {0, -1};

    for(int i = l; i <= min(mid, r); i++){
        // cout<<"i/min: "<<i<<" "<<min(mid, r)<<"\n";
        ll cost = -(sum[mid] - sum[i]);
        // cout<<"c: "<<cost<<" -> ";

        for(int j =0; j<m; j++){
            cost+= maxis[j].query(i, mid+1);
        }
        // cout<<cost<<"\n";
        best = max(best, {cost, i});

    }
    if(st == ed) return best.first;

    return max({best.first, 
        solve(st, mid, l, best.second), 
        solve(mid+1, ed, best.second, r)});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    
    for(int i =1; i<n; i++){
        cin>>v[i];
        sum[i] = sum[i-1] + v[i];
    }

    vector <vi> x(m, vi(n));
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>x[j][i];
        }
    }

    for(int j =0; j<m; j++){
        maxis.emplace_back(x[j]);
    }
        

    cout<<solve(0, n-1, 0, n-1)<<"\n";
}