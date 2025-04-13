#include <bits/stdc++.h> //CSES - Line Segment Intersection - IMPLEMENTEI ERRADO
using namespace std;    // Resolvendo pelo método do livro do CSES (achei meio paia)

typedef complex<double> point;
#define x real()
#define y imag()
#define mp make_pair

auto pvet = [](point a, point b) {
    return (conj(a) * b).y;
};

//vê se o ponto p3 tá no segmento de reta entre p1 e p2
bool noSeg(point p1, point p2, point p3){
    return min(p1.x, p2.x) <= p3.x && max(p1.x,p2.x) >= p3.x &&
    min(p1.y, p2.y) <= p3.y && max(p1.y,p2.y) >= p3.y;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d, e, f, g, h;
        cin>>a>>b>>c>>d>>e>>f>>g>>h;
        point p1(a,b), p2(c,d), p3(e,f), p4(g,h);

        //definindo os vetores v1 e v2
        point vec1 = p2-p1, vec2 = p4 - p3;
        
        bool resp = false;

        
        cout<<(resp?"YES\n":"NO\n");
    }

    return 0;
}