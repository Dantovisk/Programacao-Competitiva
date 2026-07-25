#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int sign(ll a){
    if(a == 0) return 0;
    return a/abs(a);
}

//representa nossos pontos (extremidade do segmento)
struct pt{
    ll x, y;
    //construtor
    pt(ll xx, ll yy){
        x = xx;
        y = yy;
    }

    pt operator-(pt &b){
        return pt(x-b.x, y -b.y);
    }
    // produto vetorial com o vetor b
    ll cross(pt b){ 
        return (x*b.y - y*b.x);
    }
    // produto escalar com o vetor b
    ll dot(pt b){ 
        return (x*b.x + y*b.y);
    }

    // realiza o produto vetorial entre os vetores
    // que começam no meu ponto, e vão para A e B
    ll cross2(pt a, pt b){
        return (a - *this).cross(b - *this);
    }
};

// Verifica se o ponto P está contido segmento SE
bool onSegment(pt s, pt e, pt p){
    if(p.cross2(s, e) != 0) return false; // P está fora da reta de SE

    // S e E devem estar em direções opostas em relção a P
    if((s - p).dot(e - p) > 0) return false; // P está fora do segmento
    return true;
}

//verifica interseção entre os segmentos a<->b e c<->d
bool intersect(pt a, pt b, pt c, pt d){
    // para um segmento AB intersectar com CD
    // C deve estar em um lado diferente do de D
    // em relação à reta AB
    // O mesmo vale para o inverso
    int lado1 = sign(a.cross2(b, c)) * sign(a.cross2(b, d));
    int lado2 = sign(c.cross2(d, a)) * sign(c.cross2(d, b));
    if(lado1 > 0 or lado2 > 0) return false;

    // Caso de borda: os 2 segmentos pertencem à mesma reta
    // Se não está no segmento retorna falso;
    if(lado1 == 0 and lado2==0){
        if(!(onSegment(a, b, c) or onSegment(a, b, d))) return false;
    }

    return true;
}


int main() {
    cin.tie(0)->sync_with_stdio(0); // para facilitar a visualização

    vector<pt> points;

    for(int i =0; i<4; i++){
        ll a, b;
        cin>>a>>b;
        points.emplace_back(a, b);
    }

    //verifica se os segmentos intersectam
    if(intersect(points[0],points[1], points[2], points[3])){
        cout<<"SIM\n";
    }else{
        cout<<"NAO\n";
    }
}
