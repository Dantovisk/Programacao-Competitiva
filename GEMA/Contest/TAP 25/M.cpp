#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back

const int MAX=2010; 
const int mod = 998244353;

vi adj[MAX];
int dis[MAX];
int dp[MAX][2*MAX];
int res[2*MAX];

int bfs1(){
    queue<int> q;
    q.push(1);
    dis[1] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(dis[v]) continue;

            q.push(v);
            dis[v] = dis[u] + 1;
        }

    }
    return dis[2];
}

 
ll exponenciacao(ll base,ll expoente){
    if(expoente == 0) return 1;
    ll x = exponenciacao(base,expoente/2);
    x %= mod;
    if(expoente % 2 == 0){
        return((x * x) % mod);
    }else{
        return((((x * x)%mod)*base)%mod);
    }
}
 
int inverso(int x){
    return exponenciacao(x,mod-2);
}
 
int pegar(int a,int b,int c){
    //b = max(b,a-b);
    ll resposta = 1;
    //cout << a << " " << b << " " << c << '\n';
    for(int i = a; i > b; i--){
        resposta *= i;
        resposta %= mod;
    }
    ll fatz = 1;
    for(int i = 2; i <= c; i++){
        fatz *= i;
        fatz %= mod;
    }
    //cout << fatz << endl;
    resposta *= inverso(fatz);
    resposta %= mod;
    return resposta;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m, k;
    cin>>n>>m>>k;

    rep(i, 0, m){
        int a, b;
        cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int d = (bfs1()+k-2)/k;
    // cout<<d<<"\n";

    int mx = d*k;

    dp[1][0] = 1;


    rep(i, 1, mx+1){
        rep(u, 1, n+1){
            for(int v: adj[u]){
                dp[u][i] += dp[v][i-1];
                dp[u][i] %= mod;
            }
            if(u == 2){
                res[i] += dp[u][i];
                res[i] %= mod;
            }
            // cout<<"dp["<<u<<"]["<<i<<"] = "<<dp[u][i]<<"\n";
        }
    }

    int tot = 0;
    rep(i, 1, mx+1){
        if(res[i] == 0) continue;
        // cout<<"i: "<<i<<" -> "<<res[i]<<" vira ";
        int obj = (k - (i%k))%k;

        int a = obj + d - 1;
        int b = obj;
        int c = d-1;
        if(b < c) swap(b, c);
        int xd = pegar(a, b, c);
        // cout<<xd<<"\n";
        tot += (((ll)xd * (ll)res[i])%(ll)mod);
        tot %= mod;
    }
    cout<<tot<<"\n";

}