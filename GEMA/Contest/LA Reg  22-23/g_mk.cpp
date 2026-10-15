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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
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

typedef Point<ll> P;

//encontra a soma de minkowski dos poligonos a e b (devem ser CCW)
void reorder(vector<P> &p){
    int best = 0;
    rep(i, 1, sz(p))
        if(p[best].y > p[i].y or (p[best].y == p[i].y and p[best].x > p[i].x)){
            best = i;
    }
    rotate(p.begin(), p.begin() + best, p.end());
}
vector<P> minkowski(vector<P> a, vector<P> b){
    reorder(a); reorder(b);
    int na = sz(a), nb = sz(b);
    vector<P> res;

    a.push_back(a[0]); a.push_back(a[1]);
    b.push_back(b[0]); b.push_back(b[1]);

    int i = 0, j = 0;
    while(i < na or j < nb){
        res.push_back(a[i]+b[j]);
        ll k = (b[j+1]-b[j]).cross(a[i+1]-a[i]);
        if(k >= 0 and j < nb) j++;
        if(k <= 0 and i < na) i++;
    }
    return res;
}

template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

bool inHull(const vector<P>& l, P p, bool strict = false) {
	int a = 1, b = sz(l) - 1, r = !strict;
	if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
	if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
	if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p)<= -r)
		return false;
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(sideOf(l[0], l[c], p) > 0 ? b : a) = c;
	}
	return sgn(l[a].cross(l[b], p)) < r;
}

void solve(){
    int m1, m2, n; 
    vector<P> p1, p2, pts;
    
    cin>>m1;
    rep(i, 0, m1) {
        int x, y;
        cin>>x>>y;
        p1.emplace_back(x, y);
    }

    cin>>m2;
    rep(i, 0, m2) {
        int x, y;
        cin>>x>>y;
        p2.emplace_back(x, y);
    }

    vector<P> aux1 = p1;
    vector<P> aux2 = p2;
    vector<P> dob1 = p1;
    vector<P> dob2 = p2;
    vector<P> poly = minkowski(p1, p2);
    

    rep(i, 0, m1){
        aux1[i] = aux1[i]*(-1);
        dob1[i] = dob1[i] * 2;
    }

    rep(i, 0, m2){
        aux2[i] = aux2[i]*(-1);
        dob2[i] = dob2[i] * 2;
    }

    vector<P> poly2 = minkowski(dob1, aux2);
    vector<P> poly3 = minkowski(dob2, aux1);

    cin>>n;
    rep(i, 0, n) {
        int x, y;
        cin>>x>>y;
        pts.emplace_back(x, y);
    }

    for(auto p: pts){
        //ta na media, ou 
        if(inHull(poly, p*2) or inHull(poly3, p) 
        or inHull(poly2, p)) {
            cout<<"Y";
        }
        else cout<<"N";
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}