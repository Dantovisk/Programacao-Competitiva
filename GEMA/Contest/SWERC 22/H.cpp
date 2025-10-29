#include <bits/stdc++.h>
using namespace std;

const float EPS = 1e-5;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
	T dist2() const { return x*x + y*y; }
	float dist() const { return sqrt((float)dist2()); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};


typedef Point<float> P;
P p1, p2, p3;

float funcao(P& pw){
    
}

float find_min2(float pivo, float eps=EPS) {
    float l = -1e4-7, r = 1e4+7;

    P ponto = P(pivo, 0);

	while (r - l > eps) {
		float m1 = l + (r - l) / 3;

		float m2 = r - (r - l) / 3;

        ponto.y = m1;
        float u = funcao(ponto);
        ponto.y = m2;
        float v = funcao(ponto);


		u>v ? l = m1 : r = m2;
	}
    ponto.y = l;
	return funcao(ponto);
}


float find_min(float eps=EPS) {
    float l = -1e4-7, r = 1e4+7;

	while (r - l > eps) {
		float m1 = l + (r - l) / 3;
		float m2 = r - (r - l) / 3;

		find_min2(m1) > find_min2(m2) ? l = m1 : r = m2;
	}

	return find_min2(l);
}



int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    float a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;

    p1=Point(a, b); p2=Point(c, d); p3=Point(e, f);

    cout<<fixed<<setprecision(9);
    cout<<find_min()<<"\n";
}