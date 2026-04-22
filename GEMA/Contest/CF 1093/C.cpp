#include <bits/stdc++.h>
using namespace std;

#define int long long

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
int n, m; 
int mx;

int bb(int i){
    int l = 1, r = mx+1;
    int tot = n + (2LL*m);

    while(l < r){
        int mid = (l+r)/2;
        // cout<<"t: "<<i<<" "<<mid<<"\n";

        int cost = (i+1)*(mid) + (i)*(mid+1);
        // cout<<"cost = "<<cost<<"\n";
        if(cost > tot){
            r = mid;
            continue;
        }
        else if(cost == tot){
            if(i == mid){
                return mid;
            }
            // return mid;

            // int u = min(n, m);
            // int qt = 2LL *(u + 1) * u;

            int v = abs(i-mid);
            // cout<<"v ="<<v<<"\n";
            if(n >= v){
                return mid;
            }
            else{
                return -1;
            }

        }
        else{
            l = mid+1;
        }
    }

   return -1;
}

void solve(){
    cin>>n>>m;
    mx = n+m;

    for(int i = 1; i*i<= mx; i++){
        int k = bb(i);
        if(k != -1){
            cout<<i<<" "<<k<<"\n";
            return;
        }
    }

    cout<<"-1\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}