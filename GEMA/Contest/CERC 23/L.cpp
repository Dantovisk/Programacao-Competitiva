#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;

	HashInterval(string str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

const int maxn = 670; // haha
const int inf = 1e9+3;

vector <tii> adj[maxn], adjT[maxn];
int vis[maxn];
vector<int> ts;

void dfsTS(int u){
    vis[u] = 1;
    for(auto [v, sla, sla2]: adj[u]){
        if(!vis[v]) dfsTS(v);
    }
    ts.pb(u);
}

vector<pii> segs[maxn];
int da[maxn], par[maxn];
string a; 
HashInterval ha("a");

ll getsz(vector<pii>&x){
    ll res = 0;
    for(auto [sla, s] : x){
        res += s;
    }
    return res;
}

char getChar(vector<pii>&x, ll k){
    for(auto [st, siz] : x){
        if(siz < k){
            k-= siz;
        }
        else{
            return a[st-2 + k];
        }
    }
    return ' ';
}

bool minst2(vector<pii>&x, vector<pii>&y){
    if(sz(x) == 0) return true;
    if(sz(y) == 0) return false;
    ll sx = getsz(x), sy = getsz(y);

    ll match = 0;
    int idx = 0, idy = 0;
    int foix = 0, foiy = 0;

    while(match < sx and match < sy){
        auto [stx, szx] = x[idx];
        auto [sty, szy] = y[idy];

        int pode = min(szx - foix, szy - foiy);

        if(ha.hashInterval(stx - 1 + foix, stx - 1 + foix + pode) == ha.hashInterval(sty - 1 + foiy, sty - 1 + foiy + pode)){
            match += pode;
            foix += pode;
            foiy += pode;
            if(foix == szx){
                foix = 0;
                idx++;
            }
            if(foiy == szy){
                foiy = 0;
                idy++;
            }
        }
        else break;
    }

    if(match == min (sx, sy)){
        return sx < sy;
    }

    auto [stx, szx] = x[idx];
    auto [sty, szy] = y[idy];

    ll best = 0;
    ll l = 1, r = min(szx - foix, szy - foiy) + 1;

    while(l < r){
        ll m =(l+r)/2LL;

        if(ha.hashInterval(stx - 1 + foix, stx - 1 + foix + m) == ha.hashInterval(sty - 1 + foiy, sty - 1 + foiy + m)){
            best = m;
            l = m+1;
        }
        else{
            r = m;
        }
    }

    if(best + match == min(sx, sy)){
        return sx < sy;
    }
    // cout<<getChar(x, best+1)<< " < " <<getChar(y, best+1)<<"\n";
    return getChar(x, best + match + 1) < getChar(y, best + match +1);
}

void solve(){
    int n, m, d, s;
    cin>>n>>m>>d>>s;

    cin>>a;

    ha = HashInterval(a);

    rep(i, 0, m){
        int u, v, st, siz;
        cin>>u>>v>>st>>siz;

        adj[u].push_back({v, st, siz});
        adjT[v].push_back({u, st, siz});
    }

    dfsTS(s);
    
    rep(i, 1, n+1){
        memset(da, 0, sizeof(da));

        rep(j, 1, n+1)
            segs[j].clear();

        da[i] = 1;
        par[i] = s;

        for(auto u : ts){
            if(!da[u]) continue;

            for(auto [v, st, siz] : adjT[u]){

                vector<pii> aux = {{st, siz}};
                for(auto y: segs[u]) aux.push_back(y); 
                
                // cout<<"vendo de "<<u<<" -> "<<v<<"\n";

                if(!da[v]){
                    da[v] = 1;
                    segs[v] = aux;
                    par[v] = u; 

                    continue;
                }

                if(minst2(aux, segs[v])){
                    segs[v] = aux;
                    par[v] = u; 
                }
            }
        }

        if(!da[s]){
            cout<<"0\n";
            continue;
        }

        vi res = {s};
        int u = s;
        while(u != i){
            u = par[u];
            res.pb(u);
        }
        cout<<res.size()<<" ";
        for(auto x: res) cout<<x<<" ";
        cout<<"\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    while(t--) solve();
}