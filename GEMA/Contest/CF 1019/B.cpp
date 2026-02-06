#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    string a; cin>>a;

    char l = '0';
    int ct = 0;

    rep(i, 0, n){
        if(l != a[i]) ct++;
        l = a[i];
    }

    if(ct >= 3) ct-=2;
    else if(ct >=2) ct--;
    cout<<n+ct<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}