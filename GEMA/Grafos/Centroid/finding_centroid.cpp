#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2e5+3;

vi adj[maxn];
int n; 
int sz[maxn];

int getsz(int u, int p){
    int a = 1;
    for(auto v: adj[u]){
        if(v == p) continue;
        a += getsz(v, u);
    }
    return sz[u] = a;
}


int centroid(int u, int p){
    for(auto v: adj[u]){
        if(v == p) continue;
        
        if(sz[v] > n/2) return centroid(v, u);
    }
    return u;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n;

    rep(i, 1, n){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    getsz(1, 0);
    cout<<centroid(1, 0)<<"\n";
}