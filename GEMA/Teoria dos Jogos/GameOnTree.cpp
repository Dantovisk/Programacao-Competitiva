#include <bits/stdc++.h> // Atcoder - Game on Tree
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5+10;

int n; 
vector<int> adj[maxn];

int dfs(int u, int p){
    int grundy = 0;

    for(auto v: adj[u]){
        if(v == p) continue;

        grundy ^= (dfs(v, u) + 1);
    }
    return grundy;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n;
    for(int i = 2; i<=n; i++){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    if(dfs(1, 0)) cout <<"Alice\n";
    else cout<<"Bob\n";

    return 0;
}