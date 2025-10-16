#include <bits/stdc++.h>  // Money for Nothing (ICPC World Finals)

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ff first
#define ss second

const int MAX = 5e5+7;
const ll inf = 1e18+7;

int n, m;
vector<pii> prod, cons;
vi consV, consH;

vi horB, verB;

// intervalo de busca de produtor, intervalo de busca do produtor
ll solve(int st, int ed, int l, int r){
    if(st > ed || l > r) return -1;

    int mid = (st+ed)/2;

    pair<ll, int> best = {-1, -1};

    //Estamos verificando, para o produtor mid, opt(mid) 
    // O dia de inicio é decrescente em prod
    for(int i= min(r, verB[mid]); i>= max(l, horB[mid]); i--){
        //A produção deve começar antes do dia da venda
        if(prod[mid].ss >= cons[i].ss || prod[mid].ff >= cons[i].ff) continue;

        ll cost = (ll)(cons[i].ff-prod[mid].ff)*(ll)(cons[i].ss - prod[mid].ss);
        if (cost > best.first) {
            best = {cost, i};
        }
    }

    if(st == ed) return best.ff;

    if(best.ss != -1){
        return max({best.ff, 
        solve(st, mid-1, l, best.ss),
        solve(mid+1, ed, best.ss, r)});
    }

    // Isso aqui dá TLE, preciso achar um jeito melhor
    return max({best.ff, 
        solve(st, mid-1, l, r),
        solve(mid+1, ed, l, r)});

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    vector<pii> v1, v2;

    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        v1.push_back({a, b});
    }

    for(int i = 1; i<=m; i++){ 
        int a, b;
        cin>>a>>b;
        v2.push_back({a, b});
    }

    sort(all(v1));
    
    int best  = 1e9+7;
    
    //ordem crescente de custo
    //cada cara i tem o menor inicio aparecido até agr (inicio decrescente)
    for(int i =0; i<n; i++){
        if(v1[i].second < best) {
            prod.push_back(v1[i]);
            best = v1[i].second;
        }
    }    

    sort(all(v2)); reverse(all(v2));
    best = -1;

    // ordem decrescente de valor
    //cada cara i tem o maior fim aparecido até agr
    for(int i =0; i<m; i++){
        if(v2[i].second > best) {
            cons.push_back(v2[i]);
            consV.push_back(v2[i].ss);
            consH.push_back(v2[i].ff);
            best = v2[i].second;
        }
    }
    reverse(all(cons));
    reverse(all(consH));


    if(prod.empty() || cons.empty()){
        cout << 0 << "\n";
        return 0;
    }

    // cout<<"Produtor\n";
    // for(auto [x, y] : prod) cout<<x<<" "<<y<<"\n";
    // cout<<"Consumidor\n";
    // for(auto [x, y] : cons) cout<<x<<" "<<y<<"\n";

    for(int i =0; i<prod.size(); i++){
        // cout<<"cost: "<<prod[i].ff<<" day start: "<< prod[i].ss<<"\n";
        int hb = upper_bound(all(consH), prod[i].ff) - consH.begin();
        int vb = upper_bound(all(consV), prod[i].ss) - consV.begin();
        // cout<<"hb: "<<hb<<" vb: "<< vb <<"\n";

        //Evita que saia dos limites do vetor
        horB.push_back(min(hb, (int)cons.size()-1));
        verB.push_back(max((int)cons.size() - vb - 1, 0));
        // cout<<"horB: "<<horB[i]<<" vb: "<< verB[i] <<"\n";
    }


    cout<<max(solve(0, prod.size()-1, 0, cons.size()-1), 0LL)<<"\n";

}