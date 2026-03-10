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

// pode[i][j][k] define se dá pra zerar a pilha
// usando a[i, ... i+k-1] e b[j, ... j+k-1]
int pode[102][102][102];
int par [102][102][102];

void ret(int i, int j, int s){
    if(s == 1){
        cout<<"SC";
        return;
    }

    cout<<"S";
    int k = par[i][j][s];
    if(k > 0){
        ret(i+1, j, k);
    }
    cout<<"C";
    if(k < s-1){
        ret(i+1+k,j+1+k,s-k-1);
    }
}

void solve(){
    int n; cin>>n;

    vi a(n), b(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    rep(i, 0, n){
        cin>>b[i];
    }

    for(int i = 0; i<=n; i++)
        for(int j = 0; j<=n; j++)
            pode[i][j][0] = 1;

    for(int s = 1; s <= n; s++){
        for(int i = 0; i<(n-s+1); i++){
            for(int j = 0; j<(n-s+1); j++){
                if(s == 1){
                    if(a[i] == b[j]) pode[i][j][s] = 1;
                    // cout<<"pode["<<i<<"]["<<j<<"]["<<s<<"] = "<<pode[i][j][s]<<"\n";
                    continue;
                }

                rep(k, 0, s){
                    bool deu = true;
                    if(a[i] != b[j+k]) deu = false;
                    else if(k > 0 and (!pode[i+1][j][k])){
                        deu = false;
                    }
                    else if(k < s-1){
                        if(!pode[i+1+k][j+1+k][s-k-1]) deu = false;
                    }
                    if(deu){
                        pode[i][j][s] = 1;
                        par[i][j][s] = k;
                        break;
                    }
                }
                // cout<<"pode["<<i<<"]["<<j<<"]["<<s<<"] = "<<pode[i][j][s]<<"\n";
            }
        }
    }
    if(pode[0][0][n]){
        cout<<"YES\n";
        ret(0, 0, n);
        cout<<"\n";
    }else{
        cout<<"NO\n";
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;
    while(t--){
        solve();

    }
}