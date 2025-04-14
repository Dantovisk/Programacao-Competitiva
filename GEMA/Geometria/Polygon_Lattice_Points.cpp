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

int32_t main(){
    int n; cin>>n;
    vector<pt> vec(n+1);
    
    for(int i =0; i<n; i++){
        int c, d; cin>>c>>d;
        vec[i] = pt(c,d);
    }
    vec[n] = vec[0]; 

    int area = 0;
    for(int i =0; i<n; i++){
        area += cross(vec[i], vec[i+1]);
    }
    area = abs(area);

    int cont = 0;
    //calculando o numero de pontos na borda
    for(int i =0; i<n; i++){
        pt a = vec[i+1] - vec[i];
        cont += gcd(abs(a.x), abs(a.y));
    }
    cout<<(long long)(area - cont)/2 + 1<<" "<<cont<<"\n";

    return 0;
}