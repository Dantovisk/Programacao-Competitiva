#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5+7;
const int inf = 1e9+7;

int v[MAXN];
ll psum[3*MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, q; cin>>n>>q;

    set <int> vis;
    for(int i =1; i<=n; i++) {
        cin>>v[i];
        psum[i] = psum[i-1]+v[i];
    }
    for(int i =n+1; i<=2*n; i++) {
        psum[i] = psum[i-1]+v[i-n];
    }
    for(int i =2*n+1; i<=3*n; i++) {
        psum[i] = psum[i-1]+v[i-2*n];
    }

    int st = 0;

    while(q--){
        int a, b, c;
        cin>>a>>b;

        if(a==1){
            st += b;
            if(st >= n) st %= n;
        }else{
            cin>>c;
            int l = st + b - 1;
            int r = st + c;

            cout<<(psum[r]-psum[l])<<"\n";

        }
    }
    

}