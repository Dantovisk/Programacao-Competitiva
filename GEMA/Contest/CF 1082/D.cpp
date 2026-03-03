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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n, m; 
    cin>>n>>m;

    int mx = n+m+1;
    vi div(mx+2, 0);
    vi ndiv(mx+2, 1);

    vi a(n), b(m);
    rep(i,0, n) cin>>a[i];
    rep(i,0, m) cin>>b[i];

    sort(all(a));
    sort(all(b));

    for(auto x: a){
        if(div[x]) continue;
        for(int i = x; i<= mx; i+=x){
            div[i] = 1;
        }
    }

    //contagem de jogadas 1;
    int ct1 = 0;

    //contagem de jogadas do 2;
    int ct2 = 0;

    for(auto x: b){
        if(div[x]) ct1++;
    }
    
    reverse(all(a));

    set<int> falta;
    for(int i = a[0]; i<= mx; i+=a[0]){
        falta.insert(i);
    }
    reverse(all(a));
    int lasttt = -1;

    rep(i, 0, n){
        if(lasttt == a[i]) continue;
        // if(falta.find(a[i]) != falta.end()) continue;
        // set<int> curr;
        auto ptr = falta.begin();
        while(ptr != falta.end()){
            if((*ptr) % a[i] != 0){
                ptr = falta.erase(ptr);
            } 
            else{
                ptr ++;
            }
        }
        lasttt = a[i];
    }
    for(auto k: falta) ndiv[k] = 0;


    rep(i, 0, m) if(ndiv[b[i]]) ct2++;

    // cout<<"ct: "<<ct1<<", "<<ct2<<"\n";

    int excl1 = m -ct2;
    int excl2 = m - ct1;

    if((m - excl1 - excl2) % 2) excl1++;

    if(excl1 > excl2) cout<<"Alice\n";
    else cout<<"Bob\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}