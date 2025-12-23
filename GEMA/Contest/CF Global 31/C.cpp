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
    int n, k;
    cin>>n>>k;

    if(k%2){
        rep(i, 0, k) cout<<n<<" ";
        cout<<"\n";
        return;
    }

    vector<vi> ind(k, vi(30, 0));
    int loose = -1;
    for(int i = 29; i>= 0; i--){
        if((1<<i) & n){
            //bit atual é 1

            bool mogga = false;
            int cont = ((k+1)%2);
            if(cont) {
                if(loose < k-1)loose++;
                mogga = true;
            }

            rep(j, 0, k){
                if(mogga == true && j == loose) continue;
                ind[j][i] = 1; 
            }
        }
        else{
            rep(j, 0, loose + 1 - ((loose+1) % 2)){
                ind[j][i] = 1;
            }
        }
    }

    for(auto &v: ind){
        int curr = 0;
        for(int i = 29; i>= 0; i--) curr += (v[i]<<i);
        cout<<curr<<" ";
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}