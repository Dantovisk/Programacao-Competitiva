#include <bits/stdc++.h>//ideia incompletinha
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define pb push_back
typedef long long ll;
typedef pair<double, double> pii;
typedef vector<int> vi;
#define ff first
#define ss second

const int MAX = 2e5+69;
vector<pii> psum;

double cross(pii a, pii b){
    return abs(a.ff*b.ss - a.ss*b.ff)/2.0;
}

pii add(pii a, pii b){
    return {a.ff+b.ff, a.ss+b.ss};
}

pii esc(pii a, double b){
    return {a.ff*b, a.ss*b};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    vector<pii> pts;
    psum.push_back({0, 0});
    for(int i =0; i<n; i++){
        int a, b;
        cin>>a>>b;
        pts.push_back({a, b});
        psum.push_back(add(psum[i], {a, b}));
    }

    pts.push_back(pts[0]);
    pts.push_back(pts[1]);

    if(n==3) {
        cout<<"1.00000000\n";
        return 0;
    }

    double res = 0;

    //Area total do poligono
    double total = 0;

    for(int i =0; i<n-2; i++){
        auto [ax, ay] = pts[i+1];
        auto [bx, by] = pts[0];
        auto [cx, cy] = pts[i+2];

        pii v1 = {ax-bx, ay-by};
        pii v2 = {cx-bx, cy-by};

        total += cross(v1, v2);
    }

    for(int j = 1; j< n-1; j++){
        pii a = esc(pts[j], -j);
        a = add(a, psum[j]);

        pii b = esc(pts[j],-(n-j-1));
        b = add(b, add(psum[n], esc(psum[j+1], -1)));

        res+=cross(a, b);
    }
    res/=total;
    cout<<fixed<<setprecision(8);
    cout<<res<<"\n";

}


