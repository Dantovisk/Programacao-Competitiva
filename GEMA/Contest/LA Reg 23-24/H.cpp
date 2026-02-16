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

#define vp vector<point>
#define ld double
const ld EPS = 1e-8;
const ld PI = acos(-1);

typedef ld T;
bool eq(T a, T b){ return abs(a - b) <= EPS; }

struct point{
    T x, y;
    int id;
    point(T x=0, T y=0): x(x), y(y){}

    point operator+(const point &o) const{ return {x + o.x, y + o.y}; }
    point operator-(const point &o) const{ return {x - o.x, y - o.y}; }
    point operator*(T t) const{ return {x * t, y * t}; }
    point operator/(T t) const{ return {x / t, y / t}; }
    T operator*(const point &o) const{ return x * o.x + y * o.y; }
    T operator^(const point &o) const{ return x * o.y - y * o.x; }
    bool operator<(const point &o) const{
        return (eq(x, o.x) ? y < o.y : x < o.x);
    }
    bool operator==(const point &o) const{
        return eq(x, o.x) and eq(y, o.y);
    }
	friend ostream& operator<<(ostream& os, point p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

int ccw(point a, point b, point e){ // -1=dir; 0=collinear; 1=esq;
    T tmp = (b-a) ^ (e-a); // vector from a to b
    return (tmp > EPS) - (tmp < -EPS);
}
ld norm(point a){ // Modulo
    return sqrt(a * a);
}

const ld LLINF = 1e12;

struct Halfplane {
    point p, pq;
    ld angle;
    Halfplane() {}
    Halfplane(const point &a, const point &b) : p(a), pq(b - a) {
        angle = atan2l(pq.y, pq.x);
    }

    bool out(const point &r) { return (pq ^ (r - p)) < -EPS; }
    bool operator<(const Halfplane &e) const { return angle < e.angle; }

    friend point inter(const Halfplane &s, const Halfplane &t) {
        ld alpha = ((t.p - s.p) ^ t.pq) / (s.pq ^ t.pq);
        return s.p + (s.pq * alpha);
    }
};

vp hp_intersect(vector<Halfplane> &H) {

    point box[4] = {
        point(LLINF, LLINF),
        point(-LLINF, LLINF),
        point(-LLINF, -LLINF),
        point(LLINF, -LLINF)
    };

    for(int i = 0; i < 4; i++) {
        Halfplane aux(box[i], box[(i+1) % 4]);
        H.push_back(aux);
    }

    sort(H.begin(), H.end());
    deque<Halfplane> dq;
    int len = 0;
    for(int i = 0; i < (int)H.size(); i++) {

        while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))) {
            dq.pop_back();
            --len;
        }

        while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }

        if (len > 0 && fabsl((H[i].pq ^ dq[len-1].pq)) < EPS) {
            if ((H[i].pq * dq[len-1].pq) < 0.0)
                return vp();

            if (H[i].out(dq[len-1].p)) {
                dq.pop_back();
                --len;
            }
            else continue;
        }

        dq.push_back(H[i]);
        ++len;
    }

    while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len-1].out(inter(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    if (len < 3) return vp();

    vp ret(len);
    for(int i = 0; i+1 < len; i++) {
        ret[i] = inter(dq[i], dq[i+1]);
    }
    ret.back() = inter(dq[len-1], dq[0]);
    return ret;
}

const int inf = 67676767;


void solve(){
    int n; double rad;
    cin>>n>>rad;

    point den;
    den.x = 0;
    den.y = 0;

    vector<Halfplane> lines;

    rep(i, 0, n){
        point p1, p2;
        cin>>p1.x>>p1.y;
        cin>>p2.x>>p2.y;

        
        if(ccw(p1, p2, den) == -1) swap(p1, p2);
        Halfplane xd(p1, p2);

        lines.push_back(xd);
    }

    int best = inf;
    int l = 1, r = n+1;

    set <pair<Halfplane, int>> st;

    while(l < r){
        int mid = (l+r)/2;

        while(sz(st) > mid){
            int i = sz(st) - 1;
            st.erase({lines[i], i});
        }

        while(sz(st) < mid){
            int i = sz(st);
            st.insert({lines[i], i});
        }

        vector<Halfplane> curr;
        for(auto [lin, id]: st){
            curr.push_back(lin);
        }

        vector <point> poly = hp_intersect(curr);

        bool deu = false;

        for(auto p: poly){
            if(norm(den - p) - rad > EPS){
                deu = true;
                break;
            }
        }

        if(deu){
            l = mid+1;
        } else{
            best = min(best, mid);
            r = mid;
        }
    }

    if(best == inf){
        cout<<"*\n";
    }else{
        cout<<best<<"\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}