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

const int maxn = 1e5+4;
const int inf = 1e9+3;

int z = -1;
int x = -1;

int par[maxn], cic[maxn];
vi adj[maxn];

map <pii, int> mp;

int dfs(int u){
    int deu = 0;
    for(auto v: adj[u]){
        if(par[u] == v) continue;
        // cout<<"vendo o "<<v<<"\n";
        if(v == 1 and z == -1){
            // cout<<"achei!!!\n";
            cic[u] = 1;
            z = u;
            deu = 1;
            continue;
        }

        if(par[v] != -1){
            continue;
        }

        par[v] = u;

        if(dfs(v)) {
            cic[u] = 1;
            deu = 1;
        }
    }

    return deu;
}


int par2[maxn];
int dfs2(int u){
    // cout<<"to "<<u<<"\n";
    for(auto v: adj[u]){
        // cout<<"olhei "<<v<<"\n";
        if(par2[u] == v) continue;
        if(v == 1 and x == -1) {
            x = -2;
            par2[v] = u;
            return 1;
        }
        if(cic[v] and x == -1){
            x = v;
            par2[v] = u;
            return 1;
        }
        if(par2[v] != -1) continue;

        par2[v] = u;
        if(dfs2(v)) return 1;
    }

    return 0;
}

void solve(){
    int n, m;
    cin>>n>>m;

    memset(par, -1, sizeof(par));
    memset(par2, -1, sizeof(par2));

    vector<pii> ed;

    rep(i, 0, m){
        int a, b;
        cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);

        ed.pb({a, b});

        mp[{a, b}] = i;
        mp[{b, a}] = i;
    }

    par[1] = 1;
    // pred[1] = 1;
    dfs(1);

    if(z == -1){
        cout<<"No solution\n";
        return;
    }

    // 1: ta no ciclo
    if(cic[0]){
        vi vis(m, 0);
        int a = 0;
        while(a != 1){
            cout<<mp[{a, par[a]}]<<" ";
            vis[mp[{a, par[a]}]] = 1;
            a = par[a];
        }
        cout<<"\n";

        rep(i, 0, m){
            if(!vis[i]) cout<<i<<" "; 
        }
        cout<<"\n";


        a = 0;
        while(a != 1){
            cout<<"MOVE "<<par[a]<<"\n";
            a = par[a];
        }
        cout<<"DONE\n";

        cout<<"MOVE "<<z<<"\n";
        a = z;
        while(a != 0){
            cout<<"MOVE "<<par[a]<<"\n";
            a = par[a];
        }
        cout<<"DONE\n";
        return;
    }

    dfs2(0);
    par[0] = 0;

    // cout<<"X = "<<x<<"\n";

    // 2: ta fora ciclo
    if(x > -1){
        vi vis(m, 0);
        int a = x;
        while(a != 0){
            int u = mp[{a, par2[a]}];
            vis[u] = 1;
            cout<<u<<" ";
            a = par2[a];
        }
        a = x;
        while(a != 1){
            int u = mp[{a, par[a]}];
            vis[u] = 1;
            cout<<u<<" ";
            a = par[a];
        }

        cout<<"\n";

        rep(i, 0, m){
            if(!vis[i]) cout<<i<<" "; 
        }
        cout<<"\n";


        vi res;
        a = x;
        while(a != 0){
            res.push_back(a);
            a = par2[a];
        }
        reverse(all(res));
        for(auto k: res) cout<<"MOVE "<<k<<"\n";

        int last = 0;
        for(auto k: res){
            cout<<"DROP "<<mp[{last, k}]<<"\n";
            last = k;
        }

        a = x;
        while(a != 1){
            cout<<"MOVE "<<par[a]<<"\n";
            a = par[a];
        }

        cout<<"DONE\n";

        cout<<"MOVE "<<z<<"\n";
        a = z;
        while(a != x){
            cout<<"MOVE "<<par[a]<<"\n";

            a = par[a];
        }
        cout<<"GRAB\n";

        while(a != 0){
            cout<<"MOVE "<<par2[a]<<"\n";

            a = par2[a];
        }

        cout<<"DONE\n";
        return;
    }
    // 3 : fora da subarvore
    else{
        vi vis(m, 0);

        int a = 1;
        while(a != 0){
            int u = mp[{a, par2[a]}];
            vis[u] = 1;
            cout<<u<<" ";
            a = par2[a];
        }

        a = z;
        while(a != 1){
            int u = mp[{a, par[a]}];
            vis[u] = 1;
            cout<<u<<" ";
            a = par[a];
        }

        cout<<"\n";

        rep(i, 0, m){
            if(!vis[i]) cout<<i<<" "; 
        }
        cout<<"\n";


        vi res;
        a = 1;
        while(a != 0){
            res.push_back(a);
            a = par2[a];
        }
        reverse(all(res));
        
        for(auto k: res) cout<<"MOVE "<<k<<"\n";

        vi res2;
        a = z;
        while(a != 1){
            res2.push_back(a);
            a = par[a];
        }
        reverse(all(res2));
        
        for(auto k: res2) cout<<"MOVE "<<k<<"\n";

        int last = 0;
        for(auto k: res){
            cout<<"DROP "<<mp[{last, k}]<<"\n";
            last = k;
        }
        a = z;
        while(a != 1){
            cout<<"MOVE "<<par[a]<<"\n";
            a = par[a];
        }

        cout<<"DONE\n";

        cout<<"MOVE "<<z<<"\n";
        cout<<"GRAB\n";
        cout<<"MOVE "<<1<<"\n";

        a = 1;
        while(a != 0){
            cout<<"MOVE "<<par2[a]<<"\n";
            a = par2[a];
        }

        cout<<"DONE\n";
        return;
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    while(t--) solve();
}

/*
Caso 1:
5 5
1 2
2 3
3 0
0 4
4 1

Caso 2:
6 6
1 2
2 3
3 4
4 5
5 1
0 3

Caso 3:
5 5
0 1
1 2
2 3
3 4
4 1

Caso quebrador: 
4 4
1 0
0 2
2 3
3 0
*/