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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n, m, l;
    cin>>n>>m>>l;

    vi v(n+1);
    rep(i,1, n+1) cin>>v[i];
    int currmx = 0, res = 0, qt = 0;
    v[0] = 0;
    v.pb(l+1);

    multiset<int> anim;
    rep(i, 0, min(m,n+1)){
        anim.insert(0);
    }

    int id = 1;
    rep(i, 1, l+1){
        auto ptr = anim.begin();
        int k = *ptr;
        anim.erase(ptr);
        anim.insert(k+1);

        if(i == v[id]){
            auto ptr = anim.end();
            ptr--;
            anim.erase(ptr);
            if(anim.size() < n-id+1) anim.insert(0);
            id++;
        }

        // int ds = v[i] - v[i-1];
        // res = max(currmx + ds, res);
        // currmx += ds/m;

        // qt += ds%m;
        // qt--;
        // if(qt < 0){
        //     qt += m;
        //     currmx --;
        // }

        // if(qt >= m){
        //     qt -= m;
        //     currmx ++;
        // }
    }

    for(auto x: anim) res += x;
    // res = max(res, l - v[n] + currmx);
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}