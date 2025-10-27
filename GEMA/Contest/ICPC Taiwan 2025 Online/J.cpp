#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, ll> pii;
typedef vector<int> vi;
#define ff first
#define ss second

const int MAX = 2e5+3;

vector<pii> adj [MAX];

ll d;
int cont = 0;

ll dfs(int u, int p, ll price){
    ll total = 0;

    pair<ll, ll> fil = {0, 0};

    for(auto [v, w]: adj[u]){
        if(v == p) continue;
        ll xd = dfs(v, u, w) + w;
        fil = max({fil, {xd, fil.first}, {fil.first, xd}});
    }

    total = fil.first;
    ll filhos = fil.first + fil.second;
    if(filhos > d){
        total = 0;
        cont++;
    } else if(price + total > d){
        total = 0;
        cont++;
    }
    return total;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    cin>>n>>k;

    ll l = 1, r = 1e15;
    
    for(int i = 0; i< n-1; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        l = max(l, (ll)w);
    }

    ll best = 1e15;

    while(l < r){
        ll mid = (l + r) / 2LL;
        cont = 0;
        d = mid;

        dfs(1, 0, 0);

        if(cont <= k){
            best = min(best, mid);
            r = mid;
        }else{
            
            l = mid+1;
        }
    }

    cout<<best<<"\n";
}