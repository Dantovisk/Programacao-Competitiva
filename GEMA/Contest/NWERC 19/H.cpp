#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9+7;
const double eps = 1e-7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin>>n>>m;

    vi v(n+1);

    rep(i, 0, n+1){
        cin>>v[i];
    }

    rep(xd, 0, m){
        double k; cin>>k;

        double best = -1;
        int l = 0, r = n;

        while(r<l){
            //tamanho da janela
            int mid = (l+r)/2;

            int mn = inf;

            rep(i, 0, n-mid+1){
                mn = min(mn, v[i]);
                
                int mx = v[i+mid+1];

                double res = mx- mn;
                res /= 1.0 + mid;
                res /= 10.0;

                cout<<"mid = "<<mid<<", res = "<<res<<"\n";

                if(res - k > -eps){
                    best = mid;
                    break;
                }
            }

            if(best == mid){
                l = mid+1;
            }else{
                r = mid;
            }
        }

        cout<<best + (best == -1? 0 : 1)<<"\n";
    }
}