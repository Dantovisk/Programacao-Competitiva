#include <bits/stdc++.h>  // F. Yet Another Minimization Problem - CF

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5+7;
const ll inf = 1e18+7;

int n, m;
int v[MAX];
ll dp[MAX][25];


// Sliding Window
ll sum = 0;
int cont[MAX];
int currL = 1, currR = 0;

void add(int idx){
    sum += cont[v[idx]];
    cont[v[idx]]++;
}

void remove(int idx) {
    cont[v[idx]]--;
    sum -= cont[v[idx]];
}

void updt(int l, int r) {
    while (currL > l) {
        currL--;
        add(currL);
    }
    while (currR < r) {
        currR++;
        add(currR);
    }
    while (currL < l) {
        remove(currL);
        currL++;
    }
    while (currR > r) {
        remove(currR);
        currR--;
    }
}

// Arrumaar depois, codar sliding window
void solve(int k, int st, int ed, int l, int r){
    int mid = (st+ed)/2;
    pair<ll, int> best = {inf, -1};

    for(int i = min(mid, r); i>=l; i--){
        updt(i, mid);

        // cout<<"freq: "<<v[i]<<" = "<<freq[v[i]]<<"\n";

        ll cost = sum + dp[i-1][k-1];
        best = min(best, {cost, i});
    }

    dp[mid][k] = best.first;

    if(st == ed) return;

    solve(k, st, mid, l, best.second);
    solve(k, mid+1, ed, best.second, r);
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        cin>>v[i];
        dp[i][0] = dp[i-1][0] + cont[v[i]];
        cont[v[i]]++;
        currR++;        
    }
    sum = dp[n][0];

    for(int i = 1; i<m; i++){
        dp[0][i] = inf;
        for(int j = 0; j<=n; j++){
            dp[j][i] = inf;
        }
    }


    for(int i = 1; i<m; i++){
        solve(i, 1, n, i, n);
    }   

    cout<<dp[n][m-1]<<"\n";
}