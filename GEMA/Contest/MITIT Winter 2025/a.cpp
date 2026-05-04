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
#define int long long 

const int maxn = 120;

int res[maxn];

int qr(int x, int y) {
    cout << "? " << x << " " << y << endl; 

    int r;
    cin >> r;
    return r;
}

void solve(){
    int n;
    cin >> n;

    int i = min(3LL, n);
    while(1) {
        int a = qr(i, i-1LL);
        int b = qr(i, i-2LL);

        res[i] = gcd(a, b);
        res[i-1] = a / res[i];
        res[i-2] = b / res[i];

        if(i == n) break;
        if(i + 3LL > n) {
            i=n;
        } else {
            i += 3LL;
        }
    }

    cout << "!";
    for(int i = 1; i <= n; i++) cout << " " << res[i];
    cout << endl;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t ; 
    cin>>t;
    while(t--){
        solve();
    }
}