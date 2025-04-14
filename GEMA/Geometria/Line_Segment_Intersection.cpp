#include <bits/stdc++.h> //CSES - Line Segment Intersection
using namespace std;    // Resolvendo pelo método do USACO
#define int long long

//template do USACO
struct Ponto{
    int x, y;
    Ponto(int a = 0, int b = 0) : x(a), y(b){}

    friend istream &operator>>(istream &in, Ponto &p) {
		in >> p.x >> p.y;
		return in;
	}
};

//faz o produto vetorial entre AB e AP
int cross(Ponto a, Ponto b, Ponto p){
    int res = (b.x - a.x)*(p.y-a.y) - (b.y-a.y)*(p.x-a.x);
    if (res == 0) return 0;
    return (res>0? 1: -1);
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        Ponto a, b, c, d;

        cin>>a>>b>>c>>d;
        
        int x1, x2, x3, x4, y1, y2, y3, y4;
        x1 = min(a.x, b.x), x2 = max(a.x, b.x);
        x3 = min(c.x, d.x), x4 = max(c.x, d.x);
        y1 = min(a.y, b.y), y2 = max(a.y, b.y);
        y3 = min(c.y, d.y), y4 = max(c.y, d.y);
        
        //os quadrados com diagonais AB e CD não se intersectam
        if(x3 > x2 || x4 < x1 || y3 > y2 || y4 < y1 ){
            cout<<"NO\n";
        }
        else{
            //veremos se A e B estão em lados diferentes de CD, e vice versa
            if(cross(a, b, c) * cross(a, b, d) <= 0 &&
            cross(c, d, a) * cross(c, d, b) <= 0 ){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

    }

    return 0;
}