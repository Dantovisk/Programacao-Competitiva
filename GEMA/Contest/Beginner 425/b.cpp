#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e6+7;
const int inf = 1e9+7;

int v[MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    set <int> vis;
    for(int i =1; i<=n; i++) {
        cin>>v[i];
        if(v[i] == -1) continue;
        if(vis.find(v[i])!= vis.end()){
            cout<<"No\n";
            return 0;
        }
        vis.insert(v[i]);
    }
    int k = 1;
    cout<<"Yes\n";
    for(int i =1; i<=n; i++) {
        if(v[i] == -1){
            while(vis.find(k) != vis.end()) k++;
            cout<<k<<" ";
            vis.insert(k);
        }
        else cout<<v[i]<<" ";
    }

}