#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

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
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	ld dist() const { return sqrtl((ld)dist2()); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<ld> P;
vector<P> poly, B, A;
const ld eps =  1e-8;
int n, m;

int extreme(const function<bool(P, P)> &cmp) {
    auto isExtreme = [&](int i, bool& curDir) -> bool {
        curDir = cmp(poly[(i + 1) % n], poly[i]);
        return !cmp(poly[(i + n - 1) % n], poly[i]) && !curDir;
    };
    bool lastDir, curDir;
    if(isExtreme(0, lastDir)) return 0;
    int lo = 0, hi = n; 
    while(lo + 1 < hi) {
        int m = (lo + hi) >> 1;
        if(isExtreme(m, curDir)) return m;
        bool relDir = cmp(poly[m], poly[lo]);
        if((!lastDir && curDir) || (lastDir == curDir && relDir == curDir)) {
            lo = m;
            lastDir = curDir;
        } else hi = m;
    }
    return lo;
}
ld area2(P a, P b, P c) { // two times signed area of triangle abc
	return ((b - a).unit()).cross((c - a).unit());
}
bool left(P a, P b, P c) {
	return area2(a, b, c) > eps; // counterclockwise
}
bool right(P a, P b, P c) {
	return area2(a, b, c) < -eps; // clockwise
}
pair<int, int> tangent(P q) { // O(log n) for convex polygon in ccw orientation
    // Finds the indices of the two tangents to an external point q
    auto leftTangent = [&](P r, P s) -> bool {
        return right(q, r, s);
    };
    auto rightTangent = [&](P r, P s) -> bool {
        return left(q, r, s);
    };
    int l = extreme(leftTangent);
    if(!left(poly[l], poly[(l+1)%n], q) and !right(poly[l], poly[(l+1)%n], q)){
        l = (l+1) % n;
    }

    int r = extreme(rightTangent);
    int r2 = (r-1+n)%n;
    if(!left(poly[r], poly[r2], q) and !right(poly[r], poly[r2], q)){
        r = r2;
    }
    return {l, r};
}

//1 -> left, 0 coliner, -1: right
template<class P>
int sideOf(P s, P e, P p) {
	auto a = (e-s).cross(p-s);
	ld l = (e-s).dist()*eps;
	return (a > l) - (a < -l);
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto v = e1 - s1;
    auto w = e2 - s2;
    auto d = v.cross(w);
    if (abs(d) < eps) // if parallel
        return {-(abs(v.cross(s2 - s1)) < eps), P(0, 0)};
    // to reduce imprecision
    ld t = (s2 - s1).cross(w) / d;
    return {1, s1 + v * t};
}

ld segDist(P s, P e, P p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0L,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> bool onSegment(P s, P e, P p) {
	return segDist(s,e,p)<=eps;
}

vector<pii> interv;
vector<pii> interv2;

void calc(int i, int r, ll tipo = 1){
    int da = 1;
    while(da){
        auto [x, isect] = lineInter(B[i], B[i+1], A[r], A[r+1]);
        if(x == 1){
            if(onSegment(B[i], B[i+1], isect)){
                if(tipo * (A[r] - A[r+1]).dot(isect - A[r+1]) < 0){
                    return;
                }
                auto [l2, r2] = tangent(isect);
                if(l2 < r2) {
                    l2+= n;
                }
                // cout<<"intermediario "<<isect<<": ["<<r2<<", "<<l2<<"]\n";
                if(r2+1 <= l2-1){
                    interv.emplace_back(r2+1, l2 - 1);
                }

                r++;
            }
            else{
                da = 0;
            }
        }else da = 0;
    }
}

const int MAX = 1676767;
int podes[MAX];

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build2(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build2(2*p, l, m), build2(2*p+1, m+1, r));
	}
	void build(int n2, int *v2) {
        n = n2;
        v = v2;
        if(n == 0) return;
		build2();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

void solve(){
    cin>>n>>m;
    interv.clear();
    interv2.clear();
    poly.clear();
    A.clear();
    B.clear();

    rep(i, 0, n){
        int x, y;
        cin>>x>>y;
        poly.emplace_back(x, y);
    }

    rep(j, 0, 3)
        rep(i, 0, n) 
            A.push_back(poly[i]);

    rep(i, 0, m){
        int x, y;
        cin>>x>>y;
        B.emplace_back(x, y);
    }
    B.push_back(B[0]);
    // rep(i, 0, m){
    //     B.push_back(B[i]);
    // }

    auto pr = tangent(P(0, 0));

    // cout<<pr.first<<" "<<pr.second<<"\n";

    rep(i, 0, m){
        auto [l, r] = tangent(B[i]);

        if(l < r) {
            l+= n;
        }
        // cout<<"ponto "<<B[i]<<": ["<<r<<", "<<l<<"]\n";
        if(r+1 <= l-1){
            interv.emplace_back(r+1, l - 1);
        }
        // cout<<"R: \n";
        calc(i, r, 1);
        // cout<<"L: \n";
        calc(i, l, -1);
    }

    
    for(auto x: interv){
        interv2.emplace_back(x.second, x.first);
    }
    
    //interv  [l, r]
    sort(all(interv));
    // for(auto [x, y] : interv){
    //     cout<<"x,y : ["<<x<<", "<<y<<"]\n";
    // }
    //interv2 [r, l]
    sort(all(interv2));

    rep(i ,0, sz(interv)){
        auto [x, y] = interv[i];
        podes[i] = y-x+1;
    }
    seg::build(interv.size(), podes);
    vi ress;

    rep(i, 0, n){
        ress.push_back(seg::query(0, interv.size()-1));

        int k; cin>>k;
        k--;
        //primeiro indice tal que o fim >= k
        int l = distance(interv2.begin(), lower_bound(all(interv2), make_pair(k, 0)));
        //primeiro indice tal que o inicio > k
        int r = distance(interv.begin(), lower_bound(all(interv), make_pair(k+1, 0)));
        if(l < r){
            seg::update(l, r-1, -1);
        }

        k += n;
        l = distance(interv2.begin(), lower_bound(all(interv2), make_pair(k, 0)));
        r = distance(interv.begin(), lower_bound(all(interv), make_pair(k+1, 0)));
        if(l < r){
            seg::update(l, r-1, -1);
        }
    }
    for(auto x: ress) cout<<x<<" ";
    cout<<'\n';
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