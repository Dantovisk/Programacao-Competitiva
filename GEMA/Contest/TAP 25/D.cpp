#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define ff first
#define ss second

map<string, vector<pii>> trump;
vector<pii> base;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin>>n>>m;

    int tot = 0;
    int last = 0;
    base.push_back({0, 0});

    rep(i, 0, n+m){
        int x, y;
        string a, b;
        cin>>x>>a>>y>>b;
        if(a == b){
            int dir = (x > y? 0: 1);
            base.pb({i, dir});

            last = dir;
            if(trump.find(b) == trump.end()) trump[b] = {};
        }
        else{
            trump[a].pb({i, 0});
            trump[b].pb({i, 1});
        }
        if(last == 0) tot ++;
    }
    base.push_back({n+m, 0});
    // cout<<"TOTAL: "<<tot<<"\n\n";
    
    for(auto [tr, v] : trump){
        pii esq = {0, 0};
        int curr = tot;
        int rmog = 0;

        rep(uwu, 0, v.size()){
            auto [id, dir] = v[uwu];

            if(id > rmog){
                if(esq.second == 0) {
                    curr += rmog - esq.ff;
                    // cout<<"Fechei ciclo: +"<<rmog - esq.ff<<"\n";
                } 
            }
            auto ub = upper_bound(all(base), make_pair(id, 0));
            auto lb = ub; lb--;
            // cout<<"Trump: "<<id<<" "<<dir<<"\n";

            pii l = *lb, r = *ub;
            esq = max(l, esq);

            if(rmog != r.first){
                if(l.second == 0) {
                    curr -= r.ff - l.ff;
                    // cout<<"tirei! -("<<r.ff <<" - "<<l.ff<<") = -"<<r.ff - l.ss<<"\n";
                }
            }

            if(esq.second == 0){
                curr += id - esq.first;
                // cout<<"fui de: "<<esq.ff<<" -> "<<id<<" = +"<<id - esq.first<<"\n";
            }

            esq = {id, dir};
            rmog = r.first;

            if(uwu == sz(v) - 1){
                if(esq.second == 0){
                    curr += rmog - esq.ff;
                    // cout<<"Fechei ciclo: +"<<rmog - esq.ff<<"\n";
                }
            }
        }
        // cout<<"Curr p/ "<<tr<<" = "<<curr<<"\n";
        if(curr == n){
            cout<<tr<<"\n";
            return 0;
        }
    }

    cout<<"*\n";
}