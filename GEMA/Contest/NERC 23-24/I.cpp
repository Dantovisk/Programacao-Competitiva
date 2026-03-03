#include <bits/stdc++.h>
using namespace std;

#include <cstdint>
#include <cassert>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

int gray(int a){
    return (a^(a>>1));
}

int n;
bool ligado(int i, int &k){
    int res;
    cout<<i<<" "<<i<<endl;
    cin>>res;

    if(res == n) return true;

    if(res == k){
        cout<<i<<" "<<i<<endl;
        cin>>res;
        return false;
    } 
    if(res > k){
        k = res;
        return true;
    }

    cout<<i<<" "<<i<<endl;
    cin>>res;
    k = res;
    return true;
}

void solve(){
    int k;
    cin>>n>>k;

    // vector<int> act;
    // rep(i, 1, n+1) act.insert(i);

    for(int i = 1; i<= n; i++){
        if(ligado(i, k)) {
            continue;
        }
        // cout<<"To no "<<i<<endl;
        if(k == n) {
            // cout<<"mog\n";
            return;
        }
        bool deu = false;

        rep(j, 0, (1<<(n-i+1))){
            int falta = (gray(j) ^ gray((j > 0? j-1 : (1<<(n-i+1))-1)));

            rep(id, 0, (n-i+1)){
                if(!((1<<id) & falta)) continue;

                cout<<i<<" "<<id+i<<endl;
                int res; cin>>res;
                if(res == n) return;

                else if(res > k){
                    k = res;
                    if(ligado(i, k)) {
                        deu = true;
                        break;
                    }
    
                }
            }
            if(deu) break;
        }
    }

}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;
    while(t--){
        solve();

    }
}