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

const int maxn = 2e5+4;
const int inf = 1e9+3;
typedef __int128_t ld;

int dp[1010][110];
ld v[1010];

int r, n;

ld rot(ld a, int k){
    k = (k+n)%n;
    ld u = (a>>k);
    ld x = a;
    
    ld aux = 1;
    aux <<= k;
    x = ((aux-1) & x);

    u += (x << (n-k));
    return u;
}

ld conv(string a){
    ld x = 0;
    for(auto c: a){
        x<<=1;
        x+=(c-'0');
    }
    return x;
}

void prt(ld a){
    for(int i = n-1; i>= 0; i--){
        if((1LL<<i)&a) cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";
}

void solve(){
    cin>>r>>n;

    string a;
    cin>>a;
    
    rep(i, 0, r){
        string b;
        cin>>b;
        
        v[i] = conv(b);
    }

    rep(z, 0, 2){
        ld base = conv(a);
        memset(dp, 0, sizeof(dp));

        queue<pii> q;
    
        // cout<<"\n";
        rep(i, 0, n){
            if(!(rot(base, i) & v[0])){
                // prt(rot(v[0], 0));
                // prt(rot(base, i));
                dp[0][i] = 1;
                q.push({0, i});
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            if(!dp[i][(j-1+n)%n] and !(v[i] & rot(base, j-1))){
                dp[i][(j-1+n)%n] = 1;
                q.push({i, (j-1+n)%n});
            }
            if(!dp[i][(j+1+n)%n] and !(v[i] & rot(base, j+1))){
                dp[i][(j+1+n)%n] = 1;
                q.push({i, (j+1+n)%n});
            }

            if(i<r-1 and !dp[i+1][j] and !(v[i+1] & rot(base, j))){
                dp[i+1][j] = 1;
                q.push({i+1, j});
            }

            if(i>0 and !dp[i-1][j] and !(v[i-1] & rot(base, j))){
                dp[i-1][j] = 1;
                q.push({i-1, j});
            }
                
        }

        // rep(i, 0, r-1){
        //     rep(j, 0, n){
        //         if(!dp[i][j]) continue;

        //         if(!(v[i+1] & rot(base, j))){
        //             dp[i+1][j] = 1;
                
        //             rep(k, 1, n){
        //                 if(!(v[i+1] & rot(base, j+k))){
        //                     dp[i+1][(j+k+n)%n] = 1;
        //                 }
        //                 else break;
        //             }
        //             rep(k, 1, n){
        //                 if(!(v[i+1] & rot(base, j-k))){
        //                     dp[i+1][(j-k+n)%n] = 1;
        //                 }
        //                 else break;
        //             }
        //         }
                
        //     }
        // }
        rep(i, 0, n){
            if(dp[r-1][i]){
                cout<<"Y\n";
                return;
            }
        }

        reverse(all(a));
    }
    cout<<"N\n";
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}