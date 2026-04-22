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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    string a; cin>>a;
    int n = sz(a);

    int st = -1, ed = -1;   
    rep(i,0, n-1) {
        if(a[i] == a[i+1]){
            if(st == -1) st = i+1;
            else if(ed == -1){
                ed = i;
            }else{
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}