#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back




void solve(){
    int n, x, y;
    cin>>n>>x>>y;

    string a; cin>>a;

    int dx = 0, dy = 0;

    vi v(n), ft(n);
    rep(i, 0, n) cin>>v[i];

    int falta = 0;

    bool mogx = true, mogy =true;

    rep(i, 0, n){
        int usa = (v[i] + 2) / 2;
        falta += v[i] - usa;
        ft[i] = v[i] - usa;

        if(a[i] == '0'){
            x -= usa;

            dy += (usa + usa - 1LL - v[i]);
            mogx=false;
        }
        else{
            y -= usa;

            dx += (usa + usa - 1LL - v[i]);
            mogy=false;
        }
    }

    if( x < 0 || y<0){
        cout<<"NO\n";
        return;
    }

    if(mogx){
        rep(i, 0, n){
            if(a[i] == '1'){
                int dif = x;
    
                int foi = min(ft[i], dif);
                falta -= foi;
                x -= foi;

                ft[i] -= foi;
            }
        }
    }

    if(mogy){
        rep(i, 0, n){
            if(a[i] == '0'){
                int dif = y;
    
                int foi = min(ft[i], dif);
                falta -= foi;
                y -= foi;
            }
        }
    }

    if(!mogx && !mogy){
        if(falta > x + y){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
        return;
    }

    if(mogx){
        x = max(0LL, x - dx);
        if(x > y || x + y < falta){
        cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
        return;
    }

    if(mogy){
        y = max(0LL, y- dy);
        if(y > x || x + y < falta){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
        return;
    }

}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}