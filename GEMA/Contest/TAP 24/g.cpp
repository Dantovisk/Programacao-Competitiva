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

void solve(){
    string s;
    cin >> s;

    int ct = 0, cp = 0, cm = 0;
    for(char c : s) {
        if(c == 'T') ct++;
        else if(c == 'P') cp++;
        else if(c == 'A' || c == 'U') cm++;
    }


    cout << min(cm, min(cp, ct)) << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}