#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, k; cin>>n>>k;
    vi v(n); 

    rep(i, 0, n) cin>>v[i];
    
    int l = 0, r = n-1;
    
    int qt1 = 0;
    int x = 0;
    for(; l < n; l++){
        if(v[l] <= k) qt1--;
        else qt1++;

        if((qt1 == 0 && x) || qt1 < 0){
            break;
        }
        x++;
    }
    
    int qt2 = 0;
    x = 0;
    for(; r >= 0; r--){
        if(v[r] <= k) qt2--;
        else qt2++;
        
        if((qt2 == 0 && x) || qt2 < 0){
            break;
        }
        x++;
    }
    if(r - l >= 2) {
        cout<<"YES\n";
        return;
    }

    // cout<<l<<" - "<<r<<"\n";
    
    int foi1 = 0, foi2 = 0; 
    x = 0;
    l++;
    r--;

    for(; r >= 1; r--){
        if(v[r] <= k) qt2--;
        else qt2++;
        
        if((qt2 == 0 && x) || qt2 < 0){
            foi1 = 1;
            break;
        }
        x++;
    }

    x = 0;
    for(; l < n-1; l++){
        if(v[l] <= k) qt1--;
        else qt1++;

        if((qt1 == 0 && x) || qt1 < 0){
            foi2 = 1;
            break;
        }
        x++;
    }
    

    if(foi1 or foi2){
        cout<<"YES\n";
    }
    else cout <<"NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}