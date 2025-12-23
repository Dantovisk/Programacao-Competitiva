#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; 
    cin>>n;
    vector<string> v(n);
    rep(i, 0, n) cin>>v[i];

    // pair[qtd sobrando][soma][div]
    map <tuple<int,int, int>, int> vis;

    ll res = 0;

    rep(i, 0, n){
        // cout<<"atualizou\n";
        int sum = 0;
        for(auto c: v[i]) sum += (c-'0');
        vis[{v[i].size(), sum, 0}]++;

        for(int j = 0; j < v[i].size(); j ++){
            int diff = (v[i].size()-(j+1)) - (j+1);
            sum -= 2*(v[i][j] - '0');

            if(diff <= 0 || sum <= 0) break;
            vis[{diff ,sum, 1}] ++;
            // cout<<diff<<" "<<sum<<"\n";
        }
    }

    rep(i, 0, n){
        // cout<<"somei\n";
        int sum = 0;
        for(auto c: v[i]) sum += (c-'0');
        res += 2*vis[{v[i].size(), sum, 0}];
        res += 2*vis[{v[i].size(), sum, 1}];

        for(int j = v[i].size()-1; j > 0; j--){
            int diff = (j) - (v[i].size() - (j));
            sum -= 2*(v[i][j] - '0');

            if(diff <= 0 || sum <= 0) break;

            res += 2*vis[{diff, sum, 0}];
            // cout<<diff<<" "<<sum<<"\n";
        }
        
    }
    cout<<res/2<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n = 1;
    // cin>>n;
    rep(i, 0, n){
        solve();
    }
}