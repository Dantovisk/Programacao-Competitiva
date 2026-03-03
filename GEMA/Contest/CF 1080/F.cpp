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

struct Quad{
    ll a, b, c;
};


// retorna se f > g
bool comp(Quad f, Quad g){
    Quad h = {g.a - f.a, g.b - f.b, g.c - f.c};

    if(h.a == 0){
        return (h.b == 0 && h.c < 0);
    }

    if(h.a > 0) return false;

    ll delta = h.b*h.b - (4LL*h.a*h.c);
    return delta < 0;
}

const int MAX = 3e3+3;
int n; 


void calc(vector<vi>& adj, vector<vi>& adj2, vi& dp){
    vi dg(n, 0);
    rep(i, 0, n){
        for(auto v: adj[i]){
            dg[v]++;
        }
    }
    
    queue<int> q;
    rep(i, 0, n) if(dg[i] == 0) q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto k: adj2[u]){
            dp[u] = max(dp[u], dp[k] + 1);
        }

        for(auto v: adj[u]){
            dg[v]--;
            if(! dg[v]) q.push(v);
        }
    }

}


void solve(){
    cin>>n;

    vector<vi> adj(n), adj2(n);
    vi dp(n, 0), dp2(n, 0);

    vector<Quad> v(n);

    rep(i, 0, n){
        cin>>v[i].a>>v[i].b>>v[i].c;
    }

    rep(i, 0, n){
        rep(j, 0, n){
            //v[i] > v[j]
            if(comp(v[i], v[j])){
                adj[i].push_back(j);
                adj2[j].push_back(i);
            }
        }
    }

    calc(adj, adj2, dp);
    calc(adj2, adj, dp2);

    rep(i, 0, n){
        cout<<dp[i]+dp2[i]+1<<" ";
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}