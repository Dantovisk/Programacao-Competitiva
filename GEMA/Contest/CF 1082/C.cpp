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
    ll s, m;
    cin>>s>>m;

    int last = -1;
    ll res = 1e18+1;

    vi dir (63, 0);
    vi uns;

    int xd = -1;
    rep(i, 0, 62){
        if((1LL<<i) & m){
            uns.pb(i);
            xd = i;
        }
        dir[i] = xd;
        if((1LL<<i) & s){
            if(xd == -1){
                cout<<"-1\n";
                return;
            }
        }
    }
    // cout<<"cheguei\n";
    reverse(all(uns));

    ll l = 0, r = 1e18+9;

    while(l < r){
        ll mid = (l+r)/2LL;
        ll ns = s;

        bool deu = true;
        ll sobra = mid;
        int id=0;
        for(int i = 61; i>= 0; i--){
            while(id<sz(uns) && uns[id] > i ) {
                id++;
                sobra = mid;
            }
            if((1LL<<i) & ns){
                if(id >= sz(uns)){
                    deu = false;
                    break;
                }
                // cout<<"i = "<<i<<"\n";

                ll used = min((1LL<<(i-uns[id])), sobra);
                sobra -= used;
                ns -= (used*(1LL<<uns[id]));
                // cout<<"sobra = "<<sobra<<"\n";
                while(ns & (1LL<<i)){
                    id++;
                    if(id >= sz(uns)){
                        deu = false;
                        break;
                    }
                    sobra = mid;
                    used = min((1LL<<(i-uns[id])), sobra);
                    sobra -= used;
                    ns -= (used*(1LL<<uns[id]));
                    // cout<<"sobra dnv = "<<sobra<<"\n";
                    // cout<<"ns ficou = "<<ns<<"\n";
                }
            }
            if(deu == false) break;
        }
        // cout<<"mid="<<mid<<"\n";
        if(deu){
            // cout<<"deu!\n";1
            r = mid;
            res = min(res, mid);
        }else{
            // cout<<"nao deu :c\n";
            l= mid+1;
        }
    }

    cout<<res<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}