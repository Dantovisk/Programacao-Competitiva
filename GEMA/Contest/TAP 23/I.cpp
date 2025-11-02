#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<double, int> pdi;

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

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

vector <pair<double, int>> adj[400'000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int C, Q, T;
    cin>>C>>Q>>T;

    vector<pair<P, double>> cir;
    vector<vector<P>> quad;
    vector<vector<P>> tri;

    rep(i, 0, C){
        int a, b, r;
        cin>>a>>b>>r;

        cir.push_back({P(a, b), r});
    }

    rep(i, 0, Q){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        P p1(x1, y1);
        P p2(x2, y2);

        P center = (p1 + p2) / 2.0;
        P v = p1 - center;

        P p3 = center + v.perp();
        P p4 = center - v.perp();

        quad.push_back({p1, p3, p2, p4});
    }

    rep(i, 0, T){
        int x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        tri.push_back({P(x1, y1), P(x2, y2), P(x3, y3)});
    }

    rep(i, 0, C){
        rep(j, i+1, C){
            auto[P1, r1] = cir[i];
            auto[P2, r2] = cir[j];
            double d = (P1-P2).dist() - r1 - r2;

            adj[i].push_back({d, j});
            adj[j].push_back({d, i});
        }
    }

    rep(i, 0, C){
        rep(j, 0, Q){
            auto[P1, r1] = cir[i];
            auto q = quad[j];

            double minn = 1e9+7;

            rep(k, 0, 4){
                minn = min(minn, segDist(q[k], q[(k+1)%4], P1));
            }

            double d = minn - r1;
            adj[i].push_back({d, j+C});
            adj[j+C].push_back({d, i});
        }

        rep(j, 0, T){
            auto[P1, r1] = cir[i];
            auto t = tri[j];

            double minn = 2e9+7;

            rep(k, 0, 3){
                minn = min(minn, segDist(t[k], t[(k+1)%3], P1));
            }

            double d = minn - r1;
            adj[i].push_back({d, j+C+Q});
            adj[j+C+Q].push_back({d, i});
        }
    }


    rep(i, 0, Q){
        rep(j, 0, T){
            auto q = quad[i];
            auto t = tri[j];

            double minn = 2e11+7;

            rep(k, 0, 4){
                auto P1 = q[k];
                rep(l, 0, 3){
                    minn = min(minn, segDist(t[l], t[(l+1)%3], P1));
                }
            }

            rep(k, 0, 3){
                auto P1 = t[k];
                rep(l, 0, 4){
                    minn = min(minn, segDist(q[l], q[(l+1)%4], P1));
                }
            }

            adj[i+C].push_back({minn, j+C+Q});
            adj[j+C+Q].push_back({minn, i+C});
        }
    }

    //dijkstra

    priority_queue <pdi, vector<pdi>, greater<pdi>> pq;
    vector<double> dist (C+Q+T+1, 2e9+7);

    rep(i, 0, Q){
        pq.push({0,i+C});
        dist[i+C] = 0;
    }

    while(!pq.empty()){
        auto [w1, u] = pq.top();
        pq.pop();

        if(w1 - dist[u] > 1e-9) continue;

        for(auto [w2, v] : adj[u]){
            if(dist[u] + w2 - dist[v] >= 1e-9 ) continue;
            dist[v] = dist[u] + w2;
            pq.push({dist[v], v});
        }
    }

    cout<<fixed<<setprecision(12);

    double minn = 1e12;
    rep(i, C+Q, C+Q+T){
        minn = min(dist[i], minn);
    }
    cout<<minn<<"\n";
}