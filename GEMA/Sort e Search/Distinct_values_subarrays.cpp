#include <bits/stdc++.h> 
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;

const int MAX = 2e5+5;
int v[MAX], pos[MAX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    int l = 1;
    set<int> vis;

    ll resp = 0;

    rep(i, 1, n+1) {
        cin>>v[i];
        while(vis.find(v[i]) !=vis.end()) vis.erase(v[l++]);
        
        vis.insert(v[i]);
        resp += vis.size();
    }

    cout<<resp<<"\n";

}