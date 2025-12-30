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

void solve(){
    int n; cin>>n;

    string a; cin>>a;

    bool b5 = false, b6= false;

    rep(i, 0, n-3){
        if(a.substr(i, 4) == "2025") b5 = true;
        if(a.substr(i, 4) == "2026") b6 = true;
    }

    if(b6) cout<<"0\n";
    else if(b5){
        cout<<"1\n";
    } else{
        cout<<"0\n";
    }
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}