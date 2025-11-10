#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 510;
int n, m; 
vi mask;

int adj[MAX][MAX];
int dist[MAX][MAX];



int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m, k;
    cin>>n>>m>>k;

    vector<pair<ll,ll>> v;

    rep(i, 0, m){
        ll x, y;
        cin>>x>>y;

        v.push_back({x, y});
    }

    ll x = 0, y = 0;

    rep(i, 0, k){
        int a, b;
        cin>>a>>b;

        ll k1 = (1LL << a) - 1, k2 = (1LL << b) - 1;

        x^=k1; y ^= k2;
    }

    for(auto[a, b] : v){
        cout<<(a^x)<<" "<<(b^y)<<"\n";
    }

}