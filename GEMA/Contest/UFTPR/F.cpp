#include <bits/stdc++.h>
#define pd Point<double>

#define all(x) x.begin(), x.end()

using namespace std;

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

double adj[52][52];
vector<int> super;
pd comp[55];

int cor[52];

#define pdd pair<double, double>
priority_queue <pdd, vector<pdd>, greater<pdd>> pq;

int32_t main(){
    int n, m;
    cin>>n>>m;
    
    memset(adj, -1, sizeof(adj));
    
    for(int i =0; i<n; i++){
        double a, b;
        cin>>a>>b;
        comp[i] = Point(a, b);
    }

    pair<pd, pd> wall[55];

    for(int i =0; i<m; i++){
        double a, b, c, d;
        cin>>a>>b>>c>>d;
        wall[i] = {Point(a, b), Point(c,d)};
    }
    int s; cin>>s;
    for(int i =0; i<s; i++){
        int a; cin>>a;
        super.push_back(a);
    }

    //Criando as arestas do grafo
    for(int i =0; i<n; i++){
        for(int j =i+1; j<n; j++){
            //verificando se o par de vertices nao é cruzado por uma parede
            bool naoCruza = true;
            for(int k =0; k<m; k++){
                vector<pd> inter = segInter(comp[i], comp[j], wall[i].first, wall[i].second);
                if(inter.size() == 1){
                    naoCruza = false;
                    break;
                }
            }

            if(naoCruza){
                double dis = (comp[i] - comp[j]).dist();

                adj[i][j] = dis;
                adj[j][i] = dis;
            }
        }
    }
    cout<<fixed<<setprecision(2);

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }


    cor[super[0]] = 1;

    for(int i = 2; i<=s; i++){
        
    }
    
}