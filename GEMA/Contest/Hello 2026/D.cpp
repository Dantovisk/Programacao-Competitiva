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

const int MAXN = 2e5+3;

int par[MAXN];

void dfs(int u, int p, vector<vi>& adj, vi & prof, vi & goat, vector<vi>& ls){
    int ct = 0;
    ls[prof[u]].push_back(u);
    par[u] = p;

    for(auto v : adj[u]){
        if(v == p) continue;

        prof[v] = prof[u] + 1;
        dfs(v, u, adj, prof, goat, ls);
        ct++;
    }

    goat[prof[u]] = max(goat[prof[u]], ct);
}

void solve(){
    int n;
    cin>>n;

    vector<vi> adj(n+1);
    vi prof(n+1, 0);
    vi cnt(n+1, 0);
    vi goat(n+1, 0);

    vector<vi> ls(n+1);
    vector<vi> resp;

    vi chose(n+1, -1);

    rep(i, 1, n){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0, adj, prof, goat, ls);

    rep(i, 1, n+1){
        cnt[prof[i]]++;
    }

    int res = 1;
    resp.push_back({1});
    chose[1] = 0;

    rep(i, 1, n){
        if(cnt[i] == 0) break;
        set<int> pos;
        set<int> pais;

        //aqui sera
        for(auto xd: ls[i-1]){
            if(adj[xd].size() > 1 + (par[xd] == 0 ? -1 : 0))pais.insert(chose[xd]);
        }
        for(int i=0; i<min(res, 2*cnt[i]+2); i++) pos.insert(i);

        int ultimo = -1;
        
        if(goat[i-1] < cnt[i]){
            res += max(0, cnt[i]- res);
        } else{
            res += max(0, cnt[i] -res + 1);
        }

        for(auto x: ls[i]){
            if(ultimo == -1){
                ultimo = chose[par[x]];
            }
            auto ptr = pais.begin();
            int foi = 0;
            while(ptr != pais.end()){
                if(pais.size() == 2){
                    auto ptr2 = ptr;
                    ptr = pais.begin();
                    if((*ptr) == chose[par[x]]){
                        ptr++;

                        foi = 1;
                        resp[(*ptr)].push_back(x);
                        chose[x] = (*ptr);
                        if(pos.find(*ptr) != pos.end()) pos.erase(*ptr);
                        pais.erase(ptr);
                        break;
                    }
                    ptr++;
                    if((*ptr) == chose[par[x]]){
                        ptr--;
                        foi = 1;
                        resp[(*ptr)].push_back(x);
                        chose[x] = (*ptr);
                        if(pos.find(*ptr) != pos.end()) pos.erase(*ptr);
                        pais.erase(ptr);
                        break;
                    }
                    ptr = ptr2;
                }
                

                if((*ptr) != chose[par[x]] && ((*ptr) != ultimo || pais.size() == 1)){
                    foi = 1;
                    resp[(*ptr)].push_back(x);
                    chose[x] = (*ptr);
                    if(pos.find(*ptr) != pos.end()) pos.erase(*ptr);
                    pais.erase(ptr);
                    break;
                }
                ptr++;
            }
            if(foi) continue;

            ptr = pos.begin();
            while(ptr != pos.end()){
                if((*ptr) != chose[par[x]]){
                    foi = 1;
                    resp[(*ptr)].push_back(x);
                    chose[x] = (*ptr);
                    if(pais.find(*ptr) != pais.end()) pais.erase(*ptr);
                    pos.erase(ptr);
                    break;
                }
                ptr++;
            }
            if(!foi) {
                chose[x] = resp.size();
                resp.push_back({x});
            }
        }
    }
    
    cout<<res<<"\n";
    for(auto y: resp){
        cout<<y.size()<<" ";
        for(auto x: y) cout<<x<<" ";
        cout<<"\n";
    }

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}