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

const int maxn = 2e5+4;
const int inf = 1e9+3;

void solve(){
    int n, k; 
    cin>>n>>k;

    string a; cin>>a;

    int l = 1, r = n;
    int best = 1;
    while(l < r){
        int m = (l + r)/2;

        // cout<<"m = "<<m<<"\n";

        int dist = m+1;
        int cost = 0;
        rep(i, 0, n){
            if(a[i] == '#'){
                if(dist >= m){
                    //pego suave
                    dist = 0;
                }
                else{
                    //tive q apagar
                    cost++;
                }
            }
            dist++;
        }

        if(cost <= k){
            best = m;
            l = m+1;
            // cout<<"deu !\n";
        }
        else{
            r = m;
            // cout<<"nao deu :c\n";
        }

    }

    cout<<best<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}