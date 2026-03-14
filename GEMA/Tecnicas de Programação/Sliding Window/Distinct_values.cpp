#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int n, k;
    cin>>n>>k;

    map <int, int> mp;
    vi v(n);
    rep(i,0,n) cin>>v[i];

    rep(i, 0, k-1) mp[v[i]] ++;

    rep(i, 0, n-k+1){
        mp[v[i+k-1]]++;
        cout<<mp.size()<<" "; 
        
        if((--mp[v[i]]) == 0) mp.erase(v[i]);
    }


}