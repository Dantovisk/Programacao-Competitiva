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

const int MAXN = 2e5 + 7;

//se um mog[i][j] significa v[i] < v[j] 
vi mog[MAXN];

void solve(){
    int n; cin>>n;
    vi v(n), grau(n, 0); 

    list<pii> ls;

    rep(i, 0, n+1){
        mog[i].clear();
    }
    
    rep(i, 0, n) {
        cin>>v[i];
        ls.push_back({v[i], i});
    }
    
    int mx = *max_element(all(v));
    for(int k = 1; k<= mx; k++){
        auto ptr = ls.begin();
        int offset = 0; 

        while(ptr != ls.end()){
            auto [u1, id1] = *ptr;
            if(u1 != k) {
                ptr++;
                offset = 1;
                continue;
            }

            if(ptr != ls.begin()){
                auto ptr2 = ptr;
                ptr2--;

                auto [u2, id2] = *ptr2;

                if(u2 != k){
                    if(k % 2) swap(id1, id2);
    
                    mog[id1].push_back(id2);
                    grau[id2]++;
    
                    if(k % 2) swap(id1, id2);
                    
                }
            }


            auto ptr2 = ptr;
            ptr2++;
            if(ptr2 != ls.end()){
                auto [u2, id2] = *ptr2;

                if(u2 != k){
                    if(k % 2) swap(id1, id2);
    
                    mog[id1].push_back(id2);
                    grau[id2]++;
    
                    if(k % 2) swap(id1, id2);
                }

                else{
                    if((k + offset) % 2) swap(id1, id2);
    
                    mog[id1].push_back(id2);
                    grau[id2]++;
    
                    if((k+ offset) % 2) swap(id1, id2);
                }
            }

            ptr++;
        }

        ptr = ls.begin();
        while(ptr != ls.end()){
            auto [u1, id1] = *ptr;
            if(u1 != k) {
                ptr++;
                continue;
            }
            ptr = ls.erase(ptr);
        }
    }

    queue<int> nxt;
    rep(i, 0, n){
        if(grau[i] == 0) nxt.push(i);
    }
    
    vi resp;
    while(!nxt.empty()){
        auto u = nxt.front();
        nxt.pop();

        resp.push_back(u);
        for(auto x: mog[u]){
            grau[x]--;
            if(!grau[x]) nxt.push(x);
        }
    }
    vi res(n, -1);

    rep(i, 0, sz(resp)){
        res[resp[i]] = i;
    }

    for(auto x: res) cout<<x+1<<" ";
    cout<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}