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

/**
 * Author: Ulf Lundstrom with inspiration from tinyKACTL
 * Date: 2009-04-14
 * License: CC0
 * Source:
 * Description: Class to handle points in 3D space.
 * 	T can be e.g. double or long long.
 * Usage:
 * Status: tested, except for phi and theta
 */

template<class T> struct Point3D {
	typedef Point3D P;
	typedef const P& R;
	T x, y, z;
	explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(R p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z); }
	bool operator==(R p) const {
		return tie(x, y, z) == tie(p.x, p.y, p.z); }
	P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(R p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; }
};

struct sla{
    int a, b, c;
    sla(int a, int b, int c) : a(a), b(b), c(c) {}
};

template<class V, class L>
ll signedPolyVolume(const V& p, const L& trilist) {
	ll v = 0;
	for (auto i : trilist) v += p[i.a].cross(p[i.b]).dot(p[i.c]);
	return v;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin>>n;

    vector<pii> v;

    rep(i, 0, n){
        int a, b;
        cin>>a>>b;
        v.pb({a, b});
    }
    v.pb(v[0]);

    vector<Point3D<ll>> pts;
    vector<sla> s;
    rep(i, 0, n){
        auto [x1, y1] = v[i];
        auto [x2, y2] = v[i+1];

        Point3D<ll> p1(x1, y1, y1), p2(x2, y2, y2);
        Point3D<ll> p3(x2, y2, 0), p4(x1, y1, 0);

        Point3D<ll> v1 = p3-p1, v2 = p2-p1, v3 = Point3D<ll>(0,0,0)-p1;
        Point3D<ll> v4 = p1-p3, v5 = p4-p3, v6 = Point3D<ll>(0,0,0)-p3;

        pts.pb(v1);
        pts.pb(v2);
        pts.pb(v3);
        pts.pb(v4);
        pts.pb(v5);
        pts.pb(v6);

        s.emplace_back(i*6, i*6 + 1, i*6 + 2);
        s.emplace_back(i*6 + 3, i*6 + 4, i*6 + 5);
    }

    ll res = signedPolyVolume(pts, s);
    cout<<-res<<"\n";
}