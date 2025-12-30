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
    vi v(n);
    int ct = 0;
    int foi = n-1;

    rep(i, 0, n){
        cin>>v[i];
        if(v[i] > 1 && foi > 0){
            foi -= v[i]-1;
        }
        if(v[i]) ct ++;
    } 
    cout<<ct-max(foi,0)<<"\n";


}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}