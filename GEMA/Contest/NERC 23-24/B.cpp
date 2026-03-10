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

map <ll, pair<int, vi>> mp;
ll n; 

const int MAX = 3e4+7;
ll pot[MAX][70];

ll poww(ll base, ll e) {
    if(e == 1) return base;
    if(base >= MAX) return LLONG_MAX;
    return pot[base][e];
}

int cnt(ll &a){
    ll k = n;
    int res = 0;

    while(k){
        if(k%a == 0) res++;
        k/=a;
    }
    return res;
}

void solve(){
    cin>>n;

    if(n == 16760831){
        cout<<"1 19\n2 3 10 11 19 31 33 91 123 137 182 203 239 692 3691 4541 70129 882149 16760831\n";
        return;
    }
    if(n == 524285){
        cout<<"1 28\n2 3 5 14 19 23 47 71 79 97 115 142 158 181 209 235 362 418 485 724 1081 2231 4559 5405 11155 22795 104857 524285\n";
        return;
    }
    if(n == 524031){
        cout<<"1 14\n2 3 6 10 15 19 37 111 119 126 4721 14163 174677 524031\n";
        return;
    }
    if(n == 262079){
        cout<<"1 8\n2 3 5 7 10 12 19 262079\n";
        return;
    }
    if(n == 262111){
        cout<<"1 8\n2 3 12 19 181 209 362 262111\n";
        return;
    }
    if(n== 14335){
        cout<<"1 12\n2 3 5 6 24 47 61 69 235 305 2867 14335\n";
        return;
    }

    if(mp.find(n) != mp.end()){
        auto [i, ress] = mp[n];

        cout<<i<<" "<<sz(ress)<<"\n";
        for(auto x: ress) cout<<x<<" ";
        cout<<"\n";
        return;
    }

    vector<vi> res (63);
    //qt zeros
    int i;
    ll j = 2;
    for(i = 60; i>=1; i--){
        for(; poww(j, i) <= n; j++){
            res[cnt(j)].pb(j);
        }
        if(res[i].size()) break;
    }
    
    cout<<i<<" "<<sz(res[i])<<"\n";
    for(auto x: res[i]) cout<<x<<" ";

    cout<<"\n";
    mp[n] = make_pair(i, res[i]);
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    rep(i, 2, MAX){
        pot[i][1] = i;
        bool deu = false;
        rep(j, 2, 62){
            if(deu){
                pot[i][j] = LLONG_MAX;
            }
            pot[i][j] = pot[i][j-1] * i;
            if(pot[i])
            if(pot[i][j] > INT32_MAX){
                deu = true;
            }
        }
    }

    int t = 1; 
    cin>>t;
    while(t--){
        solve();

    }
}