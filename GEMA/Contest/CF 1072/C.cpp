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

int n, k;
map<int, int> vis;

void dp(int u, int x){
    if(u < k) return;
    if(vis.find(u) != vis.end()){
        if(vis[u] <= x) return;
    }

    vis[u] = x;

    dp(u/2, x+1);
    dp((u+1)/2, x+1);
}

void solve(){
    cin>>n>>k;
    vis.clear();

    dp(n, 0);

    if(vis.find(k) != vis.end()){
        cout<<vis[k]<<"\n";
    }else{
        cout<<"-1\n";
    }
    
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}