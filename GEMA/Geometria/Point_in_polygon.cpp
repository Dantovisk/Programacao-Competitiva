#include <bits/stdc++.h> //CSES - Point in Polygon Area
using namespace std;
#define int long long

typedef complex<int> pt;
#define x real()
#define y imag()
#define mp make_pair

auto cross = [](pt a, pt b) {
    return (conj(a) * b).y;
};

//vê se o ponto p tá no segmento de reta entre p1 e p2
bool noSeg(pt p, pt p1, pt p2){
    //vê se p está dentro da reta que tem os pontos p1 e p2
    int r = cross(p1-p, p2-p);
    if(r != 0) return false;

    //verifica se ta dentro do segmento
    int a = min(p1.x, p2.x);
    int b = max(p1.x, p2.x);
    int c = min(p1.y, p2.y);
    int d = max(p1.y, p2.y);
    return (a<= p.x && b>= p.x && c<= p.y && d>= p.y);
}

int32_t main(){
    int n, m; cin>>n>>m;
    //lendo o poligono
    vector<pt> v(n+1);
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        v[i] = pt(a, b);
    }
    v[n] = v[0];

    for(int i=0; i<m; i++){
        int c, d; cin>>c>>d;
        pt p(c,d);
        bool seg = false;
        int cruz = 0;

        for(int i=0; i<n; i++){
            pt a = v[i], b = v[i+1];
            if(noSeg(p, a, b)){
                cout<<"BOUNDARY\n";
                seg = true;
                break;
            }

            //se a reta horizontal está entre A e B, e P
            //está à esquerda da reta AB, é cruzamento
            if (a.y <= p.y && p.y < b.y && cross(b - a, p - a) > 0) cruz++;
            if (b.y <= p.y && p.y < a.y && cross(a - b, p - b) > 0) cruz++;
        }
        if(seg) continue;
        if(cruz%2) cout<<"INSIDE\n";
        else cout<<"OUTSIDE\n";
    }

    return 0;
}