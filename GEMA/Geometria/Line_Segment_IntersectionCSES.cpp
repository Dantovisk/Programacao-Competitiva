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
        
        //fazendo produto vetorial pra ver se retas são colineares
        double r = pvet(vec1, vec2);
        bool resp = false;

        if(r == 0){
            //caso 1: colineares -> basta verificar a ordem
            if(mp(p1.x,p1.y) > mp(p2.x,p2.y)) swap(p1, p2);
            if(mp(p3.x,p3.y) > mp(p4.x,p4.y)) swap(p3, p4);
            
            if(noSeg(p1, p2, p3)|| noSeg(p1, p2, p4) ||
            noSeg(p3, p4, p1)|| noSeg(p3, p4, p2)) resp = true;
        }
        else{
            //caso 2: algum ponto se intersecta
            if(p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4)
                resp = true;
            // caso 3: há apenas uma intersecção p
            // queremos que a e b estejam em lados diferentes da reta cd
            // e que c e d estejam em lados diferentes da reta ab
            else{
                point ac(p1-p3), ad(p1-p4), bc(p2-p3), bd(p2-p4);

                double u = pvet(vec1, p3 - p1);
                double v = pvet(vec1, p4 - p1);
                double w = pvet(vec2, p1 - p3);
                double z = pvet(vec2, p2 - p3);

                if(u*v <= 0 && w*z <= 0) resp = true;
            }
        }
        cout<<(resp?"YES\n":"NO\n");
    }

    return 0;
}