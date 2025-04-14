#include <bits/stdc++.h> //CSES - Polygon Area
using namespace std;
#define int long long

//template do USACO
struct pt{
    int x, y;
    pt(int a = 0, int b = 0) : x(a), y(b){}

    friend istream &operator>>(istream &in, pt &p) {
		in >> p.x >> p.y;
		return in;
	}
};

int cross(pt a, pt b){
    return (a.x*b.y - a.y*b.x);
}

int32_t main(){
    int n; cin>>n;
    int res = 0;

    pt ant, ini;
    cin>>ini;
    ant = ini;
    for(int i = 1; i<n; i++){
        pt curr;
        cin>>curr;
        res+= cross(ant, curr);
        ant = curr;
    }
    res+= cross(ant, ini);
    cout<<abs(res)<<"\n";

    return 0;
}