#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 1e7+3;
int v[MAX], ors[MAX], ors2[MAX];

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin>>n>>k;
    int x, a, b, c;
    cin>>x>>a>>b>>c;
    int sum = 0;

    v[0] = x;
    rep(i, 1, n){
        v[i] = (int)((1LL*v[i-1]*a + b)%c);
    }

    rep(i, 0, n){
        int j = i%k;

        int l = (j > 0 ? ors[i-1] : 0); 
        ors[i] = l | v[i];
    }
    for(int i = n-1; i>=0; i--){
        int j = i%k;

        int l = (j+1 < k ? ors2[i+1] : 0); 
        ors2[i] = l | v[i];
    }

    rep(i, 0, k-1){
        sum ^= v[i];
    }

    int xors = 0;

    rep(i, 0, n-k+1){
        int l = 0;
        if(i % k) l = ors2[i];
        int i2 = i+k-1;
        int r = ors[i2];
        int res = (l|r);
        // cout<<"res: "<<res<<"\n";
        xors ^= res;
    }

    cout<<xors<<"\n";
}