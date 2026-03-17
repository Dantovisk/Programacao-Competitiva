#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, vector<pii>> mp;
int v[1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    rep(i, 0, n) cin>>v[i];

    rep(i, 0, n){
        rep(j, i+1, n){
            if(v[i]+v[j] > k) continue;
            mp[v[i]+v[j]].push_back({i, j});
        }
    }

    rep(i, 0, n){
        rep(j, i+1, n){
            if(v[i]+v[j] > k) continue;
            int curr = v[i]+v[j];
            int falta = k - (v[i]+v[j]);

            if(falta == curr){
                for(auto [x, y] : mp[curr]){
                    if(x != i and x != j and y != j and y != i){
                        cout<<i+1<<" "<<j+1<<" "<<x+1<<" "<<y+1<<"\n";
                        return 0;
                    }
                }
                continue;
            }
            if(mp.find(falta) != mp.end()){
                for(auto [x, y] : mp[falta]){
                    if(x != i and x != j and y != j and y != i){
                        cout<<i+1<<" "<<j+1<<" "<<x+1<<" "<<y+1<<"\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"IMPOSSIBLE\n";
    
    return 0;
}
