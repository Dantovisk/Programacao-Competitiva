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

vi adj[maxn];
set<int> adj2[maxn];
int par[maxn];
vector<vi> cicles;

void prt(vi a){
    cout<<a[0];
    rep(i, 1, sz(a)) cout<<" -> "<<a[i];
    cout<<"\n";
}

void dfs(int u){
    // cout<<"to "<<u<<"\n";
    for(auto v: adj[u]){
        if(v == par[u]) continue;

        if(par[v]){
            int a = u;
            vi aux = {a};
            rep(i, 0, 9){
                a = par[a];
                aux.push_back(a);
                if(a == v) break;
            }
            if(a == v){
                // prt(aux);
                cicles.push_back(aux);
            }
            continue;
        } 
        par[v] = u;
        dfs(v);
        par[v] = 0;
    }
}



void dfs2(int u){
    // cout<<"to no "<<u<<"\n";
    par[u] = 1;
    for(auto v: adj2[u]){
        if(!par[v]){
            // cout<<u<<" -> "<<v<<"\n";
            dfs2(v);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;

    cicles.clear();
    rep(i, 0, n+2){
        adj[i].clear();
        adj2[i].clear();
        par[i] = 0;
    }

    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[b].pb(a);
        adj[a].pb(b);

        adj2[b].insert(a);
        adj2[a].insert(b);
    }

    par[1] = 1;
    dfs(1);
    par[1] = 0;

    for(auto c: cicles){
        rep(i, 0, n+2){
            par[i] = 0;
        }
        // prt(c);

        rep(i, 0, sz(c)){
            int a = c[i];
            int b = c[(i+1)%sz(c)];

            adj2[a].erase(b);
            adj2[b].erase(a);
        }

        dfs2(1);

        rep(i, 0, sz(c)){
            int a = c[i];
            int b = c[(i+1)%sz(c)];

            adj2[a].insert(b);
            adj2[b].insert(a);
        }

        int da = 1;
        for(auto k: c){
            if(!par[k]){
                da = 0;
                break;
            }
        }
        if(da){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}