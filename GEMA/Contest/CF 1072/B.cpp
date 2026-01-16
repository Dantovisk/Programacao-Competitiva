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
    int s, k, m;
    cin>>s>>k>>m;

    if(s <= k){
        int a = m%k;
        cout<<max(0, s-a)<<"\n";
    }
    else{
        int uai = s-k;

        int fase = m/k;

        if(fase % 2 ==1){
            uai = 0;
        }

        cout<<(k-(m%k)) + uai<<"\n";
    }
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}