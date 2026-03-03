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
    cin>>n>>m; // n = moedas de valor 1, m = moedas de valor 2

    // Se a quantidade de moedas de valor 2 é ímpar, precisa de duas moedas de valor 1 para compensar
    if(m %2) n-= 2;

    // Verifica se restaram moedas de valor 1 suficientes e se a soma delas é par
    if(n < 0 || n%2) cout<<"NO\n";
    else cout<<"YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    rep(i, 0, t){
        // cout<<"Case: "<<i+1<<": ";
        solve();
    }

}