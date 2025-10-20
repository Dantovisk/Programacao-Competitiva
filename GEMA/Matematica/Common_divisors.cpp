#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e6+5;

int vis[MAX];



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    vector<int> v(N);

    rep(i, 0, N){
        cin>>v[i];
    }

    int res = 1;

    rep(i, 0, N){
        int n = v[i];
        vector<int> factors;
        // cout<<"num: "<<n<<"\n";

        int mx = 1;

        for(int i = 1; i * i <= n; i++){
            if(n%i == 0) factors.push_back(i);
        }

        for(auto f: factors){
            if(vis[f] == 1){
                mx = max(f, mx);
            }
            if(n % f == 0) {
                if(vis[n/f]) mx = max(mx, n/f);
                vis[n/f] = 1; 
            }
            vis[f] = 1;
        }
        res = max(res, mx);
    }

    cout<<res<<"\n";

}