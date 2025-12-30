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

void solve(){
    int n; cin>>n;
    vi v1(2*n), v2(2*n), v3(2*n);
    rep(i, 0, n){
        cin>>v1[i];
        v1[i+n] = v1[i];
    }
    rep(i, 0, n){
        cin>>v2[i];
        v2[i+n] = v2[i];
    }
    rep(i, 0, n){
        cin>>v3[i];
        v3[i+n] = v3[i];
    }

    //o conv 1 ta fixo
    int ct1 = 0;
    rep(st, 0, n){
        bool foi = true;
        rep(i, st, st+n){
            if(v1[i-st] >= v2[i]){
                foi = false;
                break;
            }
        }
        if(foi) ct1++;
    }

    //o conv 2 ta fixo
    int ct2 = 0;
    rep(st, 0, n){
        bool foi = true;
        rep(i, st, st+n){
            if(v2[i-st] >= v3[i]){
                foi = false;
                break;
            }
        }
        if(foi) ct2++;
    }

    ll res = n;
    res *= ct1;
    res*= ct2;

    cout<<res<<"\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}