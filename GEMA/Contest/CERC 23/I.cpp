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

void solve(){
    int n; cin>>n;

    cout<<"QUERY ";
    rep(i, 0, n) cout<<"1";
    cout<<endl;

    vi st (n);
    rep(i, 0, n) cin>>st[i];
    
    vector<vi> v;
    for(int i = 0; (1<<i)< n; i++){
        vi aux(n);
        cout<<"QUERY ";
        rep(j, 0, n){
            if(j & (1<<i)){
                cout<<"1";
            } else{
                cout<<"0";
            }
        }
        cout<<endl;

        rep(i, 0, n) cin>>aux[i];
        v.push_back(aux);
    }

    queue <int> vis;
    rep(i, 0, n){
        if(st[i] == 1) vis.push(i);
    }

    int k = v.size();

    vector<pii> res;

    while(!vis.empty()){
        int u = vis.front();
        vis.pop();
        // cout<<"\nTo em "<<u+1<<"\n";

        if(res.size() == n-1) continue;

        int id = 0;
        rep(i, 0, k){
            // cout<<"v["<<u+1<<"]["<<i<<"] = "<<v[i][u]<<"\n";            
            if(v[i][u]) id += (1<<i);
            v[i][u] = 0;
        }
        
        // cout<<"====> id ="<<id+1<<'\n';
        rep(i, 0, k){
            if((1<<i) & u) v[i][id]--;
        }
        
        st[u] = 0;
        st[id] --;
        if(st[id] == 1) vis.push(id);

        res.pb({u, id});

        // cout<<u<<":"<<endl;
        // rep(i, 0, n) cout<<st[i]<<" ";
        // cout<<endl;
    }

    cout<<"ANSWER"<<endl;
    for(auto [u, w] : res){
        cout<<u+1<<" "<<w+1<<endl;
    }

}

int main() {
    int t = 1;
    // cin>>t;

    while(t--) solve();
}