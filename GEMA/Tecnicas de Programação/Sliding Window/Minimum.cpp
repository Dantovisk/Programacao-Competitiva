#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
deque<pair<int,int>> d;

void ins(int u, int id){
    while(!d.empty() && d.back().first >= u)
        d.pop_back();
    d.push_back({u, id});

    if(d.front().second <=id-k) d.pop_front();
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    cin>>n>>k;
    int x, a, b, c;
    cin>>x>>a>>b>>c;

    vi v(n);
    v[0] = x;
    rep(i, 1, n){
        v[i] = ((ll)v[i-1]*(ll)a + b)%(ll)c;
        // cout<<i<<" = "<<v[i]<<"\n";
    }
    
    rep(i, 0, k-1){
        ins(v[i], i);
    }

    int xors = 0;

    rep(i, 0, n-k+1){
        ins(v[i+k-1], i+k-1);
        // cout<<d.front().first<<" ";
        xors ^= d.front().first;
    }

    cout<<xors<<"\n";


}