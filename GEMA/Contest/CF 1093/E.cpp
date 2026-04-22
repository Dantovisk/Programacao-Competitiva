#include <bits/stdc++.h>
using namespace std;

#define double long double

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

#define tii tuple<double, int, int>

const int MAX = 2e5+7;
const double inf = 1e9+7;

vi adj[MAX];
int vis[MAX];
int deg[MAX];
double dp[MAX][2];
string a; 

const double eps = 1e-9;

int start = 0;

void dfs(int u, int p){
    // cout<<"to no "<<u<<"\n";
    vector<double> fi;
    double acum = 0;
    for(auto v: adj[u]){
        if(v == p) continue;

        dfs(v, u);
        fi.push_back(dp[v][0] - dp[v][1]);

        acum += dp[v][1];
    }

    if(a[u-1] == '1'){
        dp[u][0] = dp[u][1] = acum;
        // cout<<"dp["<<u<<"] = "<<dp[u][0]<<" - "<<dp[u][1]<<"\n";

        return;
    }
    sort(all(fi));

    //começo com ngm ajudando
    double tt = adj[u].size();
    double ct = 0; //nro filhos ajudando

    dp[u][0] = inf;
    dp[u][1] = tt +acum;
    double curr = acum;

    // cout<<"Acum("<<u<<")"<<" = "<<acum<<"\n";
    int id = 0;
    for(int i = 0; i< adj[u].size(); i++){
        if(adj[u][i] == p) continue;
        ct+=1.0;
        curr+=fi[id];

        // cout<<"i = "<<i<<": "<<curr + tt/(ct+1.0)<<"\n";

        dp[u][0] = min(dp[u][0], curr + tt/ct);
        dp[u][1] = min(dp[u][1], curr + tt/(ct+1.0));
        
        id++;
    }

    if(adj[u].size() == 1) dp[u][1] = 1;

    // cout<<"dp["<<u<<"] = "<<dp[u][0]<<" - "<<dp[u][1]<<"\n";
}

void solve(){
    double res = 0;
    int n; 
    cin>>n;
    
    if(n==1){
        cout<<"0.0\n";
        return;
    }
    
    cin>>a;
    
    rep(i, 0, n+1) {
        adj[i].clear();
        vis[i] = 0;
        deg[i] = 0;
        dp[i][0] = dp[i][1] = 0;
    }
    
    rep(i,0, n-1){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cout<<fixed<<setprecision(12);
    
    rep(i, 0, n){
        if(a[i] == '1'){
            start = i+1;
            dfs(i+1, 0);
            double res = dp[i+1][0];
            cout<<res<<"\n";
            return;
        }
    }
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}