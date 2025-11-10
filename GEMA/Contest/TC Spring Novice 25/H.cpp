#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dp[5000010];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, q;
    cin>>n>>q;

    vi fib(n), psum(n+1, 0);
    fib[0] = fib[1] = 1;
    rep(i, 2, n) fib[i] = fib[i-1] + fib[i-2];

    rep(i, 1, n) psum[i] = fib[i-1] + psum[i-1];
    psum[n] = psum[n-2]+1;

    sort(all(psum));

    fill(dp+1, dp+5000008, 10000000);
    dp[0] = 0;

    for(int i= 0; i <= 5000000; i++){
        for(auto k: psum){
            if(i+k > 5000000) continue;
            dp[i+k] = min(dp[i+k], dp[i]+1);
        }
    }

    while(q--){
        int x;
        vi f(n);
        cin>>f[0]>>f[1]>>x;

        rep(i, 2, n) f[i] = f[i-1] + f[i-2];

        int sum = 0;
        rep(i, 0, n) sum += f[i];

        int diff = x - sum;

        if(diff < 0){
            cout<<"-1\n";
            continue;
        }

        cout<<dp[diff]<<"\n";
    }

}