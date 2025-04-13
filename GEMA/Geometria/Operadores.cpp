#include <bits/stdc++.h> //CSES - Point location test
using namespace std;

typedef complex<double> pt;
#define x real()
#define y imag()

string pp(pt c){
    ostringstream oss;
    oss << "(" << c.x << ", " << c.y << ")";
    return oss.str();
}

int main(){
    pt a (2, 0), b(0, 0);


    pt c = a + b;
    cout<<pp(a)<<" + "<<pp(b)<<" = "<<pp(c)<<"\n";
    
    //produto escalar
    c = (conj(a) * b). x;
    cout<<pp(a)<<" * "<<pp(b)<<" = "<<c.x<<"\n";

    //produto vetorial
    c = (conj(a) * b). y;
    cout<<pp(a)<<" x "<<pp(b)<<" = "<<pp(c)<<"\n";

    //modulo
    cout<<"|"<<pp(a)<<"| = "<<abs(a - b)<<"\n";

    //distancia
    cout<<"Distancia entre "<<pp(a)<<" e "<<pp(b)<<" = "<<abs(a - b)<<"\n";

    //arg(vec) = angulo do vetor (em radianos, observe que é pi para 180°)
    pt vec(-1, 0);
    cout<<"angulo de "<<pp(vec)<<" = "<<arg(vec)<<"\n";

    //arccos(1) = pi
    cout<<"pi = "<<acos(-1)<<"\n";

    // polar(r, ang) polar cria um vetor em coordenadas polares
    pt v = polar(1.0, acos(-1));
    cout<<"polar (1, pi) = "<<pp(v)<<" ~= (-1, 0)\n";
}