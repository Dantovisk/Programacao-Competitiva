#include <bits/stdc++.h> //CSES - Point location test
using namespace std;

typedef complex<double> point;
#define x real()
#define y imag()

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d, e, f;
        cin>>a>>b>>c>>d>>e>>f;
        point p1(a,b), p2(c,d), p3(e,f);

        //definindo os vetores v1 e v2
        point vec1 = p2-p1, vec2 = p3 - p1;
        
        //produto vetorial
        long long res = (conj(vec1) * vec2).y;

        if(res<0) cout<<"RIGHT\n";
        else if(res==0) cout<<"TOUCH\n";
        else cout<<"LEFT\n";
    }

    return 0;
}