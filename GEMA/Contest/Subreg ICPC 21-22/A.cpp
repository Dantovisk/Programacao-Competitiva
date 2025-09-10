#include <bits/stdc++.h>    //Errado - Preciso aprender interpolação
using namespace std;      

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define tii tuple<int, int, int>

const int MAX = 5e3+ 15;
const ll mod  = 1e9+7;

int v[MAX], a[MAX], b[MAX];
int dp[MAX][MAX];

map <int, int> id;
int coord[MAX];
int psum[MAX];

int add(int a, int b){return (a+b)%mod;}
int mul(int a, int b){return ((ll)a*(ll)b)%(ll)mod;}
int sub(int a, int b){return ((a-b)+mod)%mod;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    cin>>n>>r;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    int mx  = 0;
    
    set<int> vals;
    vals.insert(0);

    for(int i=n; i > 0; i--){
        int u = mx = max(mx, v[i]);
        a[i] = r-u+1;

        vals.insert(a[i]);

        if(a[i] <=0 ){
            cout<<"0\n";
            return 0;
        }
    }

    //Compressão de coordenadas
    int i = 0;
    for(auto x: vals){
        coord[i] = x;
        id[x] = i;
        i++;
    }

    for(i =1; i<=n; i++) b[i] = id[a[i]];

    int u = b[n];
    psum[0] = 0;
    cout<<"setup: ";
    for(i = 1; i <=b[n]; i++){
        dp[n][i] = coord[i] - coord[i-1];
        cout<< dp[n][i]<<" ";
        psum[i] = add(psum[i-1], dp[n][i]);
    } cout<<"\n";

    for(i = n - 1; i> 0; i--){
        for(int j = 1; j<=b[i]; j++){
            cout<<" i j: "<<i<<" "<<j<<"\n";
            int diff = coord[j] - coord[j-1];
            dp[i][j] = mul(sub(psum[b[i+1]], psum[j]), diff);
            cout<<"prefixo: "<<dp[i][j]<<"\n";    

            ll s = (diff*(diff+1))/2LL;
            s %= (ll)mod;
            dp[i][j] = add(dp[i][j], s);
            cout<<"diff/dp: "<<diff<<" "<<dp[i][j]<<"\n";
        }
        for(int j = 1; j <=b[i]; j++){
            psum[j] = add(psum[j-1], dp[i][j]);
        }
    }

    for(i = b[n]; i>0; i--){
        for(int j = 1; j<= n; j++){
            if(b[j] <= i) cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<psum[b[1]]<<"\n";

    return 0;
}