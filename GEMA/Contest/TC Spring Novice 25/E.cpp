#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 2e5+7;
int n, m; 
vi vis;

vi adj[MAX];
vector<pii> resp;

int dfs(int u){
    vis[u] = 1;

    vi f; //filho com paridade impar

    for(auto v: adj[u]){
        if(vis[v]) continue;
        int k = dfs(v);
        
        if(k == 1) f.push_back(v);
    }

    for(int i =0; i< f.size(); i+=2){
        if(i+1 >= f.size()){
            resp.push_back({f[i], u});
            return 0;
        }
        else{
            resp.push_back({f[i], f[i+1]});  
        }
    }
    return 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m;
    vis.resize(n);

    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        a--; b--;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, 0, n){
        if(!vis[i]){
            dfs(i);
        }
    }

    cout<<resp.size()<<"\n";
    for(auto[a, b]: resp){
        cout<<a+1<<" "<<b+1<<"\n";
    }
}