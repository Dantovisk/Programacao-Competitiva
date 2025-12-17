#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    vi v(n);

    vi impar, par;
    rep(i, 0, n) {
        cin>>v[i];
        if(v[i] % 2) impar.push_back(v[i]);
        else par.push_back(v[i]);
    }
    sort(all(par)); reverse(all(par));
    sort(all(impar)); reverse(all(impar));

    vi pp(par.size()+1, 0);

    rep(i, 1, par.size()+1){
        pp[i] = pp[i-1] + par[i-1];
    }

    for(int i = 1; i<=n; i++){
        if(impar.size() == 0){
            cout<<"0 ";
            continue;
        }
        else if(par.size() == 0){
            if(i%2) cout<<impar[0]<<" ";
            else  cout<<"0 ";
            continue;
        }

        if(par.size() < i-1){
            
            int pares = (par.size() + (((i-1) % 2LL) != (par.size() % 2LL)? -1 : 0));
            if((i - pares) > impar.size()) cout<<"0 ";
            else if((i - pares) % 2 == 0) cout<<"0 ";
            else cout<<pp[pares]+impar[0]<<" ";
            

            continue;
        }

        cout<<impar[0] + pp[i-1]<<" ";
    }
    cout<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}