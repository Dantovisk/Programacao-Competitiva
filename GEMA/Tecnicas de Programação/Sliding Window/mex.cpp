#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int inf = 1e9 + 3;
const int MAX = 2e5 + 3;
map <int, int> cnt;
//end start
set <pii> s;
int n, k;
int v[MAX];

void ins(int i){
    cnt[v[i]]++;
    if(cnt[v[i]] == 1){
        // cout<<"add: "<<v[i]<<"\n";
        auto ptr = s.lower_bound({v[i], 0});

        auto [r, l] = *ptr;
        // cout<<r<<" - "<<l<<"\n";
        int ll = v[i], rr = v[i];

        if(v[i] == l-1){
            s.erase(ptr);
            rr = r;
        }

        auto ptr2 = s.lower_bound({v[i], 0});
        ptr2--;

        auto [r2, l2] = *ptr2;
        // cout<<r2<<" - "<<l2<<"\n\n";
        if(r2 == v[i]-1){
            s.erase(ptr2);
            ll = l2;
        }

        s.insert({rr, ll});
    }
}

void rem(int i){
    cnt[v[i]] --;
    if(cnt[v[i]] == 0){
        auto ptr = s.lower_bound({v[i], 0});
        auto [r, l] = *ptr;

        s.erase(ptr);

        if(l < v[i]) s.insert({v[i]-1, l});

        if(r > v[i]) s.insert({r, v[i]+1});
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    
    cin>>n>>k;

    rep(i,0,n) cin>>v[i];

    s.insert({inf,inf});
    s.insert({-2,-2});

    rep(i, 0, k-1) {
        ins(i);
    }

    rep(i, 0, n-k+1){
        ins(i+k-1);

        // cout<<"i = "<<i<<"\n";
        // for(auto [l2, r2]: s){
        //     cout<<l2<<" "<<r2<<"\n";
        // }

        auto ptr = s.begin();
        ptr++;

        auto [r, l] = *ptr;
        
        if(l == 0) cout<<r+1<<" ";
        else cout<<"0"<<" ";

        rem(i);
    }

    cout<<"\n";
}