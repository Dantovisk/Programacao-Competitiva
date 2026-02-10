#include <bits/stdc++.h>
using namespace std;

#define int long long

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
    int t; cin>>t;

    set<int> res;
    for(int i = 2; i*i <= t; i++){
        vector<int> lista;
        int temp = t;
        while(temp != 0){
            lista.push_back(temp % i);
            temp /= i;
        }
        bool ruim = false;
        for(int j = 0; j < lista.size() - j - 1; j++){
            if(lista[j] != lista[lista.size() - j - 1]){
                ruim = true; break;
            }
        }
        if(!ruim) res.insert(i);
    }

    for(int k = 1; k *k <= t; k++){
        //procurando os palindromos no formato (kk) na base x;
        int l = k+1, r = t;
        while(l < r){
            int mid = (l+r)/2LL;
            
            int cur = mid*k + k;

            if(cur == t){
                res.insert(mid);
                break;
            }
            else if(cur < t){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
    }
        
    if(res.size() == 0){
        cout<<"*\n";
        return;
    }
    for(auto x: res) cout<<x<<" ";
    cout<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}