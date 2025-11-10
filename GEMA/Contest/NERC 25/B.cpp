#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
#define ff first
#define ss second

pii sub(pii& a,pii& b){
    return {a.ff-b.ff, a.ss-b.ss};
}

ll cross(pii a, pii b){
    return a.ff*b.ss - a.ss*b.ff;
}

int dir(pii a, pii b, pii p){
    ll k = cross(sub(b, a), sub(p, a));
    if(k > 0LL) return 1;
    if(k == 0LL) return 0;
    return -1;
}

int teste(int n, vector<pii>& pts){
    deque <pii> v;
    v.push_back(pts[0]);
    v.push_back(pts[1]);

    int resp = 2;

    rep(i, 2, n){
        // cout<<"to no "<<i<<"\n";
        while(v.size() > 1 && 
        ((dir(v[v.size() - 2], v[v.size() - 1], pts[i]) >= 0) 
        || (v.size() > 2 && (dir(v[v.size() - 1], v[0], pts[i]) <= 0)) ||
        (dir(v[1], v[0], pts[i]) <= 0))){
            // cout<<"tirei o "<<v.front().ff<<" "<<v.front().ss<<"\n";
            v.pop_front();
        }
        v.push_back(pts[i]);
        resp = max(resp, (int)v.size());
    }

    return resp;
}

void solve(){
    int n; cin>>n;

    vector<pii> pts(n);

    rep(i, 0, n){
        int a, b;
        cin>>a>>b;
        pts[i] = {a, b};
    }

    int resp = 0; 
    resp = max(resp, teste(n, pts));

    // reverse(all(pts));

    // resp = max(resp, teste(n, pts));

    cout<<(resp <= 2? 0 : resp)<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}