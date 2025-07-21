#include <bits/stdc++.h> //peguei a ideia errada, continuar dps
#define ll long long
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

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
	
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    vector <P> pts;

    pts.emplace_back(0, 100000009);
    for(int i =1; i<=n; i++){
        int a; cin>>a;

        pts.emplace_back(i, a);
    }
    pts.emplace_back(n+1, -1);

    vector <P> hull = convexHull(pts);
    sort(all(hull));

    int k = 0;
    while(!(pts[k] == hull[1])){
        k++;
    }

    cout<<fixed<<setprecision(9);

    for(int i =1; i< sz(hull) - 1; i++){
        int cont = 0;
        double sum = 0;

        while(!(pts[k] == hull[i+1])){
            sum+= pts[k].y;
            k++;
            cont++;
            
        }
        sum/=(double)cont;

        for(int j = 0; j<cont; j++) cout<<sum<<"\n";
    }
    return 0;
}