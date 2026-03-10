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

const int MAX = 1e6+5;
ll fac[MAX], invfac[MAX];

void solve(){
    int n; cin>>n;
    vi v(n+1), l(n+1), r(n+1);

    vector<pii> st = {{0, 0}};
    

    //primeiro menor à esquerda
    rep(i, 1, n+1){
        cin>>v[i];
        
        while(st.back().ff >=  v[i]) st.pop_back();
        auto [val, id] = st.back();
        l[i] = id+1;
        st.push_back({v[i], i});
    }
    st = {{0, n+1}};

    //primeiro menor ou igual à direita
    for(int i = n; i> 0; i--){
        while(st.back().ff >  v[i]) st.pop_back();
        auto [val, id] = st.back();
        r[i] = id-1;
        if(st.back().ff ==  v[i]) st.pop_back();
        st.push_back({v[i], i});
    }




}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    // fac[0] = 1;
    // rep(i, 1, 1'000'003){
    //     fac[i] = mul(fac[i-1], i);
    // }

    int t = 1; 
    // cin>>t;
    while(t--){
        solve();

    }
}