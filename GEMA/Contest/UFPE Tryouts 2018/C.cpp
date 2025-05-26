#include <bits/stdc++.h> //WA no 115, estou ficando maluco

using namespace std; 

typedef complex<double> pt;
#define x real()
#define y imag()
const double pi = acos(-1);

int main(){
    double ax, ay, bx, by, d;
    cin>>ax>>ay>>bx>>by>>d;
    
    pt a(ax, ay), b(bx, by);
    double r = abs(a-b);

    bool resp = false;

    double minn = 0, maxx = pi;
    
    while(maxx - minn > 0.0000000000000005){
        double alfa = (minn + maxx)/2;
        double beta = (pi- alfa)/2;
        
        double expD = (r * sin(alfa)) / sin(beta);

        if(abs(expD-d) < 0.0000000001){
            resp = true;
        }
        if(expD < d){
            minn = alfa;
        } else maxx = alfa;
    }

    double alfa = maxx;
    double start = atan2(a.y-b.y, a.x-b.x);

    pt off1 = polar(r, start + alfa);
    pt off2 = polar(r, start - alfa);
    
    cout<<fixed<<setprecision(8);
    pt c1 = b +off1, c2 = b + off2;


    if(!resp){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<< c1.x <<" "<<c1.y<<" "<<c2.x<<" "<<c2.y<<"\n";
    
    return 0;
}