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

void solve(){
    int n, h; 
    cin>>n>>h;

    vi v(n);
    rep(i,0, n) cin>>v[i];

    vector<vector<ll>> fut(n, vector<ll>(n, 0));

    ll res = 0;

    // cout<<"FUT\n";
    rep(i, 0, n){
        ll acum3 = 0;
        int mxx = v[i];
        rep(j, i+1, n){
            mxx = max(mxx, v[j]);
            acum3 += h-mxx;
            fut[i][j] = acum3;
        }
        // cout<<fut[i]<<" ";
    }
    // cout<<"\n";


    ll acum = 0;
    deque <pii> minq;
    minq.push_back({h, -1});
    int ptr1 = 0;
    rep(i, 0, n){
        acum += h - v[i];
        while(!minq.empty() and minq.back().ff <= v[i]){
            auto [h2, id2] = minq.back();
            minq.pop_back();
            if(v[i] > h2){
                auto [htras, idtras] = minq.back();
                acum -= (min(htras, v[i]) - h2) * (i - idtras-1);
            }
        }
        minq.push_back({v[i], i});
        // cout<<acum<<"\n";
        res = max(res, acum);

        ll acum2 = 0;
        deque <pii> minq2;
        minq2.push_back({h, i});

        pii mx = {v[i], i};

        rep(j, i+1, n){
            mx = max(mx, make_pair(v[j], j));
            acum2 += h - v[j];
            while(!minq2.empty() and minq2.back().ff <= v[j]){
                auto [h2, id2] = minq2.back();
                minq2.pop_back();
                if(v[j] > h2){
                    auto [htras, idtras] = minq2.back();
                    acum2 -= (min(htras, v[j]) - h2) * (j - idtras-1);
                }
            }
            minq2.push_back({v[j], j});

            ll aux  = acum+ fut[j][n-1] + fut[i][mx.ss] + acum2 - ((h-mx.ff) * (mx.ss - i));
            // cout<<"i = "<<i<<", j = "<<j<<" -> "<<aux<<"\n";
            // cout<<acum<<" "<<acum2<<" "<<fut[j]<<"\n";
            res = max(res, aux);
        }
    }
    cout<<res<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}