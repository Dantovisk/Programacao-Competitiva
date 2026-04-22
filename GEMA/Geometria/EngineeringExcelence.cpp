#include<bits/stdc++.h>
using namespace std ; 

#define ff first 
#define ss second 
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long double ld;

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
	// angle to x-axis in interval [-pi, pi]
	ld angle() const { return atan2l(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(ld a) const {
		return P(x*cosl(a)-y*sinl(a),x*sinl(a)+y*cosl(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-05-05
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
If a unique intersection point of the lines going through s1,e1 and s2,e2 exists \{1, point\} is returned.
If no intersection point exists \{0, (0,0)\} is returned and if infinitely many exists \{-1, (0,0)\} is returned.
The wrong position will be returned if P is Point<ll> and the intersection point does not have integer coordinates.
Products of three coordinates are used in intermediate steps so watch out for overflow if using int or ll.
 * Usage:
 * 	auto res = lineInter(s1,e1,s2,e2);
 * 	if (res.first == 1)
 * 		cout << "intersection point at " << res.second << endl;
 * Status: stress-tested, and tested through half-plane tests
 */

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

const ld DINF = 1e18;
const ld pi = acosl(-1.0);
const ld eps = 1e-7;
const ld INF = 1e9;
#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

typedef Point<ld> pt; 
ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p).cross(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}


vector<Point<ld>> v;
int n; 

template<class P>
vector<P> circleLine(P c, ld r, P a, P b) {
    P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
	ld s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	P h = ab.unit() * sqrt(h2);
	return {p - h, p + h};
}

const ld tol = 1e-5;
ld testa(int i, pt inter){
    // Garante que ta indo para fora do polígono
    if (ccw(v[i-1], v[i+1], inter) && !col(v[i-1], v[i+1], inter)) return 0;

    // cout<<"teste: "<<i<<"\n";
    if((ccw(v[i-2], v[i-1], inter) or col(v[i-2], v[i-1], inter)) 
    and ((!ccw(v[i+2], v[i+1], inter)) or col(v[i+2], v[i+1], inter))){
        ld ds = (inter-v[i-1]).dist() + (inter-v[i+1]).dist();
        ld diff = ds - (v[i]-v[i-1]).dist() - (v[i]-v[i+1]).dist();

        //Angulos alheios ficaram menores que 90°
        if((v[i-2]-v[i-1]).dot(inter-v[i-1]) > tol) return 0;
        if((v[i+2]-v[i+1]).dot(inter-v[i+1]) > tol) return 0;

        //angulo resultante ficou menor que 90°
        if((v[i-1]-inter).dot(v[i+1]-inter) > tol) return 0;

        return diff;
    }
    // cout<<"moggou\n";
    return 0;
}

void solve(){
    cin>>n;

    rep(i, 0, n){
        int x, y;
        cin>>x>>y;

        v.emplace_back(x, y);
    }
    // if(n <= 4){
    //     cout<<"0\n";
    //     return;
    // }

    v.pb(v[0]);
    v.pb(v[1]);
    v.pb(v[2]);
    v.pb(v[3]);

	ld res = 0;

    for(int i = 2; i<= n+1; i++){        
        // cout<<"i = "<<i<<'\n';
        // CASO 1: triang isosceles no circulo de thales
        pt v1 = v[i+1] - v[i-1];
        v1 = v1.rotate(-pi/4.0L);
        v1 = v1 + v[i-1];
        
        pt v2 = v[i-1] - v[i+1];
        v2 = v2.rotate(pi/4.0L);
        v2 = v2 + v[i+1];
        
        auto [fl, inter] = lineInter(v[i-1], v1, v[i+1], v2);

        if(fl != 0){
            res = max(res, testa(i, inter));
        }

        
        //Caso 3: halfplane da esquerda intersecta com o circulo de mileto
        pt center = (v[i-1]+v[i+1])/2.0L;
        ld radius = ((v[i-1]-v[i+1]).dist()/2.0L);
        vector<pt> inters = circleLine(center, radius, v[i-2], v[i-1]);
        
        for(auto inter3: inters){
            res = max(res, testa(i, inter3));
            // cout<<"res = "<<res<<"\n";
        }
        
        v1 = v[i-2] - v[i-1];
        v1 = v1.rotate(-pi/2.0L);
        v1 = v1 + v[i-1];
        inters = circleLine(center, radius, v[i-1], v1);
        
        for(auto inter3: inters){
            res = max(res, testa(i, inter3));
            // cout<<"res = "<<res<<"\n";
        }
        
        //Caso 4: halfplane da esquerda intersecta com o circulo de mileto
        inters = circleLine(center, radius, v[i+2], v[i+1]);
        
        for(auto inter4:inters){    
            res = max(res, testa(i, inter4));
            // cout<<"res = "<<res<<"\n";
        }
        
        v2 = v[i+2] - v[i+1];
        v2 = v2.rotate(pi/2.0L);
        v2 = v2 + v[i+1];
        inters = circleLine(center, radius, v[i+1], v2);
        for(auto inter4:inters){    
            res = max(res, testa(i, inter4));
            // cout<<"res = "<<res<<"\n";
        }

        // Caso 2: Intersecção dos 2 halfplanes
        auto [fl2, inter2] = lineInter(v[i-2], v[i-1], v[i+1], v[i+2]);
        if(fl2 == 1){
            res = max(res, testa(i, inter2));
        }
        
        auto [fl3, inter3] = lineInter(v1, v[i-1], v[i+1], v2);
        if(fl3 == 1)
            res = max(res, testa(i, inter3));
        
    }

	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    int t  = 1 ; ;//cin >> t ; 

    while(t--) solve() ; 
}