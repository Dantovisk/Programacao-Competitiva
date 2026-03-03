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

const ll inf = 2e9+5;
const ll mx = 1e9;

/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 * 	T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P((__int128)x*(__int128)d, (__int128)y*(__int128)d); }
	P operator/(T d) const { return P((__int128)x/(__int128)d, (__int128)y/(__int128)d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << (ll)p.x << "," << (ll)p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

typedef Point<__int128> pl;
// typedef Point<ll> pl;

ll dir[4][2] = {{inf, 0}, {0, inf}, {inf, inf}, {-inf, inf}};
ll dir2[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};

void arruma(pl &p, int id){
	if(p.x > mx){
		ll dif = p.x-mx;
		p.y -= dif * (dir2[id][0] * dir2[id][1]);
		p.x = mx;
	}

	if(p.x < -mx){
		ll dif = (-mx) - p.x;
		p.y += dif * (dir2[id][0] * dir2[id][1]);
		p.x = -mx;
	}

	if(p.y > mx){
		ll dif = p.y-mx;
		p.x -= dif * (dir2[id][0] * dir2[id][1]);
		p.y = mx;
	}
	if(p.y < -mx){
		ll dif = (-mx) - p.y;
		p.x += dif * (dir2[id][0] * dir2[id][1]);
		p.y = -mx;
	}
}

void solve(){
    int n; cin>>n;
    vector<pair<pl, pl>> act;

    rep(i, 0, n){
        ll x, y;
		cin>>x>>y;
        
        vector<pair<pl, pl>> curr;
        pl pt(x, y);

		int sla = 0;
        for(auto d: dir){
			// se pa q da pra tirar aq o tle
            pl p1(x+d[0], y+d[1]), p2(x-d[0], y-d[1]);
			arruma(p1, sla);
			arruma(p2, sla);
            curr.pb({p1, p2});
			sla++;
        }

        if(i == 0){
			for(auto xd: curr) act.pb(xd);
            continue;
        }

        vector<pair<pl, pl>> newact;
		// cout<<"to no "<<i<<"\n";
        for(auto &[st, ed] : act){
			bool paia = false;
			if(st.x != ed.x && st.y != ed.y) paia = true;

			int ctt = 0;

            if(onSegment(st, ed, pt)){
                newact.push_back({st, ed});
                continue;
            }

            for(auto &[st2, ed2] : curr){
                vector<pl> inter{};

                if(st == ed){
                    if(onSegment(st2, ed2, st)) {
                        newact.push_back({st, st});
                        break;
                    }
                }
                

                inter = segInter(st, ed, st2, ed2);
                
				
                if(sz(inter) == 2){
					newact.push_back({inter[0], inter[1]});
                }
				else if(sz(inter) == 1){
					if(ctt >= 2 && paia){
						if(((st.x + st.y)%2LL + 2LL)%2LL != ((st2.x + st2.y + 2LL)%2LL + 2LL)%2LL){
							ctt++;
							continue;
						}
					}
					newact.push_back({inter[0], inter[0]});
				}

				ctt++;
            }
        }
		act = newact;

        sort(all(act)); 
        auto last = unique(all(act)); 
        act.erase(last, act.end()); 
    }
	if(sz(act)){
		cout<<"YES\n";
		auto [p1, p2] = *act.begin();
		cout<<(ll)p1.x<<" "<<(ll)p1.y<<"\n";
	}else{
		cout<<"NO\n";
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;
    while(t--){
        solve();

    }
}