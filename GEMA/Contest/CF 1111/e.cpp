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

const int maxn = 2e5+4;
const int inf = 1e9+3;

void solve(){
    ll n;
    ll k; 
    cin>>n>>k;

    vi v(n);

    ll sum = 2LL*n - 2;

    if(sum > k or k % 2LL){
        cout<<"-1\n";
        return;
    }

    ll falta = k-sum;
    // cout<<"falta: "<<falta<<"\n";

    vi l = {0}, r = {int(n-1)};

    deque<int> dq;
    rep(i, 1, n-1) dq.push_back(i);
    
    int inv = 0;
    while(!dq.empty()){
        // cout<<dq.front()<< " - "<<dq.back()<<"\n";
        int cost = 2*abs(dq.front() - dq.back());
        if(cost > falta or cost == 0){
            if(inv) l.pb(dq.back());
            else r.pb(dq.back());

            dq.pop_back();
        }
        else{
            falta -= cost;
            inv = 1-inv;

            int esq = dq.front();
            int dir = dq.back();
            dq.pop_front();
            
            if(inv) swap(esq, dir);
            l.push_back(esq);
            
            if(!dq.empty()){
                dq.pop_back();
                r.push_back(dir);
            }
        }
    }

    vi cords;

    // cout<<"l : \n";
    for(auto x: l) {
        cords.pb(x);
        // cout<<x<<" ";
    }
    // cout<<"\nr:\n";
    reverse(all(r));
    for(auto x: r) {
        cords.pb(x);
        // cout<<x<<" ";
    }
    // cout<<"\n";

    rep(i, 0, n){
        v[cords[i]] = i+1;
    }

    if(falta > 0){
        cout<<"-1\n";
        return;
    }
    
    rep(i, 0, n-1){
        cout<<v[i]<<" "<<v[i+1]<<"\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) {
        // cout<<"caso "<<t<<"\n";
        solve();
        // cout<<"\n";
    }
}