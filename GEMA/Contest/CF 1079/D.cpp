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
    int n; cin>>n;

    vi a(n);
    vector<vi> ocurr(n+1);

    rep(i, 0, n){
        cin>>a[i];
        if(a[i] > n) continue;
        ocurr[a[i]].push_back(i);
    }

    int res = 0;

    for(int i = 1; i<=n; i++){
        if(ocurr[i].size() == 0) continue;
        for(int j=1; j*i<=n; j++){
            if(ocurr[j].size() == 0) continue;

            auto pk = ocurr[i].begin();
            auto ptr = ocurr[j].begin();

            while(pk != ocurr[i].end()){
                int k = *pk;
                if(k + i*j > n) break;
                ptr = lower_bound(ptr, ocurr[j].end(), k + i*j);
                if(ptr == ocurr[j].end()) break;

                if((*ptr) == k + i*j) {
                    res++;
                    pk++;
                }
                else{
                    pk = lower_bound(pk, ocurr[i].end(), *ptr - i*j);
                }
            }
        }
    }

    cout<<res<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}