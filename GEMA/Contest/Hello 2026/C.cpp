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
    int n, k;
    ll m;
    cin>>n>>m>>k;

    int best = 0;

    int l = 0, r = n;

    while(l < r){
        int mid = (l+r)/2;
        // cout<<"mid: "<<mid<<"\n";
        
        int ub = min(k-1, n-k);
        int x1 = min(ub, mid/2);

        int uai = max(k-1, n-k);
        int x2 = min(uai, mid - x1);
        
        if(x1 + x2 < mid){
            r = mid;
            continue;
        }

        // cout<<"x1: "<<x1<<", x2: "<<x2<<"\n";

        ll sum1 = max(1LL*x1, 0LL);
        ll sum2 = max(2LL*x2 - 1LL, 0LL);

        if(sum1 + sum2 > m){
            r = mid;
            continue;
        }

        l = mid+1;
        best = max(best, mid);
    }

    cout<<best+1<<"\n";
    
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}