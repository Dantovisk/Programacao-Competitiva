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

void solve(){
    ll n, m, k;
    cin>>n>>m>>k;

    ll sobra = k;

    int res = 0;

    vi box(m);
    rep(i, 0, m) cin>>box[i];
    sort(all(box));

    // caixas, valor
    vector<pii> caras;

    rep(i, 0, n){   
        int x, y, z;
        cin>>x>>y>>z;

        sobra -= y;
        caras.push_back({x, z-y});
    }

    sort(all(caras));

    //caras ativos por {valor, caixas}
    priority_queue<pii> act;

    int id = 0;
    for(auto c: box){
        while(id < n && caras[id].first <= c){
            act.push({caras[id].ss, caras[id].ff});
            id++;
        }

        if(!act.empty()){
            act.pop(); //tira o cara com maior valor;
            res++;
        }
    }

    while(id < n){
        act.push({caras[id].ss, caras[id].ff});
        id++;
    }

    //valores
    vector<int> v;
    while(!act.empty()){
        auto [val, c] = act.top();
        act.pop();
        v.push_back(val);
    }

    sort(all(v));

    for(auto x: v){
        if(x <= sobra){
            sobra -= x;
            res++;
        }
        else break;
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