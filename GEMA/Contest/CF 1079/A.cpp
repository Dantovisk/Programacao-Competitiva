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

    int curr = n;
    int res = 0;

    
    while(1){
        int a = curr;
        int sum= 0;
        while(a){
            sum += a%10;
            a/=10;
        }

        if(curr-sum == n) res++;
        else if(curr-sum > n){
            break;
        }

        curr++;
    }

    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}