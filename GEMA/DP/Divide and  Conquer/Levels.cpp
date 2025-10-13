#include <bits/stdc++.h>  // E. Levels and Regions - CF

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 2e5+7;

int n, m;
double v[MAX];
double dp[MAX][55];

double pref[MAX], inv[MAX], sum[MAX];
const double inf = 1e16+7;

void solve(int k, int st, int ed, int l, int r){
    int mid = (st + ed)/2;
    // cout<<k<<" "<<st<<" "<<ed<<" "<<l<<" "<<r<<"\n";
    pair <double, int> best = {inf, -1};
    for(int i = l; i<= min(r, mid); i++){
        double cost = dp[i-1][k-1] + pref[mid] - pref[i-1] 
        - (inv[mid] - inv[i-1])*sum[i-1];
        best = min(best, {cost, i});
        // cout<<cost<<" ";
    }
    dp[mid][k] = best.first;
    // cout<<best.first<<"\n";

    if(st==ed) return;
    solve(k, st, mid, l, best.second);
    solve(k, mid+1, ed, best.second, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        cin>>v[i];
    }

    double acum = 0;
    for(int i = 1; i<=n; i++){
        sum[i] = sum[i-1] + v[i];
        inv[i] = inv[i-1] + 1.0/v[i];
        acum += v[i];
        pref[i] = pref[i-1] + acum/v[i];
        dp[i][0] = pref[i];
    }   

    for(int i = 1; i<m ; i++){
        solve(i, 1, n, i, n);
    }

    cout<<fixed<<setprecision(10);
    cout<<dp[n][m-1]<<"\n";
}