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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n; 
    cin>>n;

    string a; cin>>a;

    // vector<vi> dp(n+1, vi(n+1, 0));

    // rep(s, 2, n+1){
    //     rep(i, 0, n){
    //         int j = i+s-1;
    //         if(j > n) break;
    //         if(a[i] != a[j]) continue;
    //         if(i+1 > j-1){
    //             dp[i][j] = 1;
    //         }
    //         else if(dp[i+1][j-1]){
    //             dp[i][j] = 1;
    //         }
    //     }
    // }

    // cout<<(dp[0][n-1]? "YES\n" : "NO\n");


    stack<char> st;

    rep(i, 0, n){
        if(st.empty()) st.push(a[i]);
        else if(st.top() == a[i]){
            st.pop();
        }else{
            st.push(a[i]);
        }
    }
    cout<<(sz(st) == 0? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}