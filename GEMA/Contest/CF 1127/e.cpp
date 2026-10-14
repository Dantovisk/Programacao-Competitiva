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

const int maxn = 1e3+4;
const int inf = 1e9+3;

int v[maxn][maxn];
int quad[maxn][maxn];
int psum[maxn][maxn];
int n,q; 

set<pii> vis;

bool da(int i, int j){
    if(i < 1 or j < 1 or i >= n or j >= n) return false;
    if(vis.find({i, j}) != vis.end()) return false;
    return true;
}

void upd(int i, int j, int x){
    if(!da(i, j)) return;

    quad[i][j] += x;

    rep(k, 1, n){
        psum[i][k] = psum[i][k-1];
        if(quad[i][k]) psum[i][k]++;
    }
    vis.insert({i, j});
}

void solve(){
    cin>>n>>q;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>v[i][j];
        }
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            int a; cin>>a;
            v[i][j] = a - v[i][j];
        }
    }

    for(int i = 1; i< n; i++){
        for(int j = 1; j < n; j++){
            quad[i][j] = v[i][j] + v[i+1][j+1] -
                v[i+1][j] - v[i][j+1];

            // cout<<quad[i][j]<<" ";
            
            psum[i][j] = psum[i][j-1];
            if(quad[i][j]) psum[i][j]++;
        }
        // cout<<"\n";
    }

    rep(k, 0, q){
        char t; cin>>t;
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;

        if(t == 'Q'){
            int sum = 0;
            rep(i, r1, r2){
                sum += psum[i][c2-1] - psum[i][c1-1];
            }
            
            if(sum > 0) cout<<"No\n";
            else cout<<"Yes\n";
        }
        else{
            int x; cin>>x;
            vis.clear();

            upd(r1-1, c1-1, -x);
            upd(r2, c1-1, x);
            upd(r1-1, c2, x);
            upd(r2, c2, -x);

            // cout<<quad[1][1]<<"\n";
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}