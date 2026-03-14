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

int v[200010];
set <pii, greater<pii>> l;
set <pii> r;

void ins(int i){
    if(sz(l) && (*l.begin()).ff >= v[i]){
        l.insert({v[i], i});
    }
    else{
        r.insert({v[i], i});
    }
    while(sz(r) > sz(l)){
        auto x = *r.begin();
        r.erase(r.begin());
        l.insert(x);
    }
    while(sz(r) + 1 < sz(l)){
        auto x = *l.begin();
        l.erase(l.begin());
        r.insert(x);
    }
}

void rem(int i){
    if(l.find({v[i], i}) != l.end()){
        l.erase({v[i], i});
    } else{
        r.erase({v[i], i});
    }
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin>>n>>k;

    rep(i,0,n) cin>>v[i];

    

    rep(i, 0, k-1) {
        ins(i);
    }

    rep(i, 0, n-k+1){
        ins(i+k-1);
        
        auto [x, y] = *l.begin();
        cout<<x<<" ";

        rem(i);
    }

    cout<<"\n";


}