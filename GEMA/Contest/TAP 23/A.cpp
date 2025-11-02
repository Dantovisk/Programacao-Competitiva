#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9+7;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin>>n>>m;

    vi a(n), mod;

    rep(i, 0, n) cin>>a[i];

    int last = inf;
    rep(i, 0, m){
        int b; cin>>b;
        if(b < last){
            mod.push_back(b);
            last = b;
        }
    }

    reverse(all(mod));

    for(int i =0; i<n; i++){
        int k = a[i];

        auto ptr = upper_bound(all(mod), k);

        while(ptr != mod.begin()){
            ptr--;
            k %= (*ptr);
            ptr =  upper_bound(all(mod), k);
        }

        cout<<k<<" ";
    }


}