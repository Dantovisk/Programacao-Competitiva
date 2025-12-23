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




void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> v;

    for(int i = 0; i< (1<<n); i++){
        int cont = 0;
        rep(j, 0, 20){
            if(!((1<<j)&i))break;
            cont++;
        }
        v.push_back({-cont, i});
    }

    sort(all(v));

    for(auto[x, a] : v) cout<<a<<" ";
    
    cout<<"\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}