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
    int n; 
    cin>>n;

    vi v(n);
    rep(i,0, n) cin>>v[i];


    int best = 0;

    int mal = 0;
    int ct = 0;
    vector<int> a(n), b(n);

    rep(i, 0, n){
        if(v[i]-1 <= i){
            a[i] ++;
        }
        else{
            a[i] ++;
            b[v[i]-1] += 1;
        }
    }

    rep(i, 0, n){
        if(a[i] >= 1) ct++;
        if(b[i] >= 1) mal-= b[i];

        best = max(best, ct+mal);
    }
    cout<<best<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}