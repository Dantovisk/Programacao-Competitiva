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
const ll mod = 1e9+7;

ll sum(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}

ll mexp(ll a, ll b, ll mod =mod){
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a){
    return mexp(a, mod-2);
}


//dp[i][0] -> de quantas formas posso descobrir (com palpites minimos) a subarvore
//dp[i][1] -> de quantas formas posso deixar a subarvore a 1 palpite de ser descoberta
int dp[MAX][2];
vi adj[MAX];

ll pref[MAX];
ll suf[MAX];

void dfs(int u){
    ll prod = 1;
    ll sum0 = 0, sum1 = 0; 
    for(auto v: adj[u]){
        dfs(v);
        prod = mul(prod, dp[v][0]);

        sum0 = sum(sum0, dp[v][0]);
        sum1 = sum(sum1, dp[v][1]);
    }

    pref[0] = 1;
    for(int i =0; i<adj[u].size(); i++){
        pref[i+1] = mul(pref[i], dp[adj[u][i]][0]);

    }

    suf[adj[u].size() + 1] = 1;
    for(int i = adj[u].size(); i> 0; i--){
        suf[i] = mul(suf[i+1], dp[adj[u][i-1]][0]);

    }

    if(adj[u].size() == 0){
        dp[u][0] = dp[u][1] = 1;
        return;
    }

    dp[u][1] = 0;
    int k = 0;
    for(auto v: adj[u]){
        ll s = mul(pref[k], suf[k+2]);
    
        //ll s = mul(prod, inv(dp[v][0]));
        dp[u][1] = sum(dp[u][1], mul(s, dp[v][1]));
        k++;
    }

    k = 0;
    for(auto v: adj[u]){
        //ll s = mul(prod, inv(dp[v][0]));

        ll s = mul(pref[k], suf[k+2]);
        dp[u][0] = sum(dp[u][0], mul(s, dp[v][1]));
        k++;
    }
    
    dp[u][0] = sum(dp[u][0], prod);
        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;

    for(int i =2; i<=n; i++){
        int a; cin>>a;
        adj[a].push_back(i);
    }

    dfs(1);

    cout<<dp[1][0]<<"\n";

    return 0;
}