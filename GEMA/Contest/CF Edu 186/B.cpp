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
    int a, b;
    cin>>a>>b;

    if(a < b) swap(a, b);

    int res = 0;
    int x1 = 0, x2 = 0;
    rep(i, 0, 22){
        if(i % 2) x1 += (1<<i);
        else x2 += (1<<i);

        if(x1 > x2){
            if(x1 > a || x2 > b) break;
        }
        else{
            if(x2 > a || x1 > b) break;
        }
        res++;
    }

    cout<<res<<"\n";

    // int mxa = 0, mxb = 0;

    // rep(i, 1, 22){
    //     if((1<<i)-1 <= a) mxa = i; 
    // }
    // rep(i, 1, 22){
    //     if((1<<i)-1 <= b) mxb = i; 
    // }

    // if(mxa < mxb) swap(mxa, mxb);
    // mxa = min(mxb + 1, mxa);

    // cout<<mxa+mxb<<"\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}