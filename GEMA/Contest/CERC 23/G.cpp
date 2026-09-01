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
#define double long double

const int maxn = 2e5+4;
const int inf = 1e9+3;
const double eps = 1e-9;
const double pi = acosl(-1);

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
	double dist() const { return sqrtl((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2l(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
vector<P> circleLine(P c, double r, P a, P b) {
	P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
	double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	P h = ab.unit() * sqrt(h2);
	return {p - h, p + h};
}

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= eps;
}

Point<double> a, b, c;
double xa, ya, xb, yb, xc, yc, r;

double f(double ang){
    Point<double> sla = (b-c).rotate(ang);

    sla = sla.unit();
    sla = sla * r;

    sla = sla + c;

    // cout<<"To em "<<sla<<"\n";
    // cout<<(sla-c).dist()<<"\n";

    double res = (sla - b).dist() +(sla - a).dist();

    return res;
}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the min of f(x) in [l, r]
}

void solve(){
    cin>>xa>>ya>>xb>>yb>>xc>>yc>>r;

    cout<<fixed<<setprecision(15);

    a = Point<double>(xa, ya);
    b = Point<double>(xb, yb);
    c = Point<double>(xc, yc);

    if((a-c).dist() - r < eps or (b-c).dist() - r < eps){
        cout<< (a-b).dist()<<"\n";
        return;
    }

    
    double angCB = (b-c).angle();
    double angCA = (a-c).angle();
    if(angCA < angCB) {
        swap(angCA, angCB);
        swap(a, b);
    }
    // ------------------------


    // Point<double> sla = (b-c).rotate((angCA-angCB)/2.0);

    // sla = sla.unit();
    // sla = sla * r;

    // sla = sla + c;

    // // cout<<"To em "<<sla<<"\n";
    // // cout<<(sla-c).dist()<<"\n";

    // double res = (sla - b).dist() +(sla - a).dist();

    // ----------------------------
    double res = ternary_search(0, angCA-angCB);

    if(angCB < 0){
        angCB += 2.0l*pi;
    
        swap(angCA, angCB);
        swap(a, b);

        res = min(ternary_search(0, angCA-angCB), res);
    }
    


    vector<Point<double>> v = circleLine(c, r, a, b);

    for(auto pt : v){
        if(onSegment(a, b, pt)) res = min(res, (a-b).dist());
    }

    cout<<res<<'\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}