#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define ff first
#define ss second

const int inf = 1e9+7;
const double eps = 1e-7;

typedef vector<double> vd;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin>>n>>m;

    vl v(n+1);

    rep(i, 0, n+1){
        cin>>v[i];
    }

    rep(xd, 0, m){
        // cout<<"TESTE "<<xd<<"\n";
        double k; cin>>k;

        vl a = v;

        rep(i, 0, n+1){
            a[i] = v[i] - (ll)round(k * 10) * i;
            // cout<<a[i]<<" ";
        }
        // cout<<"\n";

        vector <pair<ll, int>> mq;

        mq.push_back({-a[0], 0});

        double res = 0;

        rep(i, 1, n+1){
            auto ptr = lower_bound(all(mq), make_pair(-a[i], 0));

            if(ptr == mq.end()) {
                if(mq.back().ff < -a[i]){
                    mq.push_back({-a[i], i});
                }
                continue;
            }
            
            int id = (*ptr).ss;
            double cr = i - id;
            res = max(res, cr);
            double cl = cr;
            // cout<<cr<<" "<<id<<"\n";
            if(id){
                double aux = -(a[id] - a[id-1]);
                if (abs(aux) > 1e-9){
                    // cout<<"aux = "<<aux<<"\n";
                    cr += min((a[i] - a[id]) / aux, 1.0);
                }
            }

            res = max(res, cr);

            if(i < n ){
                double aux = -(a[i+1] - a[i]);
                if (abs(aux) > 1e-9){
                    // cout<<"aux = "<<aux<<"\n";
                    cl += min((a[i] - a[id]) / aux, 1.0);
                }
            }

            res = max(res, cl);

            if(mq.back().ff < -a[i]){
                mq.push_back({-a[i], i});
            }
        }

        cout<<fixed<<setprecision(9);
        if(res < eps) cout<<"-1\n";
        else cout<<res<<"\n";
    }
}