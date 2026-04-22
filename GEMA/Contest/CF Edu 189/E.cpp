#include <bits/stdc++.h>
#include <cstdint>
#include <cassert>
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

const int MAX = 1e5+7;
const int inf = 1e9+7;

template<class T>
void shuffle_vec(T& vec) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (vec.begin(), vec.end(), default_random_engine(seed));
}
// returns random int in [0, hi), like Python's random.randrange
int randRange(int hi) {
	return rand() % hi;
}

bool randBool() {
	return !!(rand() & 128);
}

// returns random int in [lo, hi), like Python's random.randrange
int randRange(int lo, int hi) {
	return lo + randRange(hi - lo);
}

ll dist(pii a, pii b){
    return (ll)(a.ff - b.ff)*(ll)(a.ff - b.ff) + (ll)(a.ss- b.ss)*(ll)(a.ss - b.ss);
}
const double eps = 1e-7;

void solve(){
    int n, r; 
    cin>>n>>r;

    vector<pii> v;
    rep(i,0, n){
        int a, b;
        cin>>a>>b;
        v.pb({a, b});
    }

    vi ind(n);
    rep(i, 0, n) ind[i] = i;

    rep(sla, 0, 2000){
        shuffle_vec(ind);

        vector<pii> circ;

        for(auto id: ind){
            auto c1 = v[id];
            
            rep(j, 0, 10){
                int dx = randRange(-r/2, r/2);
                int dy = randRange(-r/2, r/2);
                int da = 1;

                pii nc1 = {c1.ff + dx, c1.ss +dy};

                for(auto c2: circ){
                    if(dist(nc1, c2) < 4LL * (ll)r * r ){
                        da = 0;
                        break;
                    }
                }

                if(da) {
                    circ.push_back({nc1});
                    break;
                }
            }
        }

        int cont = 0;

        rep(i, 0, n){
            for(auto c: circ){
                if(dist(v[i], c) <= (ll)r*r){
                    // cout<<i<<" foi com "<<c.ff<<", "<<c.ss<<" =  "<<dist(v[i], c)<<"\n";
                    cont++;
                    break;
                }
            }
        }

        // cout<<"tentativa "<<sla<<": "<<cont<<"\n";

        if(cont * 100 >= 89*n){
            cout<<circ.size()<<"\n";
            for(auto [x, y] : circ){
                cout<<x<<" "<<y<<"\n";
            }
            return;
        }
    }

    exit(1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}