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
        
        //Encontra as duas intersecções dos círculos

    }

    return 0;
}