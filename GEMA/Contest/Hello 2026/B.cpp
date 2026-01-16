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
    cin>>n >> k;

    
    vi v(n), cont(n+3, 0);
    rep(i, 0, n) cin>>v[i];

    rep(i, 0, n){
        cont[v[i]]++;
    }

    int foi = 0;
    int max = k;
    rep(i, 0, k){
        if(cont[i] == 0){
            max = i;
            break;
        }
    }
    rep(i, k, n){
        if(cont[i]) {
            foi =1;
            break;
        }
    }

    if(max < k){
        cout<<max<<"\n";
    }else{
        cout<<max-1<<"\n";
    }

    // int st = 0;
    // int best = 0;
    // int mex = 0;
    // while(cont[best] > 0) best++;
    // mex = best;

    // for(int i = 1; i < n-k+1; i++){
    //     cont[v[i]]--;
    //     cont[v[i+k]]++;
    //     if(cont[v[i]] == 0){
    //         mex = min(mex, v[i]);
    //     }
    //     while(cont[mex] > 0) mex++;

    //     if(best < mex){
    //         st = i;
    //         best = mex;
    //     }
    // }

    // cout<<st<<" "<<mex<<"\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}