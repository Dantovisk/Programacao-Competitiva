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

const int maxv = 1e3 + 10;

bool sv[maxv];

void solve(){
    int n;
    cin >> n;

    int rem = n;
    vi fat;
    for(int p = 2; p < maxv; p++) if(!sv[p]) {
        for(int k=p; k < maxv; k += p) {
            sv[k] = 1;
        }

        int e = 0;
        while(rem % p == 0) {
            e++;
            rem /= p;
        }

        if(e) {
            fat.push_back(n/p);
        }
    }

    if(rem > 1) fat.push_back(n/rem);

    cout << fat.size() << "\n";
    for(auto x: fat) cout << 1 << " " << x << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}