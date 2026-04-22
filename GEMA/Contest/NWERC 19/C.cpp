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

const int MAX = 2e5+3;
const int inf = 1e9+7;

vi dp[3010][2];
int pos[3010][2];

void solve(){
    int n;
    cin>>n;

    vector<pii> v(n+1);
    vi p;
    rep(i,0,n){
        int a, b;
        cin>>a>>b;
        v[i+1] = {a, b};
    }

    int k; cin>>k;
    rep(i, 0, k){
        int b; cin>>b;
        p.pb(b);
    }

    int j = 0;
    int carry = 0;

    pos[0][0] = 1;

    rep(i, 1, n+1){
        if(j) j--;

        int ct = carry;
        auto [l, r] = v[i];

        // fr, ja tem por padrao
        int fl = 0, fr = 0;
        //colado no da direita
        int col = 0;

        vi bag;
        while(j < k and l > p[j]){
            j++;
        } 
        while(j < k and r >= p[j]){
            bag.pb(p[j]);
            j++;
        } 
        
        if(sz(bag) and bag.back() == r){
            fr =1;
        }
        if(sz(bag) and bag[0] == l){
            fl = 1;
        }
        if(i < n and (v[i].ss == v[i+1].ff)){
            col = 1;
        }

        if(sz(bag) > 2){
            cout<<"impossible\n"; return;
        }
        if(sz(bag) == 2){
            if(pos[i-1][0]){
                dp[i][0] = dp[i-1][0];
                pos[i][0] = 1;
            }
        }
        if(sz(bag) == 1){
            int pode = (col and (!fr));

            if(pos[i-1][0]){
                // add fora do proibido
                rep(u, l+1, r){
                    auto ptr = lower_bound(all(p), u);
                    if(ptr == p.end() or (*ptr) != u){

                        ///tinha algo aq?
                        dp[i][0] = dp[i-1][0];
                        dp[i][0].pb(u);
                        pos[i][0] = 1;
                        break;
                    }
                }

                if(pode){
                    dp[i][1] = dp[i-1][0];
                    dp[i][1].pb(r);
                    pos[i][1] = 1;
                }
            }

            //add antes
            if(pos[i-1][1]){
                if(pos[i][0]){
                    if(dp[i][0].size() > sz(dp[i-1][1])){
                        dp[i][0] = dp[i-1][1];
                        
                    }
                }
                else dp[i][0] = dp[i-1][1];
                pos[i][0] = 1;
            }
        }
        if(sz(bag) == 0){

            if(pos[i-1][1]){
                int pode = (col and (!fr));
                
                // add fora do proibido
                rep(u, l+1, r){
                    auto ptr = lower_bound(all(p), u);
                    if(ptr == p.end() or (*ptr) != u){
                        dp[i][0] = dp[i-1][1];
                        dp[i][0].pb(u);
                        pos[i][0] = 1;
                        break;
                    }
                }

                if(pode){
                    dp[i][1] = dp[i-1][1];
                    dp[i][1].pb(r);
                    pos[i][1] = 1;
                }
                
            }

            if(pos[i-1][0]){
                int pode = (col and (!fr));
                int prim = 0;
                rep(u, l+1, r){
                    auto ptr = lower_bound(all(p), u);
                    if(ptr == p.end() or (*ptr) != u){
                        prim = u;
                        break;
                    }
                }
                int sec = 0;
                rep(u, prim+1, r){
                    auto ptr = lower_bound(all(p), u);
                    if(ptr == p.end() or (*ptr) != u){
                        sec = u;
                        break;
                    }
                }

                if(!pos[i][0] or (pos[i][0] and(sz(dp[i][0]) > sz(dp[i-1][0]) + 2))){
                    dp[i][0] = dp[i-1][0];
                    dp[i][0].pb(prim);
                    dp[i][0].pb(sec);

                    pos[i][0] = 1;
                }

                if(pode){
                    if(!pos[i][1] or (pos[i][1] and(sz(dp[i][1]) > sz(dp[i-1][0]) + 2))){
                        dp[i][1] = dp[i-1][0];
                        dp[i][1].pb(prim);
                        dp[i][1].pb(r);
    
                        pos[i][1] = 1;
                    }
                }
                
            }

        }

        // cout<<"DP de "<<i<<"\n";
        // cout<<"possivel? "<<(pos[i][0]? "YES": "NO")<<"\n";
        // cout<<dp[i][0].size()<<"\n";
        // for(auto ks : dp[i][0]) cout<<ks<<" ";
        // cout<<"\n";

        // cout<<dp[i][1].size()<<"\n";
        // cout<<"possivel? "<<(pos[i][1]? "YES": "NO")<<"\n";
        // for(auto ks : dp[i][1]) cout<<ks<<" ";
        // cout<<"\n";

    }

    if(!pos[n][0] && !pos[n][1]){
        cout << "impossible\n";
        return;
    }

    int x = dp[n][0].size();
    int y = dp[n][1].size();
    if(!pos[n][0]) x += 100000;
    if(!pos[n][1]) y += 100000;

    // cout<<x<<" "<<y<<"\n";

    if(x < y){
        cout<<dp[n][0].size()<<"\n";
        for(auto ks : dp[n][0]) cout<<ks<<" ";
        cout<<"\n";
    }
    else{
        cout<<dp[n][1].size()<<"\n";
        for(auto ks : dp[n][1]) cout<<ks<<" ";
        cout<<"\n";
    }

    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}