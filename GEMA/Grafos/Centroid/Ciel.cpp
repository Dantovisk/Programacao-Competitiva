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
int vis[maxn];
char res[maxn];

int getsz(int u, int p){
    int a = 1;
    for(auto v: adj[u]){
        if(v == p or vis[v]) continue;
        a += getsz(v, u);
    }
    return sz[u] = a;
}

int centroid(int u, int p, int n){
    for(auto v: adj[u]){
        if(v == p or vis[v]) continue;
        if(sz[v]*2 > n) return centroid(v, u, n);
    }
    return u;
}

bool decompose(int u, char c){
    if(c > 'Z') return false;
    int cent = centroid(u, 0, sz[u]);
    // cout<<"Achei o centroid "<<cent<<"\n";
    vis[cent] = 1;
    res[cent] = c;

    for(auto v: adj[cent]){
        if(vis[v]) continue;
        getsz(v, cent);
        if(!decompose(v, c+1)) return false;
    }

    return true;
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
    if(!decompose(1, 'A')) cout<<"Impossible\n";
    else{
        rep(i, 1, n+1){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
}