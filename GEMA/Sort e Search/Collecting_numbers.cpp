#include <bits/stdc++.h> 
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin>>n;
    vi v(n), pos(n);
    rep(i, 0, n) {
        cin>>v[i];
        pos[v[i]] = i;
    }

    int cont  = 1;

    rep(i, 1, n) {
        if(pos[i] > pos[i+1]) cont++;
    }

    cout<<cont<<"\n";
}