#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
#define ff first
#define ss second

void solve(){
    ll l1, r1, l2, r2;
    cin>>l1>>r1>>l2>>r2;

    ll meu = l1 + r1;
    ll rdeles = meu - l2;
    ll diff1 = r1-l1+1;
    ll diff2 = r2-l2+1; //desconsidera
    
    
    ll best = 0;
    ll l = 1, r = min(diff1 - 1, diff2/2) + 1;

    while(l < r){
        ll mid = (l+r)/2;

        ll meu = mid*l1 + ((r1+(r1-mid+1))*(mid))/2;

        ll deles = (l2+(l2+(2*mid)-1))*(mid);


        if(meu >= deles){
            best = mid;
            l = mid+1;
        }else{
            r = mid;
        }
    }
    cout<<best<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}