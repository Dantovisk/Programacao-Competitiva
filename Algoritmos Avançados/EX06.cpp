#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
using Point = pair<double,double>;
typedef vector<int> vi;

const double EPS = 1e-9;


Point add(Point a, Point b){ return {a.ff+b.ff, a.ss+b.ss};}
Point sub(Point a, Point b){ return {a.ff-b.ff, a.ss-b.ss};}
double esc(Point a, Point b){
    return a.ff*b.ff + a.ss*b.ss;
}

double cross(Point v1, Point v2){
    return v1.ff*v2.ss-v1.ss*v2.ff;;
}

double norm(Point a){
    return sqrt(esc(a, a));
}

double dist(Point a, Point b){
    return norm(sub(a, b));
}

bool counterclock(Point a, Point b, Point c){
    Point v1 = sub(b, a), v2 = sub(c, b);
    double cross = v1.ff*v2.ss-v1.ss*v2.ff;
    if(cross<0) return true;
    return false;
}

vector <Point> grahamScan(vector<Point> pts){
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

        return (orient < EPS ? orient > 0 : norm(v1) < norm(v2));
    });


    for(auto c: cand){
        while(hull.size() > 1){
            if(counterclock(pts[hull[hull.size()-2]], pts[hull.back()], pts[c])) break;
            cand.pop_back();
        }
        cand.push_back(c);
    }
    

    return {};
}

void solve(int caso){
    int n; cin>>n;
    vector<Point> pts;
    for(int i =0; i<n; i++){
        double a, b;
        cin>>a>>b;
        pts.push_back({a, b});
    }
    vector<Point> res = grahamScan(pts);

    cout<<"Caso "<<caso<<"\n";
    cout<<"Tamanho do colar: "<<res.size();
    cout<<"Pedras ancestrais: ";

    cout<<fixed<<setprecision(4);

    for(int i =0; i<res.size(); i++){
        auto[a, b] = res[i];
        cout<<"("<<a<<","<<b<<")";
        if(i < res.size()-1)cout<<",";
    }
}

int main(){

    int t; cin>>t;

    for(int i =1; i<= t; i++){
        solve(i);
        if(i<t) cout<<"\n";
    }

    return 0;
}