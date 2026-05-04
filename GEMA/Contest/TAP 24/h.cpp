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
#define pb push_back

const int maxn = 2e5+4;
const int inf = 1e9+3;

ll n, m;

struct Ev {
    int x, abre, y0, y1, id;

    bool operator<(const Ev& ot) const {
        return make_tuple(x, y0, y1, id, abre) < make_tuple(ot.x, ot.y0, ot.y1, ot.id, ot.abre);
    }
};

vi g[maxn];
ll tsz[maxn], tsoma[maxn], val[maxn];

void dfs1(int v) {
    tsz[v] = val[v];
    tsoma[v] = 0;
    for(int u: g[v]) {
        dfs1(u);
        tsz[v] += tsz[u];
        tsoma[v] += tsoma[u] + tsz[u];
    }
}

ll totresp;

void dfs2(int v, ll r) {
    totresp += r * val[v];
    //cerr << "reroot " << v  << "  r = " << r << endl;

    for(int u: g[v]) {
        ll r2 = r + tsz[0] - 2 * tsz[u];
        dfs2(u, r2);
    }
}

void solve(){
    cin >> n >> m;

    vector<Ev> evs;
    rep(i, 1, n+1) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        
        evs.pb(Ev{.x = x0, .abre = 1, .y0 = y0, .y1 = y1, .id = i});
        evs.pb(Ev{.x = x1, .abre = 0, .y0 = y0, .y1 = y1, .id = i});
    }

    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        evs.pb(Ev{.x = x, .abre = 10, .y0 = y, .y1 = y, .id = -1});
    }

    sort(all(evs));

    set<Ev> cur;
    Ev base = Ev{.x = 0, .abre = 0};
    for(auto ev: evs) {
        if(ev.abre) {
            Ev query = Ev{.x = 0, .abre = 0, .y0 = ev.y0, .y1 = -1, .id = -1};
        
            bool fl = 0;
            auto it = cur.upper_bound(query);
            if(it != cur.begin()) {
                it--; 
                auto dt = *it;

                //cerr << "Achou " << ev.abre << " ev.y0 = " << ev.y0 << " dt.y1 = " << dt.y1 << endl;
                if(dt.y1 > ev.y0) {
                    //cerr << "Pegou id = " << dt.id << "\n";
                    if(ev.abre == 10) 
                        val[dt.id]++;
                    else
                        g[dt.id].pb(ev.id);
                    fl = 1;
                }
            }

            if(!fl) {
                if(ev.abre == 10)
                    val[0]++;
                else
                    g[0].pb(ev.id);
            }
            
            if(ev.abre != 10) {
                Ev sla = ev;
                sla.x = 0;
                sla.abre = 0;
                cur.insert(sla);
            }
        } else {
            Ev sla = ev;
            sla.x = 0;
            sla.abre = 0;
            cur.erase(sla);
        }
    }

    dfs1(0);
    dfs2(0, tsoma[0]);
    
    rep(i, 0, n+1) {
        //cerr << "v = " << i << " val = " << val[i] << " tsz = " << tsz[i] << " tsoma = " << tsoma[i]  << "\n";
        //for(auto j : g[i]) cout << j << " ";
        //cout << endl;
    }

    //cerr << "totresp = " << totresp << endl;
    long double res = totresp;
    res /= m*m;

    printf("%.16Lf\n", res);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}