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
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
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
		return os << "(" << p.x << "," << p.y << ")"; }
};
typedef Point<int> P;

bool onSegment(P s, P e, P p) {
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

typedef vector<P> seg;


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;
    set<seg> act;

    rep(i, 0, n){
        int x, y, r;
        cin>>x>>y>>r;

        P p1 (x+r, y), p2(x, y-r), p3 (x-r, y), p4(x, y+r);
        vector<seg> curr = {{p1, p2}, {p2, p3}, {p3, p4}, {p4, p1}};

        // rep(i, 0, 4){
        //     cout<<"curr "<<i<<": ";
        //     for(auto p: curr[i]) cout<<p<<" -> ";
        //     cout<<"\n";
        // }

        if(i == 0){
            for(auto k: curr) act.insert(k);

        //     int ctt = 0;
        //     for(auto k: act){
        //         cout<<"seg "<<ctt++<<": ";
        //         for(auto p: k) cout<<p<<" -> ";
        //         cout<<"\n";
        //     }
        //     continue;
        }

        set<seg> newact;
        //lados do cur
        rep(i, 0, 4){
            for(auto k: act){
                if(sz(k) == 0) continue;
                if(sz(k) == 1){
                    if(onSegment(curr[i][0], curr[i][1], k[0])) newact.insert(k);
                } 
                else{
                    seg aux = segInter(curr[i][0], curr[i][1], k[0], k[1]); 
                    if(sz(aux) == 1){
                        if(!onSegment(curr[i][0], curr[i][1], aux[0])) continue;
                        if(!onSegment(k[0], k[1], aux[0])) continue;
                    }

                    newact.insert(aux);
                    
                }
            }
        }

        act = newact;

        // int ctt = 0;
        // for(auto k: act){
        //     cout<<"seg "<<ctt++<<": ";
        //     for(auto p: k) cout<<p<<" -> ";
        //     cout<<"\n";
        // }
        
    }

    set<pii> pts;
    int dir [4][2] = {{-1,-1}, {-1, 1}, {1, 1}, {1, -1}};
    
    for(auto k: act){
        if(k.size() == 0) continue;
        if(k.size() == 1){
            pts.insert({k[0].x, k[0].y});
            continue;
        }

        for(auto d: dir){
            int xx = k[0].x;
            int yy = k[0].y;

            int fx = k[1].x;
            int fy = k[1].y;
            
            int dx = fx-xx;
            int dy = fy-yy;

            if(d[0]*dx < 0) continue;
            if(d[1]*dy < 0) continue;

            while(xx != fx){

                pts.insert({xx, yy});

                xx+= d[0];
                yy+= d[1];
            }
        }
 
    }
    for(auto [x, y]: pts){
        cout<<x<<" "<<y<<"\n";
    }
}