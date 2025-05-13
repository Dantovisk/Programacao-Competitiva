#include <bits/stdc++.h>

using namespace std; 

typedef complex<double> pt;
#define x real()
#define y imag()

int main(){
    double r; cin>>r;

    double x1, x2, y1, y2;
    cin>>x1>>y1;
    cin>>x2>>y2;

    pt p1(x1, y1), p2(x2, y2), center(0.0,0.0);

    double minn = 0.0, maxn = r;


    //Verificando se após encolher os raios em mid, eles ainda possuem área de intersecção
    while(maxn - minn > 0.00000001){
        double mid = (minn + maxn)/2.0;

        double r1 = abs(p1-center) - mid;
        double r2 = abs(p2-center) - mid;
        double d = abs(p2-p1);

        //Os circulos não se tocam, subtraiu demais
        if(d > r1 + r2){
            maxn = mid;
            continue;
        }

        //errei o calculo do pc
        pt p3(0.0, 0.0), p4(0.0, 0.0), pc = p1 + (p2-p1)*(r1/d);

        if(p1 == p2){

        }

        //Um circulo dentro do outro -> 1 intersecção
        if(abs(p1-p2) < max (r1, r2)){

        }
        
        
        //Encontra as duas intersecções dos círculos
        if(p2.x -p1.x == 0){
            //reta vertical
            p3 = (pc.x + (d/2.0), pc.y);
            p4 = (pc.x - (d/2.0), pc.y);
        }
        else{
            double m1 = (p2.y - p1.y) / (p2.x - p1.x);

            double rd = sqrt(r1*r1 - abs(p1-pc)*abs(p1-pc));
            
            if(m1 == 0){
                //reta horizontal
                p3 = (pc.x , pc.y + (d/2.0));
                p4 = (pc.x , pc.y - (d/2.0));
            }
            else{
                double m2 = -1/m1;
                p3 = (pc.x + (rd/sqrt(1 + m2*m2)), pc.y + m2 * rd/(sqrt(1 + m2* m2))); 
                p4 = (pc.x - (rd/sqrt(1 + m2*m2)), pc.y - m2 * rd/(sqrt(1 + m2* m2))); 
            }
        }
        
        //verifica se p3 ou p4 estão dentro do raio a partir da origem
        if(abs(center - p3) < r - mid || abs(center - p4) < r - mid){
            minn= mid;
        }
        else maxn = mid;
    }

    cout<<maxn<<"\n";

    return 0;
}