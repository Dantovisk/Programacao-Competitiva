#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
using Point = pair<double,double>;
typedef vector<int> vi;

const double EPS = 1e-8;


Point add(Point a, Point b){ return {a.ff+b.ff, a.ss+b.ss};}
Point sub(Point a, Point b){ return {a.ff-b.ff, a.ss-b.ss};}
double esc(Point a, Point b){
    return a.ff*b.ff + a.ss*b.ss;
}

double cross(Point v1, Point v2){
    return v1.ff*v2.ss-v1.ss*v2.ff;;
}

double cross2(Point& pivo, Point& v1, Point& v2){
    return cross(sub(v1, pivo), sub(v2, pivo));
}

double norm(Point a){
    return sqrt(esc(a, a));
}

double dist(Point a, Point b){
    return norm(sub(a, b));
}

vector <int> grahamScan(vector<Point>& pts){
    //encontra o indice do pivo
    int ind = int(min_element(pts.begin(), pts.end()) - pts.begin());
    vi cand, hull{ind};

    //adiciona os pontos que nao sao o pivo e ordena
    for(int i =0; i<pts.size(); i++){
        if(i != ind) cand.push_back(i);
    }
    // ordena pelo ângulo (menor primeiro), desempata pela distância (menor primeiro)
    sort(cand.begin(), cand.end(), [&](int a, int b){
        Point v1 = sub(pts[a],pts[ind]), v2 = sub(pts[b], pts[ind]);
        double orient = cross(v1, v2);

        return (fabs(orient) > EPS ? (orient > 0) : (norm(v1) < norm(v2)));
    });

    for(auto c: cand){
        while(hull.size() > 1 && cross2(pts[hull[hull.size() - 2]], pts[hull.back()], pts[c]) < -EPS){
            hull.pop_back();
        }
        hull.push_back(c);
    }

    return hull;
}

void solve(int caso){
    int n; cin>>n;
    vector<Point> pts;
    for(int i =0; i<n; i++){
        double a, b;
        cin>>a>>b;
        pts.push_back({a, b});
    }
    vector<int> res = grahamScan(pts);

    cout<<"Caso "<<caso<<":\n";
    cout<<"Tamanho do colar: "<<res.size()<<"\n";
    cout<<"Pedras ancestrais: ";

    cout<<fixed<<setprecision(4);

    for(int i =0; i<res.size(); i++){
        auto[a, b] = pts[res[i]];
        cout<<"("<<a<<","<<b<<")";
        if(i < res.size()-1)cout<<",";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    for(int i =1; i<= t; i++){
        solve(i);
        cout<<"\n";
    }

    return 0;
}