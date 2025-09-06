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
#define tii tuple<int, int, int>

const int MAX = 1e6+ 15;
const ll mod  = 1e9+7;

double dp[2*MAX];
double suff[2*MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r;
    cin>>n>>l>>r;
    double sz = 1.0 + r - l;

    for(int i = n-1; i>=0; i--){
        if(l > 0){
            double inter = suff[i+l] - suff[i+r+1];
            dp[i] += 1.0 + (1.0/sz)*inter;
        }
        else{
            double inter = suff[i+l+1] - suff[i+r+1];
            dp[i] = sz/(sz-1.0) + inter/(sz-1.0);
        }
        
        suff[i] = suff[i+1] +dp[i];
    }

    cout<<fixed<<setprecision(9);
    cout<<dp[0]<<"\n";

    return 0;
}