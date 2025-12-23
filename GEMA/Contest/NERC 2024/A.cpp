#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, m; 
    cin>>n>>m;
    string a; cin>>a;
    set<char> vis;
    //n eh oq queremos
    
    for(auto c: a) vis.insert(c);

    string res = "";

    rep(i, 0, 26){
        if(res.size() == n) break;
        if(vis.find('a'+i) == vis.end()){
            res.push_back('a'+i);
        }
    }
    rep(i, 0, 26){
        if(res.size() == n) break;
        if(vis.find('A'+i) == vis.end()){
            res.push_back('A'+i);
        }
    }
    rep(i, 0, 10){
        if(res.size() == n) break;
        if(vis.find('0'+i) == vis.end()){
            res.push_back('0'+i);
        }
    }

    if(res.size() == n){
        cout<<res<<"\n";
    }else cout<<"-\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;cin>>n;
    rep(i, 0, n){
        solve();
    }
}