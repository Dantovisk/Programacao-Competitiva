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

    map<string, string> mp; // Mapeia IP para o nome do servidor

    rep(i, 0, n){
        string nm, ip;
        cin>>nm>>ip;

        mp[ip] = nm;
    }

    rep(i, 0, m){
        string nm, ip;
        cin>>nm>>ip;

        cout<<nm<<" "<<ip;

        // Remove o caractere ';' do final do IP para realizar a busca no mapa
        string key = ip.substr(0, sz(ip)-1);

        // Busca o nome correspondente e imprime como comentário
        cout<<(mp.find(key) != mp.end() ? (" #" + mp[key]) : "")<<"\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    rep(i, 0, t){
        // cout<<"Case: "<<i+1<<": ";
        solve();
    }

}